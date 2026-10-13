/*
===================================================================
NAME: Saviyo Thomas
ROLL NO: CS11
DATE: 04/09/2026
EXPERIMENT NO: 15

ALGORITHM: Binary Heap Operations (Insert / Extract Max or Min)
1. Define max size and initialize heap array with 'size' = 0.
2. Implement INSERT operation:
 a. Add element at the end of the heap array.
 b. Increment size.
 c. Up-heapify (bubble up): Compare the added element with its parent. If it violates heap property, swap them and repeat for parent until root is reached.
3. Implement EXTRACT root (Max/Min) operation:
 a. Replace root element with the last element of the heap array.
 b. Decrement size.
 c. Down-heapify (bubble down/heapify) from root to restore heap property.
4. Provide a menu-driven interface to insert, extract, and display the heap.
===================================================================
SOURCE CODE: Implementation of heap tree and operations
*/
#include <stdio.h>

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void maxHeapify(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    maxHeapify(arr, n, largest);
  }
}

void insert(int arr[], int* n, int key) {
  (*n)++;
  int i = *n - 1;
  arr[i] = key;

  while (i != 0 && arr[(i - 1) / 2] < arr[i]) {
    swap(&arr[i], &arr[(i - 1) / 2]);
    i = (i - 1) / 2;
  }
}

void deleteRoot(int arr[], int* n) {
  if (*n <= 0) {
    printf("Heap underflow!\n");
    return;
  }
  arr[0] = arr[*n - 1];
  (*n)--;
  maxHeapify(arr, *n, 0);
}

void display(int arr[], int n) {
  printf("Heap elements: ");
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int main() {
  int arr[100], n = 0, choice, val;

  while (1) {
    printf("\n1. Insert\n2. Delete Root\n3. Display\n4. Exit\nEnter choice: ");
    if (scanf("%d", &choice) != 1) break;

    switch (choice) {
      case 1:
        printf("Enter value to insert: ");
        scanf("%d", &val);
        insert(arr, &n, val);
        break;
      case 2:
        deleteRoot(arr, &n);
        break;
      case 3:
        display(arr, n);
        break;
      case 4:
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
   2. Delete Root
   3. Display
   4. Exit
   Enter choice: 2
   Heap underflow!

   1. Insert
   2. Delete Root
   3. Display
   4. Exit
   Enter choice: 1
   Enter value to insert: 40

   1. Insert
   2. Delete Root
   3. Display
   4. Exit
   Enter choice: 1
   Enter value to insert: 20

   1. Insert
   2. Delete Root
   3. Display
   4. Exit
   Enter choice: 1
   Enter value to insert: 60

   1. Insert
   2. Delete Root
   3. Display
   4. Exit
   Enter choice: 1
   Enter value to insert: 10

   1. Insert
   2. Delete Root
   3. Display
   4. Exit
   Enter choice: 1
   Enter value to insert: 30

   1. Insert
   2. Delete Root
   3. Display
   4. Exit
   Enter choice: 3
   Heap elements: 60 30 40 10 20

   1. Insert
   2. Delete Root
   3. Display
   4. Exit
   Enter choice: 2

   1. Insert
   2. Delete Root
   3. Display
   4. Exit
   Enter choice: 3
   Heap elements: 40 30 20 10

   1. Insert
   2. Delete Root
   3. Display
   4. Exit
   Enter choice: 2

   1. Insert
   2. Delete Root
   3. Display
   4. Exit
   Enter choice: 3
   Heap elements: 30 10 20

   1. Insert
   2. Delete Root
   3. Display
   4. Exit
   Enter choice: 4
*/
