#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Common function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node into BST
struct Node* insertNode(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insertNode(root->left, value);
    else if (value > root->data)
        root->right = insertNode(root->right, value);
    else
        printf("\nDuplicate values not allowed!");
    return root;
}

// Find minimum value node (used in deletion)
struct Node* findMin(struct Node* node) {
    while (node->left != NULL)
        node = node->left;
    return node;
}

// Delete a node from BST
struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        printf("\nValue %d not found in tree.", value);
        return root;
    }

    if (value < root->data)
        root->left = deleteNode(root->left, value);
    else if (value > root->data)
        root->right = deleteNode(root->right, value);
    else {
        // Node found — perform deletion
        if (root->left == NULL) {
            struct Node* temp = root->right;
            printf("\nDeleted node with value %d.", root->data);
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            printf("\nDeleted node with value %d.", root->data);
            free(root);
            return temp;
        }

        // Node with two children
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Inorder traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Preorder traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Postorder traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Display all traversals
void displayTraversals(struct Node* root) {
    if (root == NULL) {
        printf("\nTree is empty.");
        return;
    }
    printf("\nInorder   : ");
    inorder(root);
    printf("\nPreorder  : ");
    preorder(root);
    printf("\nPostorder : ");
    postorder(root);
}

// Main function
int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\n\n--- Binary Search Tree Menu ---");
        printf("\n1. Create Tree (Insert Root)");
        printf("\n2. Insert Node");
        printf("\n3. Delete Node");
        printf("\n4. Display Traversals");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (root != NULL) {
                    printf("\nTree already created!");
                    break;
                }
                printf("Enter root value: ");
                scanf("%d", &value);
                root = createNode(value);
                printf("\nRoot node created with value %d.", value);
                break;
            case 2:
                if (root == NULL) {
                    printf("\nCreate the tree first!");
                    break;
                }
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;
            case 3:
                if (root == NULL) {
                    printf("\nTree is empty!");
                    break;
                }
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                break;
            case 4:
                displayTraversals(root);
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
