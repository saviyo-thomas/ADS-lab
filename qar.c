#include<stdio.h>
#include<stdbool.h>
#define size 3

int a[size],b=-1,f=-1;

void enq(int d);
void dq();
void count();
void dis();

bool isfull(){
  return b==size-1;
}
bool isempty(){
  return f==-1;
}
int main(){
  int ch,d;
  while(1){
   printf("\n1.Enqueue\n2.Dequeue\n3.print\n4.Count\n5.Exit\nEnter your choice :");
   scanf("%d",&ch);
   switch(ch){
     case 1:{printf("\nData :"); scanf("%d",&d); enq(d); break;}
     case 2:dq(); break;
     case 3:dis(); break;
     case 4:count(); break;
     case 5:return 0;
     default:printf("\nEnter valid input");
  }}
  return 0;
}

void enq(int d){
  if(isfull()){printf("\nQueue is full please wait till the queue is empty again"); return;}
  else {
    b++; a[b]=d;}
}

void dq(){
  if(isempty()){printf("\nQueue is empty");return;}
  else {f++; printf("\n%d is dequeued",a[f]);}
}

void count(){
  int c;
  c=(b-f);
  printf("b:%df:%d",b,f);
  printf("\nNumber of elements in queue: %d",c);
}

void dis(){
  if(isempty()){printf("\nQueue is empty");return;} 
  for (int i=f; i<=b;++i){
    printf("[%d] ",a[i]);
}}
