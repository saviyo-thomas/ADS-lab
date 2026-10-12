#include<stdio.h>
#include<stdlib.h>

struct node{
  int data;
  struct node*next;
};

void printlist(struct node* h){
  struct node*temp=h;

  printf("\nLinked List\n");
  while(temp!=NULL){
    printf("%d.",temp->data);
    temp=temp->next;
  }
  printf("NULL\n");
}

void append(struct node**h, int nd){
  struct node*nn=(struct node*)malloc(sizeof(struct node));
  nn->data=nd;
  nn->next=NULL;
  if(*h==NULL){
    *h=nn;
    return;
  }
  struct node* l= *h;
  while(l->next!=NULL){
    l=l->next;
  }
  l->next=nn;
}

int main(){
  struct node* hd=NULL;

  append(&hd,10);
  append(&hd,20);
  append(&hd,30);

  printlist(hd);


  return 0;
}
