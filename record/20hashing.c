/*
===================================================================
NAME: Saviyo Thomas
ROLL NO: CS11
DATE: 26/09/2026
EXPERIMENT NO: 20

ALGORITHM: Hash Table with Separate Chaining
1. Define TABLE_SIZE (10) and a Node structure with integer 'data' and 'next' pointer.
2. Initialize hashTable[0..TABLE_SIZE-1] to NULL.
3. Define Hash Function: h(key) = key % TABLE_SIZE.
4. Implement INSERT operation:
 a. Calculate index = h(key).
 b. Create new node with key.
 c. If hashTable[index] is NULL, make it the head.
 d. Else (collision), traverse to end of chain and append new node.
5. Implement DISPLAY operation to print each index chain ending with NULL.
6. Provide driver program in main() to insert, display and exit.
===================================================================
SOURCE CODE: Implementation of hashing using separate chaining 
*/
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node {
  int data;
  struct Node* next;
}n;

n* hashTable[TABLE_SIZE];

void initHash() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    hashTable[i] = NULL;
  }
}

int hashKey(long int key) {
  return key % 10;
}

void insertHash(long int key) {
  int index = hashKey(key);
  n* nn = (n*)malloc(sizeof(n));
  nn->data = key;
  nn->next = NULL;

  if (hashTable[index] == NULL) { hashTable[index] = nn;}
  else {
    n* temp = hashTable[index];
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = nn;
  }
  printf("Inserted %ld at index %d\n", key, index);
}

void displayHash() {
  for (int i = 0; i < TABLE_SIZE; i++) {
    printf("Index %d: ", i);
    struct Node* temp = hashTable[i];
    while (temp != NULL) {
      printf("%d -> ", temp->data);
      temp = temp->next;
    }
    printf("NULL\n");
  }
}

int main() {
  initHash();
  int choice;
  long int val;

  while (1) {
    printf("\n1. Insert\n2. Display\n3. Exit\nEnter choice: ");
    if (scanf("%d", &choice) != 1) break;

    switch (choice) {
      case 1:
        printf("Enter value to insert: ");
        scanf("%ld", &val);
        insertHash(val);
        break;
      case 2:
        displayHash();
        break;
      case 3:
        return 0;
      default:
        printf("Invalid choice!\n");
    }
  }
  return 0;
}

/*
   ===================================================================

   OUTPUT

   CS2024PG01@csserver:~/pg2026/ads/ADS-lab/record$ ./a.out

   1. Insert
   2. Display
   3. Exit
   Enter choice: 1
   Enter value to insert: 15
   Inserted 15 at index 5

   1. Insert
   2. Display
   3. Exit
   Enter choice: 1
   Enter value to insert: 25
   Inserted 25 at index 5

   1. Insert
   2. Display
   3. Exit
   Enter choice: 1
   Enter value to insert: 35
   Inserted 35 at index 5

   1. Insert
   2. Display
   3. Exit
   Enter choice: 1
   Enter value to insert: 12
   Inserted 12 at index 2

   1. Insert
   2. Display
   3. Exit
   Enter choice: 1
   Enter value to insert: 22
   Inserted 22 at index 2

   1. Insert
   2. Display
   3. Exit
   Enter choice: 2
   Index 0: NULL
   Index 1: NULL
   Index 2: 12 -> 22 -> NULL
   Index 3: NULL
   Index 4: NULL
   Index 5: 15 -> 25 -> 35 -> NULL
   Index 6: NULL
   Index 7: NULL
   Index 8: NULL
   Index 9: NULL

   1. Insert
   2. Display
   3. Exit
   Enter choice: 3
*/
