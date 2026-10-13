/*
===================================================================
NAME: Saviyo Thomas
ROLL NO: CS11
DATE: 29/07/2026
EXPERIMENT NO: 09

ALGORITHM: Binary Search Tree Operations with Traversals
1. Define a Node structure with 'data', 'left' (lc) and 'right' (rc) pointers.
2. Implement INSERT operation:
 a. If tree is empty, create new node and return it.
 b. If data is less than current node's data, recursively insert in left subtree.
 c. If data is greater, recursively insert in right subtree.
3. Implement DELETE operation:
 a. If key is smaller/larger, recurse left/right.
 b. If found with 0/1 child, replace with non-null child and free node.
 c. If two children, replace with inorder successor (smallest in right subtree) and delete successor.
4. Implement SEARCH operation to recursively find key and report found/not found.
5. Implement INORDER (Left, Root, Right), PREORDER (Root, Left, Right) and POSTORDER (Left, Right, Root) traversals recursively.
6. Provide a menu-driven main() to insert, delete, search, display traversals and exit.
===================================================================
SOURCE CODE: Binary Search Tree Operations with Traversals
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

/*
   ===================================================================

   OUTPUT

   CS2024PG01@csserver:~/pg2026/ads/ADS-lab/record$ ./a.out

   ========Tree=======
   1.Insert
   2.Delete
   3.Search
   4.Display
   5.Exit
   Choice: 1
   Enter data: 50

   ========Tree=======
   1.Insert
   2.Delete
   3.Search
   4.Display
   5.Exit
   Choice: 1
   Enter data: 30

   ========Tree=======
   1.Insert
   2.Delete
   3.Search
   4.Display
   5.Exit
   Choice: 1
   Enter data: 70

   ========Tree=======
   1.Insert
   2.Delete
   3.Search
   4.Display
   5.Exit
   Choice: 1
   Enter data: 20

   ========Tree=======
   1.Insert
   2.Delete
   3.Search
   4.Display
   5.Exit
   Choice: 1
   Enter data: 40

   ========Tree=======
   1.Insert
   2.Delete
   3.Search
   4.Display
   5.Exit
   Choice: 1
   Enter data: 60

   ========Tree=======
   1.Insert
   2.Delete
   3.Search
   4.Display
   5.Exit
   Choice: 1
   Enter data: 80

   ========Tree=======
   1.Insert
   2.Delete
   3.Search
   4.Display
   5.Exit
   Choice: 4
   Inorder
    20  30  40  50  60  70  80
   Preorder
    50  30  20  40  70  60  80
   Postorder
    20  40  30  60  80  70  50

   ========Tree=======
   1.Insert
   2.Delete
   3.Search
   4.Display
   5.Exit
   Choice: 3
   Enter data to search: 40

   Data found at node with value: 40

   ========Tree=======
   1.Insert
   2.Delete
   3.Search
   4.Display
   5.Exit
   Choice: 3
   Enter data to search: 100

   Data not found

   ========Tree=======
   1.Insert
   2.Delete
   3.Search
   4.Display
   5.Exit
   Choice: 2
   Enter data to be deleted: 20

   ========Tree=======
   1.Insert
   2.Delete
   3.Search
   4.Display
   5.Exit
   Choice: 4
   Inorder
    30  40  50  60  70  80
   Preorder
    50  30  40  70  60  80
   Postorder
    40  30  60  80  70  50

   ========Tree=======
   1.Insert
   2.Delete
   3.Search
   4.Display
   5.Exit
   Choice: 5
*/
