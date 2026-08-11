#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
 char ch;
 struct* next;
}n;

n* createnode(char c){
  n* nn=(n*)malloc(sizeof(n));
  nn->ch=c;
  nn->next=NULL;
  return nn;
}

void append(n** h, n** t, c){
  n* nn=createnode(c);
  if(*h==NULL){*h=nn; *tail=nn;}
  else{(&t)->next=nn; *t=nn;}
}

void pr(const char* ip){
  int l=strlen(ip);

  for(int i=0;i<l;i++){
    if(!isdigit(ip[i])){printf("Error : enter digts only."); return;}
  }
  if(l!=9&&l!=12){printf("Error."); return;}

  n*h=NULL;
  n*t=NULL;
  
  for (int i=0;i<l;i++){append(&h,&t,ip[i]);}
  
  char dig;

  if(l==9){
    int s=0, w=10;
    n*c=h;
    while(c!=NULL){
      int d= c->ch-'0';
      s+=d*w;
      w-;
      c=c->next;
    }
    int rem=s%10;
    if(rem==0){dig='0';}
    else if(11-rem==10){dig='X';}
    else{dig='0'+(11-rem);}
    }
  else{
    int s=0, p=1;
    n*c=h;
    while(c!=NULL){
      int d=c->ch-'0';
      int w=(p%2!=0)?1:3;
      s+=d*w;
      p++;
      c=c->next;
    }
    int rem=s%10;
    dig=(r==0)?'0':('0'+(10-rem));
  }
  
  append(&h,&t,dig);

  printf("%d-digit ISBN:",(l==9)?10:13);

  n*curr=h;
  while(curr!=NULL){
    putchar()
  }
  }
}
