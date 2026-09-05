#include<stdio.h>
#define mx_rs 50
#define mx_cls 50
#define mx_tlen 250


int main(){
  int r,c,size1,size2=0,a[mx_rs][mx_cls], b[3][mx_tlen],count;

    printf("\nEnter Matrix details\nRows: ");
    scanf("%d",&r);
    printf("Columns :");
    scanf("%d",&c);
    size1=r*c;
    printf("\nEnter Matrix elements separated by space (%d no.s)\n",size1);
    for (int i=0; i<r;i++){for (int j=0;j<c;j++){
      scanf("%d",&a[i][j]);
    }}


    for (int i=0; i<r;i++){for (int j=0;j<c;j++){
      if (a[i][j]!=0){
        count++;
    }}}
    if(count>((r*c)/2)){printf("\nThe array input doesn't have majority zeroes\n Not a sparse matrix\n"); return 0;}

    for (int i=0; i<r;i++){for (int j=0;j<c;j++){
      if (a[i][j]!=0){
        b[0][size2]=i;
        b[1][size2]=j;
        b[2][size2]=a[i][j];
        size2++;
      }
    }}


    printf("\nSparse Matrix is represented as follows\n");
    printf("Row:\t");
    for (int j=0;j<size2;j++){
     printf(" [%d]",b[0][j]);
    }printf("\n");
    printf("Column:\t");
    for (int j=0;j<size2;j++){
     printf(" [%d]",b[1][j]);
    }printf("\n");
    printf("Data:\t");
    for (int j=0;j<size2;j++){
     printf(" [%d]",b[2][j]);
    }printf("\n");
 return 0;
}
