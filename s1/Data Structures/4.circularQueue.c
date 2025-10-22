#include <stdio.h>
#include <stdlib.h>
#define SIZE 5  // You can change the queue size here

int queue[SIZE];
int front = -1, rear = -1, count = 0;

// Function to insert element into circular queue
void enqueue(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("\nQueue is FULL. Cannot insert %d.", value);
        return;
    }
    if (front == -1)
        front = 0;
    rear = (rear + 1) % SIZE;
    queue[rear] = value;
    count++;
    printf("\nInserted %d into the queue.", value);
}

// Function to delete element from circular queue
void dequeue() {
    if (front == -1) {
        printf("\nQueue is EMPTY. Cannot delete.");
        return;
    }
    printf("\nDeleted element: %d", queue[front]);
    if (front == rear) {
        front = rear = -1;  // Queue becomes empty
    } else {
        front = (front + 1) % SIZE;
    }
    count--;
}

// Function to display the queue
void display() {
    if (front == -1) {
        printf("\nQueue is EMPTY.");
        return;
    }
    printf("\nQueue elements: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
}

// Function to count the number of elements
void countElements() {
    printf("\nTotal elements in queue: %d", count);
}

// Main function
int main() {
    int choice, value;

    do {
        printf("\n\n--- Circular Queue Menu ---");
        printf("\n1. Enqueue (Insert)");
        printf("\n2. Dequeue (Delete)");
        printf("\n3. Display Queue");
        printf("\n4. Count Elements");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                countElements();
                break;
            case 5:
                printf("\nExiting program...");
                break;
            default:
                printf("\nInvalid choice! Try again.");
        }
    } while (choice != 5);

    return 0;
}
