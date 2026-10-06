#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}n;

n* head = NULL;

void insertAtBeginning(int val) {
    n* newNode = (n*)malloc(sizeof(n));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    printf("\nInserted %d at the beginning.", val);
}

void insertAtEnd(int val) {
    n* newNode = (n*)malloc(sizeof(n));
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        printf("\nInserted %d as the first element.", val);
        return;
    }
    n* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("\nInserted %d at the end.", val);
}

void deleteNode(int val) {
    if (head == NULL) {
        printf("\nList is empty.");
        return;
    }
    n *temp = head, *prev = NULL;
    if (temp != NULL && temp->data == val) {
        head = temp->next;
        free(temp);
        printf("\nDeleted %d from the list.", val);
        return;
    }
    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nElement %d not found in the list.", val);
        return;
    }
    prev->next = temp->next;
    free(temp);
    printf("\nDeleted %d from the list.", val);
}

void display() {
    if (head == NULL) {
        printf("\nList is empty.");
        return;
    }
    n* temp = head;
    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, val;
    while (1) {
        printf("\n\n--- Linked List Operations Menu ---");
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Delete a Node");
        printf("\n4. Display");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) return 0;

        switch (choice) {
            case 1:
                printf("\nEnter value to insert at beginning: ");
                if (scanf("%d", &val) == 1) insertAtBeginning(val);
                break;
            case 2:
                printf("\nEnter value to insert at end: ");
                if (scanf("%d", &val) == 1) insertAtEnd(val);
                break;
            case 3:
                printf("\nEnter value to delete: ");
                if (scanf("%d", &val) == 1) deleteNode(val);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.");
        }
    }
    return 0;
}
