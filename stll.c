//stack using linked list
#include<stdio.h

typedef struct node{
	int d;
	struct node* next;
}n;

void clrscr(){
  printf("\e[1;1H\e[2J");
  return;
}

n* createnode(int d){
  n* nn=(n*)malloc(sizeof(n));
  nn->id=d;
  nn->next=NULL;
  return nn;
}
void push(n** h);
void pop(n** h);
void peek(n** h);

int main(){
	n* head=NULL;

  int c;
  while(1){
    clrscr();
    printf("\n1.Push\n2.Pop\n3.Peek\n4.Exit");
    scanf("%d",&c);

    switch(c){
      case 1:{push(&head); break;}
      case 2:{pop(&head); break;}
      case 3:{peek(&head); break;}
      case 4:return;
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
  if(*h=NULL){printf("!!Stack Underflow!!");}
  else{printf("%d popped",h->d);}
  n* t=*h;
  h=h->next;
  free(t);
  return;
}

void peek(n** h){
  if(*h=NULL){printf("!!Stack Underflow!!");}
  else{printf("%d is at the top",h->d);}
  return;
}