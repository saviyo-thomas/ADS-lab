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
    
    // If the character is an operand, add it to the output string
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')){
      postfix[j++] = c;
    }
    // If the character is '(', push it to the stack
    else if(c == '('){
      push(&head, c);
    }
    // If the character is ')', pop and output from the stack until '(' is encountered
    else if(c == ')'){
      while(head != NULL && peek(&head) != '('){
        postfix[j++] = pop(&head);
      }
      if(head != NULL) pop(&head); // Remove '(' from stack
    }
    // An operator is encountered
    else{
      while(head != NULL && precedence(peek(&head)) >= precedence(c)){
        postfix[j++] = pop(&head);
      }
      push(&head, c);
    }
    i++;
  }
  
  // Pop all remaining operators from the stack
  while(head != NULL){
    postfix[j++] = pop(&head);
  }
  
  postfix[j] = '\0';
}
