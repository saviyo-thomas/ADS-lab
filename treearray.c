#include<stdio.h>
#define SIZE 500

int data[SIZE];
int end=0,cur=0;

void ins(int d){
  if(end==0){ data[0]=d; return;  }
  if(d<data[cur]){
    if(2*cur+1>=end){ data[2*cur+1]=d; end++; return; }
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
  if(cur>=end) return;
  printf("%d ",data[cur]);
}

int main(){
  int ch,d;
  printf("\n====Tree Menu====");
  scanf("%d",&ch);
  switch(ch){
    case 1: printf("\nEnter data to insert: ");
            scanf("%d",&d);
            ins(d);
            break;
    case 2: printf("\nTree data: ");
            dis();
            break;
    default: printf("\nInvalid choice");
  }
  return 0;
}
