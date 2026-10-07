#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}n;

n* head = NULL;
n* crnod (int val){n* nn = (n*)malloc(sizeof(n)); nn->data=val; nn->next=NULL; }

void insbeg(int val) {
  n* nn=crnod(val);
  nn->next = head;
  head = nn;
  printf("Inserted %d at the beginning.", val);
}

void append(int val) {
  n* nn=crnod(val);
  nn->next = NULL;
  if (head == NULL) { head = nn;
    printf("Inserted %d as the first element.", val);
    return;}
  n* temp = head;
  while (temp->next != NULL) {temp = temp->next;}
  temp->next = nn;
  printf("Inserted %d at the end.", val);
}

void insatpos(int val, int pos) {
  n* nn=crnod(val);
  struct Node* temp = head;
  while(temp!= NULL) {
    temp=temp->next;
    if(temp->data == pos){
      nn->next=temp->next;
      temp->next= nn;
      printf("Inserted %d after %d.", val, pos);}
    return;
  }
  printf("Value not found in list"); return;
}

void delNode(int val) {
    if (head == NULL) {
        printf("List is empty."); return; }
    n *temp = head, *prev = NULL;
    if (temp != NULL && temp->data == val) {
        head = temp->next;
        free(temp);
        printf("Deleted %d from the list.", val);
        return;
    }
    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found in the list.", val); return; }
    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.", val);
}

void display() {
    if (head == NULL) {
       printf("List is empty.");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main() {
  int choice, val, pos;
  while (1) {
    printf("\n--- Linked List Operations Menu ---\n1. Insert at Beginning\n2. Insert at End\n3. Insert In Between (at Position)\n4. Delete a Node\n5. Display\n6. Exit\nEnter your choice: ");
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
        if (scanf("%d", &val) == 1) { display();
          printf("\nEnter preceding record :");
          if (scanf("%d", &pos) == 1) { insatpos(val, pos); }
        }break;
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
    }}
    return 0;
}
