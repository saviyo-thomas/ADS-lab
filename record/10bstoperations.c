#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* l;
    int d;
    struct Node* r;
} n;

n* h = NULL;

n* create(int d) {
    n* nn = (n*)malloc(sizeof(n));
    nn->d = d;
    nn->l = NULL;
    nn->r = NULL;
    return nn;
}

n* ins(n* root, int d) {
    if (root == NULL) {
        return create(d);
    }
    if (d < root->d) {
        root->l = ins(root->l, d);
    } else if (d > root->d) {
        root->r = ins(root->r, d);
    }
    return root;
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

// 1. Inorder Traversal (Left, Root, Right)
void inorder(n* root) {
    if (root != NULL) {
        inorder(root->l);
        printf("%d ", root->d);
        inorder(root->r);
    }
}

// 2. Preorder Traversal (Root, Left, Right)
void preorder(n* root) {
    if (root != NULL) {
        printf("%d ", root->d);
        preorder(root->l);
        preorder(root->r);
    }
}

// 3. Postorder Traversal (Left, Right, Root)
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
        printf("\n\n==== BST Menu =====\n");
        printf("1. Insertion\n");
        printf("2. Search\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &ch) != 1) break;
        
        switch(ch) {
            case 1: {
                printf("\nEnter value to insert: ");
                scanf("%d", &data);
                h = ins(h, data); 
                break;
            }
            case 2: {
                printf("\nEnter key: ");
                scanf("%d", &key);
                ser(h, key);
                break;
            }
            case 3: {
                printf("\nInorder Traversal: ");
                inorder(h);
                printf("\n");
                break;
            }
            case 4: {
                printf("\nPreorder Traversal: ");
                preorder(h);
                printf("\n");
                break;
            }
            case 5: {
                printf("\nPostorder Traversal: ");
                postorder(h);
                printf("\n");
                break;
            }
            case 6: 
                return 0;
            default: 
                printf("\nEnter a valid input");
        }
    }
    return 0;
}