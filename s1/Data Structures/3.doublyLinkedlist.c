#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *tail = NULL;

// Common function for creating a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("\nMemory allocation failed!");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("\nInserted %d at beginning.", value);
}

// Insert at end
void insertAtEnd(int value) {
    struct Node *newNode = createNode(value);
    if (tail == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
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
    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }
    printf("\nDeleted %d from beginning.", temp->data);
    free(temp);
}

// Delete from end
void deleteFromEnd() {
    if (tail == NULL) {
        printf("\nList is empty.");
        return;
    }
    struct Node *temp = tail;
    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
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
    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("\nValue %d not found.", value);
        return;
    }

    if (temp == head)
        head = head->next;
    if (temp == tail)
        tail = tail->prev;
    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("\nDeleted node with value %d.", value);
    free(temp);
}

// Display from beginning
void displayFromBeginning() {
    if (head == NULL) {
        printf("\nList is empty.");
        return;
    }
    struct Node *temp = head;
    printf("\nList (Forward): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

// Display from end
void displayFromEnd() {
    if (tail == NULL) {
        printf("\nList is empty.");
        return;
    }
    struct Node *temp = tail;
    printf("\nList (Backward): ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL");
}

// Count number of elements
void countNodes() {
    int count = 0;
    struct Node *temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("\nTotal number of nodes: %d", count);
}

// Main menu
int main() {
    int choice, value;

    do {
        printf("\n\n--- Doubly Linked List Menu ---");
        printf("\n1. Insert at Beginning");
        printf("\n2. Insert at End");
        printf("\n3. Delete from Beginning");
        printf("\n4. Delete from End");
        printf("\n5. Delete by Value");
        printf("\n6. Display from Beginning");
        printf("\n7. Display from End");
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
                displayFromBeginning();
                break;
            case 7:
                displayFromEnd();
                break;
            case 8:
                countNodes();
                break;
            case 9:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice! Try again.");
        }
    } while (choice != 9);

    return 0;
}
