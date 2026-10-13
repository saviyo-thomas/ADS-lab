/*
   ===================================================================
NAME: Saviyo Thomas
ROLL NO: CS11
DATE: 13/07/2026
EXPERIMENT NO: 05

ALGORITHM: Stack Implementation using Singly Linked List
1. Define a Node structure with 'data' and a 'next' pointer.
2. Initialize 'top' pointer to NULL.
3. Implement PUSH operation:
 a. Dynamically allocate memory for a new node.
 b. If memory allocation fails, print Stack Overflow.
 c. Set new_node->data = value and new_node->next = top.
 d. Update 'top' to point to the new node.
4. Implement POP operation:
 a. Check if 'top' is NULL (Stack Underflow). If yes, return.
 b. Create a temporary pointer pointing to 'top'.
 c. Update 'top' to top->next.
 d. Free the temporary node and return/print its data.
5. Implement DISPLAY operation by traversing from 'top' to NULL.
6. Provide a menu-driven program in main().
===================================================================
 */

//stack using linked list
#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  int d;
  struct node* next;
}n;

n* createnode(int d){
  n* nn=(n*)malloc(sizeof(n));
  nn->d=d;
  nn->next=NULL;
  return nn;
}
void push(n** h);
void pop(n** h);
void peek(n** h);
void wait();

int main(){
  n* head=NULL;

  int c;
  while(1){
    printf("\n1.Push\n2.Pop\n3.Peek\n4.Exit\nEnter choice :");
    scanf("%d",&c);

    switch(c){
      case 1:{push(&head); break;}
      case 2:{pop(&head); break;}
      case 3:{peek(&head); break;}
      case 4:return 0;
      default:{printf("\n Enter a valid input");}
    }}
  return 0;
}

void push (n** h){
  int d;
  printf("\nEnter data :");
  scanf("%d",&d);
  n* nn=createnode(d);
  if(*h==NULL){*h=nn; return;}
  else{nn->next=*h; *h=nn;}
  return;
}

void pop (n** h){
  if(*h==NULL){printf("!!Stack Underflow!!"); return;} 
  else{printf("%d popped",(*h)->d);}
  n* t=*h;
  *h=(*h)->next;
  free(t);
  return;
}

void peek(n** h){
  if(*h==NULL){printf("!!Stack Underflow!!"); return;}
  else{printf("%d is at the top",(*h)->d);}
  return;
}
