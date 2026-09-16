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
  if (d < h->data) {
    h->lc = ins(h->lc, d);
  } else if (d > h->data) {
    h->rc = ins(h->rc, d);
  }
  return h;
}

n* del(n* h, int d) {
  if (h == NULL) {
    printf("\nData not found");
    return h;
  }
  
  if (d < h->data) {
    h->lc = del(h->lc, d);
  } else if (d > h->data) {
    h->rc = del(h->rc, d);
  } else {
    // Node to be deleted found
    if (h->lc == NULL) {
      n* temp = h->rc;
      free(h);
      return temp;
    } else if (h->rc == NULL) {
      n* temp = h->lc;
      free(h);
      return temp;
    }
    
    // Node with two children: Get inorder successor
    n* temp = h->rc;
    while (temp->lc != NULL) {
      temp = temp->lc;
    }
    h->data = temp->data;
    h->rc = del(h->rc, temp->data);
  }
  return h;
}

void search(n* h, int d) {
  if (h == NULL) {  
    printf("\nData not found");
    return;
  }
  if (d < h->data) {
    search(h->lc, d);
  } else if (d > h->data) {
    search(h->rc, d);
  } else {
    printf("\nData found at node with value: %d", h->data);
  }
}

void display(n* h, int space) {
  // Base case
  if (h == NULL) {
    return;
  }
  
  // Increase distance between levels (5 spaces per level)
  space += 5;
  
  // 1. Process right child first (prints at the top of the terminal)
  display(h->rc, space);
  
  // 2. Print current node after printing spaces
  printf("\n");
  for (int i = 5; i < space; i++) {
    printf(" ");
  }
  printf("%d\n", h->data);
  
  // 3. Process left child (prints at the bottom of the terminal)
  display(h->lc, space);
}

int main() {
  n* hd = NULL;
  int ch, data;
  
  while (1) {
    printf("\n\n========Tree=======\n1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\nChoice: ");
    if(scanf("%d", &ch) != 1) break; // Basic input validation
    
    switch (ch) {
      case 1: 
        printf("Enter data: ");
        scanf("%d", &data);
        hd = ins(hd, data); // Capture returned pointer
        break;
      case 2: 
        printf("Enter data to be deleted: ");
        scanf("%d", &data);
        hd = del(hd, data); // Capture returned pointer
        break;
      case 3: 
        printf("Enter data to search: ");
        scanf("%d", &data);
        search(hd, data);
        break;
      case 4: 
        printf("The tree is: ");
        display(hd);
        break;
      case 5: 
        return 0;
      default: 
        printf("Invalid input");
    }
  }
  return 0;
}
