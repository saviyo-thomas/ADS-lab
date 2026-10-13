/*
   ===================================================================
NAME: Saviyo Thomas
ROLL NO: CS11
DATE: 06/07/2026
EXPERIMENT NO: 03

ALGORITHM: Circular Queue Implementation using Linked List (with Size Limit)
1. Define a maximum size MAX (5) for the circular queue and a Node structure with 'data' and 'next'.
2. Initialize 'front' and 'rear' pointers to NULL and 'current_size' to 0.
3. Implement ISFULL (current_size == MAX) and ISEMPTY (current_size == 0) helpers.
4. Implement ENQUEUE operation:
 a. Check if queue is Full using ISFULL. If yes, display Overflow.
 b. Create new node. If empty, set front = rear = new node and rear->next = front.
 c. Otherwise, set rear->next = new node, update rear to new node, and rear->next = front to maintain circular link.
 d. Increment current_size.
5. Implement DEQUEUE operation:
 a. Check if queue is Empty using ISEMPTY. If yes, display Underflow.
 b. Retrieve/print front->data, update front to front->next, update rear->next = front.
 c. If it was the last node, reset front and rear to NULL.
 d. Free old node and decrement current_size.
6. Implement DISPLAY operation to traverse from 'front' for current_size nodes and COUNT to print current_size.
7. Provide a menu-driven interface in main() to enqueue, dequeue, display, count and exit.
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

/*
   ===================================================================

   OUTPUT

   CS2024PG01@csserver:~/pg2026/ads/ADS-lab/record$ ./a.out

   1.Enqueue
   2.Dequeue
   3.print
   4.Count
   5.Exit
   Enter your choice :3
   Queue is empty

   1.Enqueue
   2.Dequeue
   3.print
   4.Count
   5.Exit
   Enter your choice :4
   Number of elements in queue: 0

   1.Enqueue
   2.Dequeue
   3.print
   4.Count
   5.Exit
   Enter your choice :1
Data :75

1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :1
Data :94

1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :1
Data :68

1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :1
Data :32

1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :1
Data :74

1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :1
Data :26
Queue is full

1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :4
Number of elements in queue: 5

1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :3
[75] [94] [68] [32] [74] 

1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :2
75 is dequeued

1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :2
94 is dequeued

1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :2
68 is dequeued

1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :2
32 is dequeued

1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :2
74 is dequeued

1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :2
Queue is empty

1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :5
*/
