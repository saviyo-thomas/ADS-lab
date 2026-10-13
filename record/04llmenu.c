/*
===================================================================
NAME: Saviyo Thomas
ROLL NO: CS11
DATE: 13/07/2026
EXPERIMENT NO: 04

ALGORITHM: Singly Linked List Operations (Menu-driven)
1. Define a Node structure containing 'data' and a pointer 'next' to the next node.
2. Initialize 'head' pointer to NULL.
3. Implement INSERT operations:
 a. At the beginning: Create new node, set its next to head, update head to new node.
 b. At the end: Create new node, traverse to the last node, set its next to new node.
 c. After a given value: Traverse to node with data == pos, insert new node after it.
4. Implement DELETE operation by value:
 a. If list is empty, print List is empty.
 b. If head holds val, update head to head->next and free old head.
 c. Otherwise traverse to node with data == val, bypass it via prev->next and free it. If not found, print not found.
5. Implement DISPLAY operation to traverse the list from 'head' to NULL, printing each node's data.
6. Provide a menu-driven loop in main() to insert, delete, display and exit.
===================================================================
SOURCE CODE: Singly Linked List Operations (Menu-driven)
*/

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

/*
   ===================================================================

   OUTPUT

   CS2024PG01@csserver:~/pg2026/ads/ADS-lab/record$ ./a.out

   --- Linked List Operations Menu ---
   1. Insert at Beginning
   2. Insert at End
   3. Insert In Between (at Position)
   4. Delete a Node
   5. Display
   6. Exit
   Enter your choice: 5
   List is empty.
   --- Linked List Operations Menu ---
   1. Insert at Beginning
   2. Insert at End
   3. Insert In Between (at Position)
   4. Delete a Node
   5. Display
   6. Exit
   Enter your choice: 1
   Enter value to insert at beginning: 10
   Inserted 10 at the beginning.
   --- Linked List Operations Menu ---
   1. Insert at Beginning
   2. Insert at End
   3. Insert In Between (at Position)
   4. Delete a Node
   5. Display
   6. Exit
   Enter your choice: 2
   Enter value to insert at end: 20
   Inserted 20 at the end.
   --- Linked List Operations Menu ---
   1. Insert at Beginning
   2. Insert at End
   3. Insert In Between (at Position)
   4. Delete a Node
   5. Display
   6. Exit
   Enter your choice: 2
   Enter value to insert at end: 30
   Inserted 30 at the end.
   --- Linked List Operations Menu ---
   1. Insert at Beginning
   2. Insert at End
   3. Insert In Between (at Position)
   4. Delete a Node
   5. Display
   6. Exit
   Enter your choice: 5
   Linked List:
   Linked List: 10 -> 20 -> 30 -> NULL
   --- Linked List Operations Menu ---
   1. Insert at Beginning
   2. Insert at End
   3. Insert In Between (at Position)
   4. Delete a Node
   5. Display
   6. Exit
   Enter your choice: 3
   Enter value to insert: 25
   Linked List:
   Linked List: 10 -> 20 -> 30 -> NULL
   Enter preceding record :20
   Inserted 25 after 20.
   --- Linked List Operations Menu ---
   1. Insert at Beginning
   2. Insert at End
   3. Insert In Between (at Position)
   4. Delete a Node
   5. Display
   6. Exit
   Enter your choice: 5
   Linked List:
   Linked List: 10 -> 20 -> 25 -> 30 -> NULL
   --- Linked List Operations Menu ---
   1. Insert at Beginning
   2. Insert at End
   3. Insert In Between (at Position)
   4. Delete a Node
   5. Display
   6. Exit
   Enter your choice: 4
   Enter value to delete: 10
   Deleted 10 from the list.
   --- Linked List Operations Menu ---
   1. Insert at Beginning
   2. Insert at End
   3. Insert In Between (at Position)
   4. Delete a Node
   5. Display
   6. Exit
   Enter your choice: 5
   Linked List:
   Linked List: 20 -> 25 -> 30 -> NULL
   --- Linked List Operations Menu ---
   1. Insert at Beginning
   2. Insert at End
   3. Insert In Between (at Position)
   4. Delete a Node
   5. Display
   6. Exit
   Enter your choice: 4
   Enter value to delete: 99
   Element 99 not found in the list.
   --- Linked List Operations Menu ---
   1. Insert at Beginning
   2. Insert at End
   3. Insert In Between (at Position)
   4. Delete a Node
   5. Display
   6. Exit
   Enter your choice: 5
   Linked List:
   Linked List: 20 -> 25 -> 30 -> NULL
   --- Linked List Operations Menu ---
   1. Insert at Beginning
   2. Insert at End
   3. Insert In Between (at Position)
   4. Delete a Node
   5. Display
   6. Exit
   Enter your choice: 6
*/
