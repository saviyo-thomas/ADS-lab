//gym_console
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int mcount=0,madd=0;


struct memb{
  int id;
  char name[20];
  float wt;
  int date;
}m[50];

void membsort(){
  int i,j;
  struct memb temp;
  for(i=0;i<mcount-1;i++){
    for(j=i-1;j<mcount;j++){
      if(m[i].date<m[j].date){
        temp=m[i];
        m[i]=m[j];
        m[j]=temp;
      }
    }
  }
}

void admem(){
  bool t[4];
  printf("\nEnter new member details");
  if(mcount<50){
    printf("\nName: ");
    t[0]=scanf("%s",m[madd].name);
    printf("\nID: ");
    t[1]=scanf("%d",&m[madd].id);
    printf("\nWeight :");
    t[2]=scanf("%f",&m[madd].wt);
    printf("\nEnter days since last workout: ");
    t[3]=scanf("%d",&m[madd].date);
    if (t[0]&&t[1]&&t[2]&&t[3]) {
      madd++;
      mcount++;
      printf("\nMember added successfully\n");
    }
  }
  else printf("sorry members are maxed out");
}

void viewall(){
   printf("\n=ID=\t=Name=\t=Weight=\t=Days from last workout=");
   for (int i=0; i<mcount; i++){
     printf("\n==%d===  ==%s== ==%.2f== ==%d==\n",m[i].id,m[i].name,m[i].wt,m[i].date);
  }
}

void viewinact(){
   printf("\n=ID=\t=Name=\t=Weight=\t=Days from last workout=");
   for (int i=0; i<mcount; i++){
     if(m[i].date>=7){
       printf("\n==%d===  ==%s== ==%.2f== ==%d==\n",m[i].id,m[i].name,m[i].wt,m[i].date);
}}}

void dash(){
  membsort();
  printf("\n=ID=\t=Name=\t=Weight=\t=Days lapsed==");
  if(mcount==0){printf("\nNo members added");}
  int dlim=(mcount<5)?mcount:5;
  for (int j=0; j<dlim; j++){
    printf("\n=%d=\t=%s=\t=%.2f=\t=%d==\n",m[j].id,m[j].name,m[j].wt,m[j].date);
}}

int main(){
  int in;
  while(true){
    printf("====Gym fitness tracker====");
    printf("\n1.Add new member\n2.Display all members\n3.View inactive members\n4.exit\n===========================");
    dash();
    printf("\nEnter Input:");
    scanf("%d",&in);
    
    switch (in){
      case 1:
        admem();
        break;
      case 2:
        viewall();
        break;
      case 3:
        viewinact();
        break;
      case 4:
        return 0;
      default:
        printf("\n!!Please enter valid input!!\n");
        break;
    }

  }


  return 0;
}
