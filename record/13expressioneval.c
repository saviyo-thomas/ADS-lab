/*
===================================================================
NAME: Saviyo Thomas
ROLL NO: CS11
DATE: 06/08/2026
EXPERIMENT NO: 13

ALGORITHM: Infix to Postfix Conversion using Stack
1. Define a Node structure with 'data' (char) and 'next' for stack, with push, pop and peek.
2. Define PRECEDENCE function: '^' = 3, '*'/'/' = 2, '+'/'-' = 1, else -1.
3. Implement INFIXTOPOSTFIX function:
 a. Scan infix string left to right.
 b. If operand (alphanumeric), append to postfix.
 c. If '(' push onto stack.
 d. If ')' pop and append until '(' is found, then discard '('.
 e. If operator, pop and append while stack top has >= precedence, then push current operator.
 f. After scan, pop remaining stack contents to postfix and terminate string.
4. In main(), read infix string, call conversion, and print postfix expression.
===================================================================
 */

//Infix to Postfix conversion using stack (linked list)
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node{
  char d;
  struct node* next;
}n;

n* createnode(char d){
  n* nn=(n*)malloc(sizeof(n));
  nn->d=d;
  nn->next=NULL;
  return nn;
}

void push(n** h, char d);
char pop(n** h);
char peek(n** h);
int precedence(char c);
void infixtopostfix(char* infix, char* postfix);

int main(){
  char infix[100], postfix[100];

  printf("\nEnter infix expression :");
  scanf("%s", infix);

  infixtopostfix(infix, postfix);

  printf("Postfix expression :%s\n", postfix);
  return 0;
}

void push (n** h, char d){
  n* nn=createnode(d);
  if(*h==NULL){*h=nn; return;}
  else{nn->next=*h; *h=nn;}
  return;
}

char pop (n** h){
  if(*h==NULL){return '\0';} 
  n* t=*h;
  char popped = t->d;
  *h=(*h)->next;
  free(t);
  return popped;
}

char peek(n** h){
  if(*h==NULL){return '\0';}
  return (*h)->d;
}

int precedence(char c){
  if(c == '^') return 3;
  if(c == '*' || c == '/') return 2;
  if(c == '+' || c == '-') return 1;
  return -1;
}

void infixtopostfix(char* infix, char* postfix){
  n* head = NULL;
  int i = 0, j = 0;

  while(infix[i] != '\0'){
    char c = infix[i];
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
      postfix[j++] = c;
    }
    else if(c == '('){ push(&head, c); }
    else if(c == ')'){
      while(head != NULL && peek(&head) != '('){
        postfix[j++] = pop(&head); }
      if(head != NULL) pop(&head); }
    else{
      while(head != NULL && precedence(peek(&head)) >= precedence(c)){
        postfix[j++] = pop(&head);
      }
      push(&head, c); }
    i++;
  }

  while(head != NULL){ postfix[j++] = pop(&head); }
  postfix[j] = '\0';
}

/*
   ===================================================================

   OUTPUT

   CS2024PG01@csserver:~/pg2026/ads/ADS-lab/record$ ./a.out

   Enter infix expression :(a+b)*c-d/e
   Postfix expression :ab+c*de/-
*/
