/*
===================================================================
NAME: Saviyo Thomas
ROLL NO: CS11
DATE: 06/07/2026
EXPERIMENT NO: 03

ALGORITHM: Circular Queue Implementation using Array
1. Define a maximum size MAX for the circular queue.
2. Initialize an array of size MAX and pointers 'front' and 'rear' to -1.
3. Implement ENQUEUE operation:
   a. Check if Queue is Full: ((rear + 1) % MAX == front). If yes, display Overflow.
   b. If 'front' is -1, set 'front' to 0.
   c. Update 'rear' as (rear + 1) % MAX and insert the element at queue[rear].
4. Implement DEQUEUE operation:
   a. Check if Queue is Empty: (front == -1). If yes, display Underflow.
   b. Retrieve/print the element at queue[front].
   c. If front == rear (only one element), reset both 'front' and 'rear' to -1.
   d. Otherwise, update 'front' as (front + 1) % MAX.
5. Implement DISPLAY operation to traverse from 'front' to 'rear' circularly.
6. Provide a menu-driven interface in main().
===================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define size 5

typedef struct node {
    int data;
    struct node* next;
} node;

node* front = NULL;
node* rear = NULL;
int current_size = 0;

void enq(int d);
void dq();
void count();
void dis();
bool isfull();
bool isempty();

bool isfull() {
    return current_size == size;
}

bool isempty() {
    return current_size == 0;
}

int main() {
    int ch, d;
    while(1) {
        printf("\n1.Enqueue\n2.Dequeue\n3.print\n4.Count\n5.Exit\nEnter your choice :");
        if (scanf("%d", &ch) != 1) return 0;
        switch(ch) {
            case 1: {
                printf("Data :");
                if (scanf("%d", &d) == 1) { enq(d); }
                break;
            }
            case 2: dq(); break;
            case 3: dis(); break;
            case 4: count(); break;
            case 5: return 0;
            default: printf("Enter valid input\n");
        }
    }
    return 0;
}

void enq(int d) {
    if (isfull()) { 
        printf("Queue is full\n"); 
        return; 
    }
    
    node* newNode = (node*)malloc(sizeof(node));
    newNode->data = d;
    newNode->next = NULL;

    if (isempty()) {
        front = newNode;
        rear = newNode;
        rear->next = front;
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
    current_size++;
}

void dq() {
    if (isempty()) { 
        printf("Queue is empty\n"); 
        return; 
    }
    
    printf("%d is dequeued\n", front->data);
    node* temp = front;
    
    if (front == rear) {
        front = NULL;
        rear = NULL;
    } else {
        front = front->next;
        rear->next = front; 
    }
    
    free(temp);
    current_size--;
}

void count() {
    printf("Number of elements in queue: %d\n", current_size);
}

void dis() {
    if (isempty()) { 
        printf("Queue is empty\n"); 
        return; 
    }
    
    node* temp = front;
    for (int i = 0; i < current_size; i++) {
        printf("[%d] ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}