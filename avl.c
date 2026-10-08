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

int getBalance(n* node) {
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

    int balance = getBalance(node);

    // Left Left Case
    if (balance > 1 && d < node->l->d)
        return rightRotate(node);

    // Right Right Case
    if (balance < -1 && d > node->r->d)
        return leftRotate(node);

    // Left Right Case
    if (balance > 1 && d > node->l->d) {
        node->l = leftRotate(node->l);
        return rightRotate(node);
    }

    // Right Left Case
    if (balance < -1 && d < node->r->d) {
        node->r = rightRotate(node->r);
        return leftRotate(node);
    }

    return node;
}

void ser(n* root, int k) {
    if (root == NULL) {
        printf("\nKey is not found");
        return;
    }
    if (k == root->d) {
        printf("\nKey is found");
    } else if (k < root->d) {
        ser(root->l, k);
    } else {
        ser(root->r, k);
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
        printf("\n\n==== AVL Tree Menu =====\n");
        printf("1. Insertion (Auto-Balancing via Rotations)\n");
        printf("2. Search\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
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
                ser(h, key);
                break;
            case 3:
                printf("\nInorder Traversal: ");
                inorder(h);
                printf("\n");
                break;
            case 4:
                printf("\nPreorder Traversal: ");
                preorder(h);
                printf("\n");
                break;
            case 5:
                printf("\nPostorder Traversal: ");
                postorder(h);
                printf("\n");
                break;
            case 6:
                return 0;
            default:
                printf("\nEnter a valid input\n");
        }
    }
    return 0;
}