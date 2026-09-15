#include<stdio.h>

typedef struct node{
  struct node* lc;
  struct node* rc;
  int data;
}n;

n* ins (n* h, int d){
 
}

int main(){
  n* hd=NULL;
  int ch,data;
  while(1){
    printf("\n========Tree=======\n1.insert\n2.Delete\n3.display\n4.Exit");
    scanf("%d",&ch);
    switch(ch){
      case 1:{
               printf("\nEnter data :");
               scanf("%d",&data);             
               ins(hd,data);
               break;
             }
      case 2:{

             }
    }
  }
  return 0;
}
