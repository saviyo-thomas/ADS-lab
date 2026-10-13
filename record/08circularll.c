/*
   ===================================================================
NAME: Saviyo Thomas
ROLL NO: CS11
DATE: 19/07/2026
EXPERIMENT NO: 08

ALGORITHM: Circular Doubly Linked List Operations
1. Define a Node structure containing 'data', 'next' and 'prev' pointers.
2. Initialize 'head' pointer to NULL.
3. Maintain circular property where head->prev is tail and tail->next is head; single node points to itself.
4. Implement INSERT operation:
 a. At beginning: Create node, link it before head and update head to new node.
 b. At end: Create node, link it after tail (head->prev).
 c. After value pos: Traverse circularly to node with data == pos and splice new node after it.
5. Implement DELETE operation by value:
 a. If list is empty, return.
 b. If single node matches, free it and set 'head' to NULL.
 c. Otherwise, bypass node via prev->next and next->prev, update head if needed, and free memory.
6. Implement DISPLAY operation by traversing starting from 'head' and stopping when we loop back to 'head'.
===================================================================
 */

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

/*
   ===================================================================

   OUTPUT

   CS2024PG01@csserver:~/pg2026/ads/ADS-lab/record$ ./a.out

   --- Circular Linked List Operations Menu ---
   1. Insert at Beginning
   2. Insert at End
   3. Insert In Between (at Position)
   4. Delete a Node
   5. Display
   6. Exit
   Enter your choice: 5
   List is empty.
   --- Circular Linked List Operations Menu ---
   1. Insert at Beginning
   2. Insert at End
   3. Insert In Between (at Position)
   4. Delete a Node
   5. Display
   6. Exit
   Enter your choice: 1
   Enter value to insert at beginning: 10
   Inserted 10 at the beginning.
   --- Circular Linked List Operations Menu ---
   1. Insert at Beginning
   2. Insert at End
   3. Insert In Between (at Position)
   4. Delete a Node
   5. Display
   6. Exit
   Enter your choice: 2
   Enter value to insert at end: 20
   Inserted 20 at the end.
   --- Circular Linked List Operations Menu ---
   1. Insert at Beginning
   2. Insert at End
   3. Insert In Between (at Position)
   4. Delete a Node
   5. Display
   6. Exit
   Enter your choice: 2
   Enter value to insert at end: 30
   Inserted 30 at the end.
   --- Circular Linked List Operations Menu ---
   1. Insert at Beginning
   2. Insert at End
   3. Insert In Between (at Position)
   4. Delete a Node
   5. Display
   6. Exit
   Enter your choice: 5
   Circular Linked List: 10 -> 20 -> 30 -> (head)
   --- Circular Linked List Operations Menu ---
   1. Insert at Beginning
   2. Insert at End
   3. Insert In Between (at Position)
   4. Delete a Node
   5. Display
   6. Exit
   Enter your choice: 3
   Enter value to insert: 25
   Circular Linked List: 10 -> 20 -> 30 -> (head)Enter preceding record: 20
   Inserted 25 after 20.
   --- Circular Linked List Operations Menu ---
   1. Insert at Beginning
   2. Insert at End
   3. Insert In Between (at Position)
   4. Delete a Node
   5. Display
   6. Exit
   Enter your choice: 5
   Circular Linked List: 10 -> 20 -> 25 -> 30 -> (head)
   --- Circular Linked List Operations Menu ---
   1. Insert at Beginning
   2. Insert at End
   3. Insert In Between (at Position)
   4. Delete a Node
   5. Display
   6. Exit
   Enter your choice: 4
   Enter value to delete: 10
   Deleted 10 from the list.
   --- Circular Linked List Operations Menu ---
   1. Insert at Beginning
   2. Insert at End
   3. Insert In Between (at Position)
   4. Delete a Node
   5. Display
   6. Exit
   Enter your choice: 5
   Circular Linked List: 20 -> 25 -> 30 -> (head)
   --- Circular Linked List Operations Menu ---
   1. Insert at Beginning
   2. Insert at End
   3. Insert In Between (at Position)
   4. Delete a Node
   5. Display
   6. Exit
   Enter your choice: 6
*/
