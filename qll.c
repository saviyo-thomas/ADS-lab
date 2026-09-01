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

void clrscr(){
  printf("\e[1;1H\e[2J");
  return;
}

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
  clrscr();
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
      printf("\nPress Enter to continue");
      getchar(); getchar();
      usleep(500000);
      break;
    case 3: return 0;
    default:
      printf("\nEnter a valid input...");
      usleep(500000);
  }}
  return 0;
}
