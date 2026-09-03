#include<stdio.h>
#define mx_sz 100

typedef struct Node{
    int row;
    int col;
    int val;
    struct Node* next;
}N;

int a[mx_sz][mx_sz];

int main(){
    int r, c, i, j, count = 0;
    N* hd = NULL;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &r, &c);

    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < r; i++){
        for(j = 0; j < c; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < r; i++){for (j = 0; j < c; j++)
        {
            if(a[i][j] != 0){
                count++;
            }
        }
    }
    for (i = 0; i < count; i++)
    {
        if(a[i][j] != 0){
            N* nn = (N*)malloc(sizeof(N));
            nn->row = i;
            nn->col = j;
            nn->val = a[i][j];
            nn->next = hd;
            hd = nn;
        }
    }
    printf("The sparse matrix representation is:\n");
    N* temp = hd;
    while(temp != NULL){    
        printf("Row: %d, Column: %d, Value: %d\n", temp->row, temp->col, temp->val);
        temp = temp->next;
    }
    return 0;
}

