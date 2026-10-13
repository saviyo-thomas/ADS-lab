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
 a. Read data and dynamically allocate memory for a new node.
 b. Set new_node->data = value and new_node->next = top.
 c. Update 'top' to point to the new node.
4. Implement POP operation:
 a. Check if 'top' is NULL (Stack Underflow). If yes, return.
 b. Print top->data, update 'top' to top->next and free old top.
5. Implement PEEK operation by printing top->data, or Underflow if empty.
6. Provide a menu-driven program in main() to push, pop, peek and exit.
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

/*
   ===================================================================

   OUTPUT

   CS2024PG01@csserver:~/pg2026/ads/ADS-lab/record$ ./a.out

   1.Push
   2.Pop
   3.Peek
   4.Exit
   Enter choice :2
   !!Stack Underflow!!
   1.Push
   2.Pop
   3.Peek
   4.Exit
   Enter choice :1
   Enter data :10
   1.Push
   2.Pop
   3.Peek
   4.Exit
   Enter choice :1
   Enter data :20
   1.Push
   2.Pop
   3.Peek
   4.Exit
   Enter choice :3
   20 is at the top
   1.Push
   2.Pop
   3.Peek
   4.Exit
   Enter choice :2
   20 popped
   1.Push
   2.Pop
   3.Peek
   4.Exit
   Enter choice :3
   10 is at the top
   1.Push
   2.Pop
   3.Peek
   4.Exit
   Enter choice :2
   10 popped
   1.Push
   2.Pop
   3.Peek
   4.Exit
   Enter choice :2
   !!Stack Underflow!!
   1.Push
   2.Pop
   3.Peek
   4.Exit
   Enter choice :4
*/
