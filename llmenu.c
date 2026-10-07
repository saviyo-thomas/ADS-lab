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
    printf("Inserted %d at the beginning.", val);
}

void insertAtEnd(int val) {
    n* newNode = (n*)malloc(sizeof(n));
    newNode->data = val;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
        printf("Inserted %d as the first element.", val);
        return;
    }
    n* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    printf("Inserted %d at the end.", val);
}

void insertAtPosition(int val, int pos) {
    if (pos < 1) { printf("Invalid position!"); return; }
    if (pos == 1) { insertAtBeginning(val); return;}
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    struct Node* temp = head;
    for (int i = 1; temp != NULL && i < pos - 1; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Position out of bounds!"); free(newNode); return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    printf("Inserted %d at position %d.", val, pos);}

void deleteNode(int val) {
    if (head == NULL) {
        printf("List is empty."); return; }
    n *temp = head, *prev = NULL;
    if (temp != NULL && temp->data == val) {
        head = temp->next;
        free(temp);
        printf("Deleted %d from the list.", val);
        return;
    }
    while (temp != NULL && temp->data != val) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Element %d not found in the list.", val); return; }
    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.", val);
}

void display() {
    if (head == NULL) {
       printf("List is empty.");
        return;
    }
    struct Node* temp = head;
    printf("Linked List: ");
    printf("\nLinked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main() {
    int choice, val, pos;
    while (1) {
        printf("\n--- Linked List Operations Menu ---\n1. Insert at Beginning\n2. Insert at End\n3. Insert In Between (at Position\n4. Delete a Node\n5. Display\n6. Exit\nEnter your choice: ");
        if (scanf("%d", &choice) != 1) return 0;

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                if (scanf("%d", &val) == 1) insertAtBeginning(val);
                break;
            case 2:
                printf("Enter value to insert at end: ");
                if (scanf("%d", &val) == 1) insertAtEnd(val);
                break;
            case 3:
                printf("Enter value to insert: ");
                if (scanf("%d", &val) == 1) {
                    printf("Enter 1-based position (e.g. 2 to insert after head): ");
                    if (scanf("%d", &pos) == 1) {
                        insertAtPosition(val, pos);
                    }
                }
                break;
            case 4:
                printf("Enter value to delete: ");
                if (scanf("%d", &val) == 1) deleteNode(val);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice. Please try again.");
        }
    }
    return 0;
}
