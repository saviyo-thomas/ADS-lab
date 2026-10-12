#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>

typedef struct node{
  int id;
  struct node*next;
  struct node*prev;
}n;

void clrscr(){
  printf("\e[1;1H\e[2J");
  return;
}

n* createnode(int d){
  n* nn=(n*)malloc(sizeof(n));
  nn->id=d;
  nn->next=NULL;
  nn->prev=NULL;
  return nn;
}

void append(n** h, int d){
  n* nn=createnode(d);
  if(*h==NULL){*h=nn; return;}
  n* l=*h;
  while(l->next!=NULL){l=l->next;}
  l->next=nn;
  nn->prev=l;
  return;
}

void insb(n** h,int d){
  n* nn=createnode(d);
  if(*h==NULL){*h=nn; nn->prev=h; return;}//if head is null-> no list exits, ->head gets the value of new node
  else{nn->next=*h; *h=nn; nn->prev=h; }//list exists -> new node's next gets the value in head ie:1st node's address
  return;
}

void trall(n* h){
  n*t=h;
  printf("\nLInked list\n");
  while(t!=NULL){
    printf("%d->",t->id);
    t=t->next;
  }
  printf("NULL\n");
}

n* search(n* h, int k){
  n* t=h;
  while(t!=NULL){
    if(t->id==k){return t;}
    t=t->next;
  }
  return NULL;
}

void ins(n** h, int d){
  n* nn=createnode(d);
  if(*h==NULL){*h=nn; return;}
  else{
    int pos;
    n* z;
    while(true){
      trall(*h);
      printf("\nEnter preceding record:");
      scanf("%d",&pos);
      z=search(*h,pos);
      if(z==NULL){
        printf("Enter a valid input\npress any key to continue.");
        getchar();
        continue;}
      else{
        nn->next=z->next;
        z->next=nn;
      }
    }
  }
  return;
}

int main(){
  n* hd=NULL;

  int c,d;

  while(true){
  clrscr();
  printf("\n1.Insert node at start\n2.Print list\n3.Insert node at End\n4.Insert node in between\n5.exit\n\nEnter your choice:");
  scanf("%d",&c);
 
  switch(c){
    case 1:
      printf("\nEnter data:");
      scanf("%d",&d);
      insb(&hd,d);
      break;
    case 2:
      clrscr();
      trall(hd);
      
      printf("Press any key to continue");
      sleep(3);
      break;
    case 3:
      printf("Enter data:");
      scanf("%d",&d);
      append(&hd,d);
      break;
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
