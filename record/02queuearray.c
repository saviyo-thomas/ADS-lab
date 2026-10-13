/*
===================================================================
NAME: Saviyo Thomas
ROLL NO: CS11
DATE: 05/07/2026
EXPERIMENT NO: 02

ALGORITHM: Linear Queue Implementation using Array
1. Define a maximum size MAX for the queue array.
2. Initialize an array of size MAX and two pointers 'front' and 'rear' to -1.
3. Implement ENQUEUE operation:
 a. Check if 'rear' equals MAX - 1 (Queue Overflow). If yes, return.
 b. If 'front' is -1, set 'front' to 0.
 c. Increment 'rear' and insert the element at queue[rear].
4. Implement DEQUEUE operation:
 a. Check if 'front' is -1 or greater than 'rear' (Queue Underflow). If yes, return.
 b. Otherwise, print/retrieve queue[front] and increment 'front'.
 c. If 'front' exceeds 'rear', reset both 'front' and 'rear' to -1.
5. Implement DISPLAY and COUNT operations to traverse from 'front' to 'rear' and print (rear-front+1).
6. Provide a menu-driven program in main() to allow users to enqueue, dequeue, display, count and exit.
===================================================================
 */

#include<stdio.h>
#include<stdbool.h>
#define size 3


int a[size],b=-1,f=-1;

void enq(int d);
void dq();
void count();
void dis();

bool isfull(){ return b==size-1;}

bool isempty(){ return f==-1;}

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
  if(f==-1)f=0;
  b++; a[b]=d;
}

void dq(){
  if(isempty()){printf("\nQueue is empty");return;}
  else {  printf("\n%d is dequeued", a[f]); f++; }
  if(f>b){f=-1; b=-1;}
}

void count(){
  if(isempty()){printf("\nQueue is empty");return;}
  int c;
  c=(b-f+1);
  printf("\nNumber of elements in queue: %d",c);
}

void dis(){
  if(isempty()){printf("\nQueue is empty");return;} 
  for (int i=f; i<=b;++i){
    printf("[%d] ",a[i]);
  }}

/*
   ===================================================================

   OUTPUT

CS2024PG01@csserver:~/pg2026/ads/ADS-lab/record$ ./a.out

1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :4

Queue is empty
1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :3

Queue is empty
1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :1

Data :85

1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :1

Data :64

1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :1

Data :25

1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :1

Data :74

Queue is full please wait till the queue is empty again
1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :3
[85] [64] [25] 
1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :4

Number of elements in queue: 3
1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :2

85 is dequeued
1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :3
[64] [25] 
1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :2

64 is dequeued
1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :4

Number of elements in queue: 1
1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :2

25 is dequeued
1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :2

Queue is empty
1.Enqueue
2.Dequeue
3.print
4.Count
5.Exit
Enter your choice :5
*/
