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

bool ismt(n** h){
  return h==NULL;
}

n* createnode(int d){
  n* nn=(n*)malloc(sizeof(n));
  nn->data=d;
  nn->next=NULL;
  return nn;
}

void nq(n** h, int d){
  n* nn=createnode(d);
  if(*h==NULL){*h=nn; return;}
  
  return;
}

n* dq(n* h,int d){
  if(h==NULL){printf("Empty queue");
  else{h=h->next; return h}
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
      nq(&hd,d);
      break;
    
    case 1:
      
    case 4:
      printf("\nEnter data:");
      scanf("%d",&d);
      ins(&hd,d);
      break;
    case 5:
      return 0;
    default:
      printf("\nEnter a valid input...");
  }}
  return 0;
}
