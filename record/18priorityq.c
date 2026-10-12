/* 18. Implementation of priority queue */
#include <stdio.h>
#define MAX 100

struct Item {
    int data;
    int priority;
};

struct Item pq[MAX];
int size = -1;

void enqueue(int data, int priority) {
    if (size >= MAX - 1) {
        printf("Priority Queue Overflow!\n");
        return;
    }
    size++;
    pq[size].data = data;
    pq[size].priority = priority;
}

int peek() {
    int highestPriority = -1089203;
    int ind = -1;

    for (int i = 0; i <= size; i++) {
        if (highestPriority == pq[i].priority && ind > -1 && pq[ind].data < pq[i].data) {
            highestPriority = pq[i].priority;
            ind = i;
        } else if (pq[i].priority > highestPriority) {
            highestPriority = pq[i].priority;
            ind = i;
        }
    }
    return ind;
}

void dequeue() {
    if (size < 0) {
        printf("Priority Queue Underflow!\n");
        return;
    }
    int ind = peek();
    for (int i = ind; i < size; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

void display() {
    for (int i = 0; i <= size; i++) {
        printf("Value: %d, Priority: %d\n", pq[i].data, pq[i].priority);
    }
}

int main() {
    int choice, val, pri;
    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter value and priority: ");
                scanf("%d %d", &val, &pri);
                enqueue(val, pri);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}