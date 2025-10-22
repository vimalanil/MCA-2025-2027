#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int value) {
    struct Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    printf("\nInserted %d at beginning.", value);
}

// Insert at end
void insertAtEnd(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("\nInserted %d at end.", value);
}

// Delete from beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("\nList is empty.");
        return;
    }
    struct Node *temp = head;
    head = head->next;
    printf("\nDeleted %d from beginning.", temp->data);
    free(temp);
}

// Delete from end
void deleteFromEnd() {
    if (head == NULL) {
        printf("\nList is empty.");
        return;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    if (prev == NULL) {  // only one node
        head = NULL;
    } else {
        prev->next = NULL;
    }
    printf("\nDeleted %d from end.", temp->data);
    free(temp);
}

// Delete by value
void deleteByValue(int value) {
    if (head == NULL) {
        printf("\nList is empty.");
        return;
    }
    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nValue %d not found.", value);
        return;
    }

    if (prev == NULL)
        head = head->next;
    else
        prev->next = temp->next;

    printf("\nDeleted node with value %d.", value);
    free(temp);
}

// Display forward
void displayForward() {
    struct Node *temp = head;
    if (temp == NULL) {
        printf("\nList is empty.");
        return;
    }
    printf("\nList (Forward): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

// Display backward (recursive)
void displayBackward(struct Node *node) {
    if (node == NULL) return;
    displayBackward(node->next);
    printf("%d -> ", node->data);
}

// Count nodes
void countNodes() {
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("\nTotal nodes: %d", count);
}

// Main function
int main() {
    int choice, value;
    do {
        printf("\n\n--- Single Linked List Menu ---");
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Delete from Beginning");
        printf("\n4. Delete from End");
        printf("\n5. Delete by Value");
        printf("\n6. Display Forward");
        printf("\n7. Display Backward");
        printf("\n8. Count Nodes");
        printf("\n9. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                deleteFromBeginning();
                break;
            case 4:
                deleteFromEnd();
                break;
            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteByValue(value);
                break;
            case 6:
                displayForward();
                break;
            case 7:
                printf("\nList (Backward): ");
                displayBackward(head);
                printf("NULL");
                break;
            case 8:
                countNodes();
                break;
            case 9:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice. Try again.");
        }
    } while (choice != 9);
    return 0;
}
