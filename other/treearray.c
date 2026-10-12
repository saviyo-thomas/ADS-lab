#include<stdio.h>
#define SIZE 500

int data[SIZE];
int p=0;


void ins(int d){
  if(p==0){data[p]=d; p++; return;  }
  if(d<data[p]){
    data[2*p]=d; p++; return; }
    cur=2*cur+1;
    ins(d);
  }
  else{
    if(2*cur+2>=end){ data[2*cur+2]=d; end++; return; }
    cur=2*cur+2;
    ins(d);
  }
  if(cur!=0) cur=(cur-1)/2;
  return;
}
void dis(){
  if(end==0){printf("\n Tree is empty"); return;}
  printf("Tree is stored in the array:");
  for(int i=0;i<cur;i++){printf("%d ",data[cur]);}
  return;
}

int main(){
  int ch,d;
  while(1){
  printf("\n====Tree Menu====\n1.Insert\n2.display\n3.exit\nEnter your choice:");
  scanf("%d",&ch);
  switch(ch){
    case 1: printf("\nEnter data to insert: ");
            scanf("%d",&d);
            ins(d);
            break;
    case 2: dis();
            break;
    case 3:return 0;
    default: printf("\nInvalid choice");
  }}
  return 0;
}
