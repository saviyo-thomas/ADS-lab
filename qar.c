#include<stdio.h>


int a[5],b=0,f=0;
void enq(int d);
void dq();
void vq();
int cq();


int main(){
  int ch,d;
  while(1){
   printf("\n1.Enqueue\n2.Dequeue\n3.Traversal\n4.Count\n5.Exit\nEnter your choice :");
   scanf("%d",&ch);
   switch(ch){
     case 1:{printf("\nData :"); scanf("%d",&d); enq(d); break;}
     case 2:dq(); break;
     case 3:printf("Queue has %d elements",cq()); break;
     case 4:cq(); break;
     case 5:return 0;
     default:printf("Enter valid input");
  }}
  return 0;
}

void enq(int d){
  if((f<b)&&(b-f)==5){printf("Queue is full"); return;}
  else if((f))
  a[b]=d;
  b=(b+1)%100;
}

void dq(){
  if(b==f){printf("Queue is empty"); return;}
  printf("\n%d is dequeued",a[f]); f=(f+1)%100;
}

void vq(){
  printf("\n");
  for (int i=f; f!=b; f=(f+1)%100){
    printf("%d,"a[i]);
  }
}

int cq(){
  if(f==b)return 0;
  else if(f<b)return(b-f);
}