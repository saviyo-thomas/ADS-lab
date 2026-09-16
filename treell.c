#include<stdio.h>
#include<stdlib.h>

typedef struct node{
  struct node* lc;
  struct node* rc;
  int data;
}n;

n* ins (n* h, int d){
  if(h==NULL){
    n* nn=(n*)malloc(sizeof(n));
    nn->data=d;
    nn->lc=NULL;
    nn->rc=NULL;
    return nn;
  }
  if(d<h->data){
    h->lc=ins(h->lc,d);
  }
  else if(d>h->data){
    h->rc=ins(h->rc,d);
  }
  return h;
}

void del(n* h, int d){
  if(h==NULL){
    printf("\nData not found");
    return;
  }
  if(d<h->data){
    del(h->lc,d);
  }
  else if(d>h->data){
    del(h->rc,d);
  }
  else{
    // Node to be deleted found
    if(h->lc==NULL && h->rc==NULL){
      free(h);
      h=NULL;
    }
    else if(h->lc==NULL){
      n* temp=h;
      h=h->rc;
      free(temp);
    }
    else if(h->rc==NULL){
      n* temp=h;
      h=h->lc;
      free(temp);
    }
    else{
      // Node with two children
      n* temp=h->rc;
      while(temp->lc!=NULL){
        temp=temp->lc;
      }
      h->data=temp->data;
      del(h->rc,temp->data);
    }
  }
}
void search(n* h, int d){
  if(h==NULL){  
    printf("\nData not found");
    return;
  }
  if(d<h->data){
    return search(h->lc,d);
  }
  else if(d>h->data){
    return search(h->rc,d);
  }
  else{
    printf("\nData found at node with value: %d",h->data);
    return ;
  }
}

void display(n* h){
  if(h==NULL){
    printf(" End");
    return;
  }
  display(h->lc);
  printf("%d ",h->data);
  display(h->rc);
}

int main(){
  n* hd=NULL;
  int ch,data;
  while(1){
    printf("\n========Tree=======\n1.insert\n2.Delete\n3.Search\n4.display\n5.Exit");
    scanf("%d",&ch);
    switch(ch){
      case 1:{ printf("\nEnter data :");
               scanf("%d",&data);
               ins(hd,data); break;}
      case 2:{ printf("\nEnter data to be deleted :");
               scanf("%d",&data);
               del(hd,data);
               break;}
      case 3:{ printf("\nEnter data to search :");
               scanf("%d",&data);
               search(hd,data);
               break;}
      case 4:{ printf("\nThe tree is :");
               display(hd);
               break;}
      case 5:{return 0;}
      default :printf("Invalid input");
  }}
  return 0;
}
