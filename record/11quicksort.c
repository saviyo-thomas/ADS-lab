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
