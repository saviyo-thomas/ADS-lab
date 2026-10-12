/*
ALGORITHM: Heap Sort Implementation
1. Define HEAPIFY function to maintain max-heap property for subtree rooted at index 'i' in array of size 'n':
   a. Set 'largest' as 'i', left child 'l' = 2*i + 1, right child 'r' = 2*i + 2.
   b. If 'l' < n and array[l] > array[largest], set 'largest' to 'l'.
   c. If 'r' < n and array[r] > array[largest], set 'largest' to 'r'.
   d. If 'largest' is not equal to 'i', swap array[i] with array[largest] and recursively heapify the affected subtree.
2. Define HEAPSORT function:
   a. Build max heap: Loop from n/2 - 1 down to 0, calling HEAPIFY.
   b. Sort phase: Loop from n-1 down to 1:
      - Swap array[0] (root/largest element) with array[i].
      - Call HEAPIFY on root with reduced heap size 'i'.
3. In main(), read input array, sort it, and print sorted results.
*/

#include <stdio.h>
#include <stdlib.h>

// To heapify a subtree rooted with node i
void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(int arr[], int n) {
    // Build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        // Move current root to end
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        // Call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid size entered.\n");
        return 1;
    }

    // Dynamically allocate memory based on user input size
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    heapSort(arr, n);

    printf("\nSorted array:\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free allocated memory to prevent memory leaks
    free(arr);

    return 0;
}