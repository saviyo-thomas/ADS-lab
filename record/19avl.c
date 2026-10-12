/*
ALGORITHM: AVL Tree Operations (Insertion with Rotations)
1. Define Node structure with 'data', 'left' and 'right' pointers, and 'height'.
2. Implement helper functions: Get Height, Balance Factor (height(left) - height(right)).
3. Implement ROTATION functions:
   a. Left Rotate (y):
      - x = y->right, T2 = x->left.
      - x->left = y, y->right = T2.
      - Update heights of y and x. Return x.
   b. Right Rotate (y):
      - x = y->left, T2 = x->right.
      - x->right = y, y->left = T2.
      - Update heights of y and x. Return x.
4. Implement INSERT operation:
   a. Perform standard BST insertion recursively.
   b. Update height of current node.
   c. Calculate Balance Factor.
   d. If unbalanced, apply rotations: LL (Right Rotate), RR (Left Rotate), LR (Left then Right), RL (Right then Left).
5. Display AVL Tree using Inorder/Preorder traversal.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* l;
    int d;
    struct Node* r;
    int height;
} n;

n* h = NULL;

int height(n* node) {
    if (node == NULL)
        return 0;
    return node->height;
}

int maxVal(int a, int b) {
    return (a > b) ? a : b;
}

n* create(int d) {
    n* nn = (n*)malloc(sizeof(n));
    nn->d = d;
    nn->l = NULL;
    nn->r = NULL;
    nn->height = 1;
    return nn;
}

n* rightRotate(n* y) {
    n* x = y->l;
    n* T2 = x->r;

    x->r = y;
    y->l = T2;

    y->height = maxVal(height(y->l), height(y->r)) + 1;
    x->height = maxVal(height(x->l), height(x->r)) + 1;

    return x;
}

n* leftRotate(n* x) {
    n* y = x->r;
    n* T2 = y->l;

    y->l = x;
    x->r = T2;

    x->height = maxVal(height(x->l), height(x->r)) + 1;
    y->height = maxVal(height(y->l), height(y->r)) + 1;

    return y;
}

int htdiff(n* node) {
    if (node == NULL)
        return 0;
    return height(node->l) - height(node->r);
}

n* ins(n* node, int d) {
    if (node == NULL)
        return create(d);

    if (d < node->d)
        node->l = ins(node->l, d);
    else if (d > node->d)
        node->r = ins(node->r, d);
    else
        return node;

    node->height = 1 + maxVal(height(node->l), height(node->r));

    int h_diff = htdiff(node);

    // Left Left Case
    if (h_diff > 1 && d < node->l->d)
        return rightRotate(node);

    // Right Right Case
    if (h_diff < -1 && d > node->r->d)
        return leftRotate(node);

    // Left Right Case
    if (h_diff > 1 && d > node->l->d) {
        node->l = leftRotate(node->l);
        return rightRotate(node);
    }

    // Right Left Case
    if (h_diff < -1 && d < node->r->d) {
        node->r = rightRotate(node->r);
        return leftRotate(node);
    }

    return node;
}

void search(n* root, int k) {
    if (root == NULL) {
        printf("\nKey is not found");
        return;
    }
    if (k == root->d) {
        printf("\nKey is found");
    } else if (k < root->d) {
        search(root->l, k);
    } else {
        search(root->r, k);
    }
}

void inorder(n* root) {
    if (root != NULL) {
        inorder(root->l);
        printf("%d ", root->d);
        inorder(root->r);
    }
}

void preorder(n* root) {
    if (root != NULL) {
        printf("%d ", root->d);
        preorder(root->l);
        preorder(root->r);
    }
}

void postorder(n* root) {
    if (root != NULL) {
        postorder(root->l);
        postorder(root->r);
        printf("%d ", root->d);
    }
}

int main() {
    int ch, data, key;
    
    while(1) {
        printf("\n\n==== AVL Tree Menu =====\n1. Insertion (Auto-Balancing via Rotations)\n2. Search\n3. Traversal\n4. Exit\nEnter your choice: ");
        
        if (scanf("%d", &ch) != 1) break;
        
        switch(ch) {
            case 1:
                printf("\nEnter value to insert: ");
                scanf("%d", &data);
                h = ins(h, data); 
                printf("Inserted and balanced successfully.\n");
                break;
            case 2:
                printf("\nEnter key: ");
                scanf("%d", &key);
                search(h, key);
                break;
            case 3:
                printf("\nInorder Traversal: ");
                inorder(h);
                printf("\n");
                printf("\nPreorder Traversal: ");
                preorder(h);
                printf("\n");
                printf("\nPostorder Traversal: ");
                postorder(h);
                printf("\n");
                break;
            case 4:
                return 0;
            default:
                printf("\nEnter a valid input\n");
        }
    }
    return 0;
}
