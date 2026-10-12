/* 15. Implementation of heap tree and operations */
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