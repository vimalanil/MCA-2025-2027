#include <stdio.h>
#define MAX 100

int parent[MAX];
int rank[MAX];
int n;  // Number of elements

void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
    printf("Disjoint sets created for elements 0 to %d.\n", n-1);
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);  // Path compression
    }
    return parent[x];
}

void unionSets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);

    if (rootX == rootY) {
        printf("Elements %d and %d are already in the same set.\n", x, y);
        return;
    }

    if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
    } else if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
    } else {
        parent[rootY] = rootX;
        rank[rootX]++;
    }
    printf("Union done: %d and %d are now in the same set.\n", x, y);
}

int main() {
    int choice, x, y;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    makeSet(n);

    while (1) {
        printf("\n--- Disjoint Set Menu ---\n");
        printf("1. Union\n");
        printf("2. Find\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter two elements to union (0 to %d): ", n-1);
                scanf("%d %d", &x, &y);
                if (x >= 0 && x < n && y >= 0 && y < n) {
                    unionSets(x, y);
                } else {
                    printf("Invalid elements! Please enter values between 0 and %d.\n", n-1);
                }
                break;

            case 2:
                printf("Enter element to find its set representative (0 to %d): ", n-1);
                scanf("%d", &x);
                if (x >= 0 && x < n) {
                    int parentX = find(x);
                    printf("Representative of element %d is %d.\n", x, parentX);
                } else {
                    printf("Invalid element! Please enter a value between 0 and %d.\n", n-1);
                }
                break;

            case 3:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
