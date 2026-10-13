/*
===================================================================
NAME: Saviyo Thomas
ROLL NO: CS11
DATE: 31/07/2026
EXPERIMENT NO: 11

ALGORITHM: Quick Sort Implementation
1. Define PARTITION function (using array, low, and high indices):
 a. Choose a pivot element (e.g., array[high]).
 b. Maintain an index 'i' initialized to low - 1.
 c. Loop 'j' from low to high - 1:
  - If array[j] < pivot, increment 'i' and swap array[i] with array[j].
 d. Swap array[i + 1] with array[high] (pivot position).
 e. Return partition index (i + 1).
2. Define QUICKSORT function (array, low, high):
 a. If low < high:
  - Partition the array to find pivot index 'pi'.
  - Recursively call QUICKSORT on left sub-array (low to pi - 1).
  - Recursively call QUICKSORT on right sub-array (pi + 1 to high).
3. In main(), read input array, call QUICKSORT, and print sorted array.
===================================================================
SOURCE CODE: Quick Sort Implementation
*/

#include <stdio.h>
#define size 10


void swap(int* a, int* b) {
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(int arr[], int low, int high) {

  int pivot = arr[high];

  int i = low - 1;

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[high]);  
  return i + 1;
}


void qsort(int arr[], int low, int high) {
  if (low < high) {

    int pi = partition(arr, low, high);

    qsort(arr, low, pi - 1);
    qsort(arr, pi + 1, high);
  }}

int main() {
  int arr[size];
  printf("\nEnter 10  elements to sort separated by space:");
  for(int i=0;i<size;i++){ 
    scanf("%d",&arr[i]);
  }
  int n = sizeof(arr) / sizeof(arr[0]);

  qsort(arr, 0, n - 1);
  printf("\n Sorted array :");
  for (int i = 0; i < n; i++) { printf("%d ", arr[i]); }
  printf("\n");
  return 0;
}

/*
   ===================================================================

   OUTPUT

   CS2024PG01@csserver:~/pg2026/ads/ADS-lab/record$ ./a.out

   Enter 10  elements to sort separated by space:64 34 25 12 22 11 90 5 77 30

    Sorted array :5 11 12 22 25 30 34 64 77 90
*/
