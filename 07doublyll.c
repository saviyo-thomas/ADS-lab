#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
}n;

n* head = NULL;

n* crnod (int val){
  n* nn = (n*)malloc(sizeof(n));
  nn->data=val;
  nn->next=NULL;
  nn->prev=NULL;
  return nn;
}

void insbeg(int val) {
  n* nn=crnod(val);
  nn->next = head;
  if (head != NULL) {
    head->prev = nn;
  }
  head = nn;
  printf("Inserted %d at the beginning.
", val);
}

void append(int val) {
  n* nn=crnod(val);
  if (head == NULL) {
    head = nn;
    printf("Inserted %d as the first element.
", val);
    return;
  }
  n* temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = nn;
  nn->prev = temp;
  printf("Inserted %d at the end.
", val);
}

void insatpos(int val, int pos) {
  n* nn=crnod(val);
  n* temp = head;
  while(temp != NULL) {
    if(temp->data == pos){
      nn->next = temp->next;
      if (temp->next != NULL) {
        temp->next->prev = nn;
      }
      temp->next = nn;
      nn->prev = temp;
      printf("Inserted %d after %d.
", val, pos);
      return;
    }
    temp=temp->next;
  }
  printf("Value %d not found in list.
", pos);
  free(nn);
}

void delNode(int val) {
    if (head == NULL) {
        printf("List is empty.
");
        return;
    }
    n *temp = head;
    while (temp != NULL && temp->data != val) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found in the list.
", val);
        return;
    }
    if (temp == head) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    } else {
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;
        }
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
    }
    free(temp);
    printf("Deleted %d from the list.
", val);
}

void display() {
    if (head == NULL) {
        printf("List is empty.
");
        return;
    }
    n* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL
");
}

int main() {
  int choice, val, pos;
  while (1) {
    printf("
--- Linked List Operations Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert In Between (at Position)
4. Delete a Node
5. Display
6. Exit
Enter your choice: ");
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
          printf("
Enter preceding record: ");
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
        printf("Invalid choice. Please try again.
");
    }
  }
  return 0;
}
