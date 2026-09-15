#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
  n* l;
  int d;
  n* r;
}n;

n* h=NULL;

n* create(int d){
  n* nn=(n*)malloc(sizeof(n));
  nn->d=d;
  nn->l=NULL;
  nn->r=NULL;
}

void ins(){

}

void ser(n* h, int k){
  if (k==h->d){printf("\nKey is found");}
}

int main(){

  int ch,data,key;
  printf("\n====BST Menu=====\n1.Insertion\n2.search");
  scanf("%d",&ch);
  switch(ch){
    case 1: {
              printf("\n Enter value to insert");
              scanf("%d",&data);
              ins(h,data); break;}
    case 2: {
              printf("\n Enter key:");
              scanf("%d",&key);
              ser(h,key);break;}
    default: printf("\n Enter a valid input");
}
