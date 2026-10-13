/*
   ===================================================================
NAME: Saviyo Thomas
ROLL NO: CS11
DATE: 15/07/2026
EXPERIMENT NO: 06

ALGORITHM: Queue Implementation using Singly Linked List
1. Define a Node structure with 'data' and a 'next' pointer.
2. Initialize 'front' (h) and 'rear' (t) pointers to NULL.
3. Implement ENQUEUE operation:
 a. Create a new node with data.
 b. If queue is empty (front == NULL), set both 'front' and 'rear' to the new node.
 c. Otherwise, set rear->next = new_node and update 'rear' to new_node.
4. Implement DEQUEUE operation:
 a. Check if 'front' is NULL (Queue empty). If yes, return.
 b. Print front->data, update 'front' to front->next.
 c. If 'front' becomes NULL, set 'rear' to NULL.
5. Provide a menu-driven interface in main() to enqueue, dequeue and exit.
===================================================================
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>

typedef struct node{
  int data;
  struct node*next;
}n;
n* h=NULL;
n* t=NULL;

bool ismt(){
  if(h==NULL){return true;}
  else return false;
}

n* createnode(int d){
  n* nn=(n*)malloc(sizeof(n));
  nn->data=d;
  nn->next=NULL;
  return nn;
}

void nq(int d){
  n* nn=createnode(d);
  if(h==NULL){h=nn; t=nn;}
  else{t->next=nn; t=nn;}
  return;
}

void dq(){
  if(ismt()){printf("\nQueue is empty"); return;}
  printf("%d is dequeued",h->data);
  h=h->next;
  if (h==NULL){t=NULL;}
}

int main(){
  int c,d;

  while(true){

    printf("\n1.Enqueue\n2.Dequeue\n3.Exit\nEnter your choice :");
    scanf("%d",&c);

    switch(c){
      case 1:
        printf("\nEnter data:");
        scanf("%d",&d);
        nq(d);
        break;
      case 2: 
        dq();
        usleep(500000);
        break;
      case 3: return 0;
      default:
              printf("\nEnter a valid input...");
              usleep(500000);
    }}
  return 0;
}

/*
   ===================================================================

   OUTPUT

   CS2024PG01@csserver:~/pg2026/ads/ADS-lab/record$ ./a.out

   1.Enqueue
   2.Dequeue
   3.Exit
   Enter your choice :2
   Queue is empty
   1.Enqueue
   2.Dequeue
   3.Exit
   Enter your choice :1
   Enter data:10
   1.Enqueue
   2.Dequeue
   3.Exit
   Enter your choice :1
   Enter data:20
   1.Enqueue
   2.Dequeue
   3.Exit
   Enter your choice :1
   Enter data:30
   1.Enqueue
   2.Dequeue
   3.Exit
   Enter your choice :2
   10 is dequeued
   1.Enqueue
   2.Dequeue
   3.Exit
   Enter your choice :2
   20 is dequeued
   1.Enqueue
   2.Dequeue
   3.Exit
   Enter your choice :2
   30 is dequeued
   1.Enqueue
   2.Dequeue
   3.Exit
   Enter your choice :2
   Queue is empty
   1.Enqueue
   2.Dequeue
   3.Exit
   Enter your choice :3
*/
