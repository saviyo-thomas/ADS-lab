#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
} n;

n* head = NULL;

n* crnod(int val) {
  n* nn = (n*)malloc(sizeof(n));
  nn->data = val;
  nn->next = nn;
  nn->prev = nn;
  return nn;
}

void insbeg(int val) {
  n* nn = crnod(val);
  if (head == NULL) {
    head = nn;
  } else {
    n* tail = head->prev;
    nn->next = head;
    nn->prev = tail;
    head->prev = nn;
    tail->next = nn;
    head = nn;
  }
  printf("Inserted %d at the beginning.", val);
}

void append(int val) {
  n* nn = crnod(val);
  if (head == NULL) {
    head = nn;
  } else {
    n* tail = head->prev;
    tail->next = nn;
    nn->prev = tail;
    nn->next = head;
    head->prev = nn;
  }
  printf("Inserted %d at the end.", val);
}

void insatpos(int val, int pos) {
  if (head == NULL) {
    printf("List is empty.");
    return;
  }
  n* temp = head;
  do {
    if (temp->data == pos) {
      n* nn = crnod(val);
      nn->next = temp->next;
      nn->prev = temp;
      temp->next->prev = nn;
      temp->next = nn;
      printf("Inserted %d after %d.", val, pos);
      return;
    }
    temp = temp->next;
  } while (temp != head);
  
  printf("Value %d not found in list.", pos);
}

void delNode(int val) {
  if (head == NULL) {
    printf("List is empty.");
    return;
  }
  n* temp = head;
  do {
    if (temp->data == val) {
      if (temp->next == temp) { // Only one node
        head = NULL;
      } else {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        if (temp == head) {
          head = temp->next;
        }
      }
      free(temp);
      printf("Deleted %d from the list.", val);
      return;
    }
    temp = temp->next;
  } while (temp != head);
  
  printf("Element %d not found in the list.", val);
}

void display() {
  if (head == NULL) {
    printf("List is empty.");
    return;
  }
  n* temp = head;
  printf("Circular Linked List: ");
  do {
    printf("%d -> ", temp->data);
    temp = temp->next;
  } while (temp != head);
  printf("(head)");
}

int main() {
  int choice, val, pos;
  while (1) {
    printf("\n--- Circular Linked List Operations Menu ---\n1. Insert at Beginning\n2. Insert at End\n3. Insert In Between (at Position)\n4. Delete a Node\n5. Display\n6. Exit\nEnter your choice: ");
    if (scanf("%d", &choice) != 1) return 0;
    switch (choice) {
      case 1:
        printf("Enter value to insert at beginning: ");
        if (scanf("%d", &val) == 1) insbeg(val);
        break;
      case 2:
        printf("Enter value to insert at end: ");
        if (scanf("%d", &val) == 1) append(val);
        break;
      case 3:
        printf("Enter value to insert: ");
        if (scanf("%d", &val) == 1) {
          display();
          printf("Enter preceding record: ");
          if (scanf("%d", &pos) == 1) { insatpos(val, pos); }
        }
        break;
      case 4:
        printf("Enter value to delete: ");
        if (scanf("%d", &val) == 1) delNode(val);
        break;
      case 5:
        display();
        break;
      case 6:
        exit(0);
      default:
        printf("Invalid choice. Please try again.");
  } }
  return 0;
}
