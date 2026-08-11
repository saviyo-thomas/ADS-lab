#include<stdio.h>


int a[5],top=-1,data,ch;

void push(){
  if(top>4){printf("\n!!Stack overflow!!");}
  else{
  top++;
  printf("\nEnter data :");
  scanf("%d",&data);
  a[top]=data;
  }
  return;
}

void pop(){
  if(top<0){printf("\n!!Stack underflow!!");}
  else{
    printf("%d popped\n",a[top]);
    top--;
  }
  return;
}

void peep(){
  printf("%d is at top\n",a[top]);
  return;
}

int main(){
   while(1){
     printf("\n1.Push\n2.pop\n3.peep\n4.exit\n Enter Choice :");
     scanf("%d",&ch);
     switch(ch){
       case 1:{push(); break;}
       case 2:{pop(); break;}
       case 3:{peep(); break;}
       case 4:return 0;
       default:{printf("\nEnter valid input");}
     }
   }
 return 0;
}
     
