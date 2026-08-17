#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>

typedef struct node{
  int id;
  struct node*next;
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

void append(n** h, int d){
  n* nn=createnode(d);

}

n* dq(n* h,int d){
  if(h==NULL){printf("Empty queue");return NULL;}//if head is null-> no list exits, ->head gets the value of new node
  else{h=h->next; return h}
}

int main(){
  n* hd=NULL;

  int c,d;

  while(true){
  clrscr();
  printf("\n1.Enqueue\n2.Dequeue\n3.Exit\nEnter your choice :");
  scanf("%d",&c);
 
  switch(c){
    case 1:
      printf("\nEnter data:");
      scanf("%d",&d);
      append(&hd,d);
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
