#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;

void push(int val) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

void pop() {
    if (!top) printf("Stack Underflow\n");
    else {
        printf("Popped: %d\n", top->data);
        struct Node* temp = top;
        top = top->next;
        free(temp);
    }
}

void display() {
    if (!top) printf("Stack Empty\n");
    else {
        struct Node* temp = top;
        printf("Stack: ");
        while (temp) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int ch, val;
    do {
        printf("\n--- Stack Menu ---\n1. Push\n2. Pop\n3. Display\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Enter value: "); scanf("%d", &val); push(val); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: break;
            default: printf("Invalid choice\n");
        }
    } while (ch != 4);
    return 0;
}
