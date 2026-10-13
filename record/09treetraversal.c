/*
   ===================================================================
NAME: Saviyo Thomas
ROLL NO: CS11
DATE: 29/07/2026
EXPERIMENT NO: 09

ALGORITHM: Binary Tree Traversals (Preorder, Inorder, Postorder)
1. Define a Node structure representing a binary tree node with 'data', 'left' pointer, and 'right' pointer.
2. Implement INORDER Traversal (Left, Root, Right):
 a. If node is NULL, return.
 b. Recursively call Inorder on left subtree.
 c. Process/print root node data.
 d. Recursively call Inorder on right subtree.
3. Implement PREORDER Traversal (Root, Left, Right):
 a. If node is NULL, return.
 b. Process/print root node data.
 c. Recursively call Preorder on left subtree.
 d. Recursively call Preorder on right subtree.
4. Implement POSTORDER Traversal (Left, Right, Root):
 a. If node is NULL, return.
 b. Recursively call Postorder on left subtree.
 c. Recursively call Postorder on right subtree.
 d. Process/print root node data.
5. Provide a driver main() to build a sample binary tree and execute traversals.
===================================================================
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  struct node* lc;
  struct node* rc;
  int data;
} n;

n* ins(n* h, int d) {
  if (h == NULL) {
    n* nn = (n*)malloc(sizeof(n));
    nn->data = d;
    nn->lc = NULL;
    nn->rc = NULL;
    return nn;
  }
  if (d < h->data) { h->lc = ins(h->lc, d); }
  else if (d > h->data) { h->rc = ins(h->rc, d); }
  return h;
}

n* del(n* h, int d) {
  //node not found
  if (h == NULL) { printf("\nData not found"); return h; }
  if (d < h->data) { h->lc = del(h->lc, d); }
  else if (d > h->data) { h->rc = del(h->rc, d); }

  //node found
  else {
    if (h->lc == NULL) { n* temp = h->rc; free(h); return temp;}
    else if (h->rc == NULL) { n* temp = h->lc; free(h); return temp;}

    n* temp = h->rc;
    while (temp->lc != NULL) { temp = temp->lc; }
    h->data = temp->data;
    h->rc = del(h->rc, temp->data);
  }
  return h;
}

void search(n* h, int d) {
  if (h == NULL) { printf("\nData not found"); return; }
  if (d < h->data) { search(h->lc, d); } 
  else if (d > h->data) { search(h->rc, d); }
  else { printf("\nData found at node with value: %d", h->data); }
}

void inord(n*h){
  if (h==NULL){return;}
  inord(h->lc);
  printf(" %d ",h->data);
  inord(h->rc);
}

void preord(n*h){
  if(h==NULL){return;}
  printf(" %d ",h->data);
  preord(h->lc);
  preord(h->rc);
}

void postord(n*h){
  if(h==NULL){return;}
  postord(h->lc);
  postord(h->rc);
  printf(" %d ",h->data);
}

int main() {
  n* hd = NULL;
  int ch, data;

  while (1) {
    printf("\n\n========Tree=======\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\nChoice: ");
    if(scanf("%d", &ch) != 1) break; 

    switch (ch) {
      case 1: 
        printf("Enter data: ");
        scanf("%d", &data);
        hd = ins(hd, data);
        break;
      case 2: 
        printf("Enter data to be deleted: ");
        scanf("%d", &data);
        hd = del(hd, data);
        break;
      case 3: 
        printf("Enter data to search: ");
        scanf("%d", &data);
        search(hd, data);
        break;
      case 4: 
        printf("Inorder\n ");
        inord(hd);
        printf("\nPreorder\n");
        preord(hd);
        printf("\nPostorder\n");
        postord(hd);

        break;
      case 5: 
        return 0;
      default: 
        printf("Invalid input");
    }
  }
  return 0;
}
