/* 20. Implementation of hashing using separate chaining */
#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
}n;

n* hashTable[TABLE_SIZE];

void initHash() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

int hashKey(long int key) {
    return key % 10;
}

void insertHash(long int key) {
    int index = hashKey(key);
    n* nn = (n*)malloc(sizeof(n));
    nn->data = key;
    nn->next = NULL;

    if (hashTable[index] == NULL) { hashTable[index] = nn;}
    else {
        n* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nn;
    }
    printf("Inserted %ld at index %d\n", key, index);
}

void displayHash() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    initHash();
    int choice;
    long int val;

    while (1) {
        printf("\n1. Insert\n2. Display\n3. Exit\nEnter choice: ");
        if (scanf("%d", &choice) != 1) break;

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%ld", &val);
                insertHash(val);
                break;
            case 2:
                displayHash();
                break;
            case 3:
                return 0;
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
