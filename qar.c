#include<stdio.h>


int a[100],b=0,f=0;
void enq(int d);
void dq();


int main(){
  int ch,d;
  while(1){
   printf("\n1.Enqueue\n2.Dequeue\n3.Exit\nEnter your choice :");
   scanf("%d",&ch);
   switch(ch){
     case 1:{printf("\nData :"); scanf("%d",&d); enq(d); break;}
     case 2:dq(); break;
     case 3:return 0;
     default:printf("Enter valid input");
  }}
  return 0;
}

void enq(int d){
  a[b]=d;
  b=(b+1)%100;
}

void dq(){
  if(b==f){printf("Queue is empty"); return;}
  printf("\n%d is dequeued",a[f]); f=(f+1)%100;
}

