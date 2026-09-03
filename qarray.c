#include<stdio.h>

//q array
int q[100],b=0;
void enq(int d);
void dq();

int main(){
    int ch, d;
    while(1){
        printf("\n Enter your choice\n1.Enqueue\n2.Dequeue\n3Exit\nEnter your choice :");
        scanf("%d",&ch);
        switch(ch){
            case 1: printf("\nData :"); scanf("%d",&d); enq(d); break;
            case 2: dq(); break;
            case 3: return 0;
            default: printf("\nEnter a valid input please");
        }
    }
    return 0;
}
 void enq(int d){
    q[b]=d; b++;
    return;
 }
void dq(){
    if(b==0){printf("\nQueue is empty"); return;}
    printf("%d is dequeued",q[0]);
    for(int i=1; i<b; i++){q[i-1]=q[i]}
    return;
}