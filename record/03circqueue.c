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