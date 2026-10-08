#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *prev, *next;
};

struct myDeque {
    struct Node *front, *rear;
    int size;
};

struct myDeque* createMyDeque() {
    struct myDeque* dq = (struct myDeque*)malloc(sizeof(struct myDeque));
    dq->front = dq->rear = NULL;
    dq->size = 0;
    return dq;
}

int isEmpty(struct myDeque* dq) { return dq->front == NULL; }


int getSize(struct myDeque* dq) { return dq->size; }


void insertFront(struct myDeque* dq, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = dq->front;

    if (isEmpty(dq)) dq->front = dq->rear = newNode;
    else {
        dq->front->prev = newNode;
        dq->front = newNode;
    }
    dq->size++;
}


void insertRear(struct myDeque* dq, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty(dq)) {
        newNode->prev = NULL;
        dq->front = dq->rear = newNode;
    } else {
        newNode->prev = dq->rear;
        dq->rear->next = newNode;
        dq->rear = newNode;
    }
    dq->size++;
}


void deleteFront(struct myDeque* dq) {
    if (isEmpty(dq)) {
        printf("UnderFlow\n");
        return;
    }
    dq->front = dq->front->next;
    if (dq->front) dq->front->prev = NULL;
    else dq->rear = NULL;
    dq->size--;
}


void deleteRear(struct myDeque* dq) {
    if (isEmpty(dq)) {
        printf("UnderFlow\n");
        return;
    }
    dq->rear = dq->rear->prev;
    if (dq->rear) dq->rear->next = NULL;
    else dq->front = NULL;
    dq->size--;
}


int getFront(struct myDeque* dq) { return isEmpty(dq) ? -1 : dq->front->data; }


int getRear(struct myDeque* dq) { return isEmpty(dq) ? -1 : dq->rear->data; }

void erase(struct myDeque* dq) {
    while (!isEmpty(dq)) deleteFront(dq);
}

int main() {
    struct myDeque* dq = createMyDeque();

    // Insert 5 at the rear
    insertRear(dq, 5);

    // Insert 10 at the rear
    insertRear(dq, 10);

    // Get the rear element
    printf("%d\n", getRear(dq));

    // Delete the rear element
    deleteRear(dq);

    // Get the rear element
    printf("%d\n", getRear(dq));

    // Insert 15 at the front
    insertFront(dq, 15);

    // Get the front element
    printf("%d\n", getFront(dq));

    // Get the current size
    printf("%d\n", getSize(dq));

    // Delete the front element
    deleteFront(dq);

    // Get the front element
    printf("%d\n", getFront(dq));

    return 0;
}
