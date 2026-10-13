/*
   ===================================================================
NAME: Saviyo Thomas
ROLL NO: CS11
DATE: 05/07/2026
EXPERIMENT NO: 01

ALGORITHM: Stack Implementation using Array
1. Define a maximum size MAX for the stack array.
2. Initialize a stack array of size MAX and set the 'top' pointer to -1.
3. Implement PUSH operation:
 a. Check if 'top' equals MAX - 1 (Stack Overflow). If yes, return.
 b. Otherwise, increment 'top' and insert the element at stack[top].
4. Implement POP operation:
 a. Check if 'top' equals -1 (Stack Underflow). If yes, return.
 b. Otherwise, print/retrieve the element at stack[top] and decrement 'top'.
5. Implement PEEK/DISPLAY operations to look at the top element or traverse from top to 0.
6. Provide a menu-driven interface in main() to continuously run these operations until the user exits.
===================================================================
 */

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


/*
===================================================================
OUTPUT

