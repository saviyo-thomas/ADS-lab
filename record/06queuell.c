/*
===================================================================
NAME: Saviyo Thomas
ROLL NO: CS11
DATE: 15/07/2026
EXPERIMENT NO: 06

ALGORITHM: Queue Implementation using Singly Linked List
1. Define a Node structure with 'data' and a 'next' pointer.
2. Initialize 'front' and 'rear' pointers to NULL.
3. Implement ENQUEUE operation:
   a. Create a new node with data.
   b. If queue is empty (rear == NULL), set both 'front' and 'rear' to the new node.
   c. Otherwise, set rear->next = new_node and update 'rear' to new_node.
4. Implement DEQUEUE operation:
   a. Check if 'front' is NULL (Queue Underflow). If yes, return.
   b. Store front node in a temporary pointer.
   c. Update 'front' to front->next.
   d. If 'front' becomes NULL, set 'rear' to NULL.
   e. Free the temporary node and retrieve its data.
5. Implement DISPLAY operation by traversing from 'front' to NULL.
6. Provide a menu-driven interface in main().
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
