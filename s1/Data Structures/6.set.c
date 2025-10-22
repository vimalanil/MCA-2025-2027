#include <stdio.h>
#define SIZE 8   // Universal set size

// Print a set represented by a bit string
void printSet(int set[]) {
    printf("{ ");
    for (int i = 0; i < SIZE; i++) {
        if (set[i] == 1)
            printf("%d ", i);
    }
    printf("}");
}

// Perform Union
void setUnion(int A[], int B[], int U[]) {
    for (int i = 0; i < SIZE; i++)
        U[i] = A[i] | B[i];
}

// Perform Intersection
void setIntersection(int A[], int B[], int I[]) {
    for (int i = 0; i < SIZE; i++)
        I[i] = A[i] & B[i];
}

// Perform Difference (A - B)
void setDifference(int A[], int B[], int D[]) {
    for (int i = 0; i < SIZE; i++)
        D[i] = A[i] & (!B[i]);
}

int main() {
    int A[SIZE], B[SIZE], U[SIZE], I[SIZE], D[SIZE];
    int choice;

    // Input Set A
    printf("Enter elements of Set A (0 or 1 for indices 0 to %d):\n", SIZE - 1);
    for (int i = 0; i < SIZE; i++) {
        printf("A[%d]: ", i);
        scanf("%d", &A[i]);
    }

    // Input Set B
    printf("\nEnter elements of Set B (0 or 1 for indices 0 to %d):\n", SIZE - 1);
    for (int i = 0; i < SIZE; i++) {
        printf("B[%d]: ", i);
        scanf("%d", &B[i]);
    }

    // Menu-driven operations
    do {
        printf("\n\n--- Set Operations Menu ---");
        printf("\n1. Display Set A");
        printf("\n2. Display Set B");
        printf("\n3. Union (A ∪ B)");
        printf("\n4. Intersection (A ∩ B)");
        printf("\n5. Difference (A - B)");
        printf("\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Set A = ");
                printSet(A);
                printf("\n");
                break;

            case 2:
                printf("Set B = ");
                printSet(B);
                printf("\n");
                break;

            case 3:
                setUnion(A, B, U);
                printf("A ∪ B = ");
                printSet(U);
                printf("\n");
                break;

            case 4:
                setIntersection(A, B, I);
                printf("A ∩ B = ");
                printSet(I);
                printf("\n");
                break;

            case 5:
                setDifference(A, B, D);
                printf("A - B = ");
                printSet(D);
                printf("\n");
                break;

            case 6:
                printf("\nExiting program...");
                break;

            default:
                printf("\nInvalid choice! Please try again.");
        }
    } while (choice != 6);

    return 0;
}
