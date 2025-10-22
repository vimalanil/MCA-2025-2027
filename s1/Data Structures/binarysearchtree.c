#include <stdio.h>
#include <stdlib.h>

// --- Node Structure ---
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

    if(root == NULL)
        return createNode(data);

    if (data < root->data)
// --- Utility Functions ---

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to find the minimum value node in a subtree (used for deletion)
struct Node* findMin(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// --- Core BST Operations ---

// 1. Insert a node
struct Node* insert(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    // Optional: handle duplicates
    // else
    //    printf("Duplicate value %d ignored.\n", data);

    return root;
}

// 2. Search a node
struct Node* search(struct Node* root, int key) {
    // Base Case: Root is null (not found) or key is present at root
    if (root == NULL || root->data == key)
        return root;

    // Key is smaller than root's data, search left subtree
    if (key < root->data)
        return search(root->left, key);

    // Key is larger than root's data, search right subtree
    return search(root->right, key);
}

// 3. Delete a node
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root; // Key not found

    // Traverse to find the node
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node found: Handle deletion based on children count

        // Case 1 & 2: Node with one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node with two children
        // Find the in-order successor (smallest in the right subtree)
        struct Node* temp = findMin(root->right);

        // Copy the successor's content to this node
        root->data = temp->data;

        // Delete the successor node from the right subtree
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// --- Traversal Operations ---

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// --- Main Menu Function ---
int main() {
    struct Node* root = NULL;
    int choice, value;

    do {
        printf("\n\n--- Binary Search Tree Operations ---\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Inorder Traversal (Sorted)\n");
        printf("5. Preorder Traversal\n");
        printf("6. Postorder Traversal\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Value %d inserted.\n", value);
                break;

            case 2:
                printf("Enter value to search: ");
                scanf("%d", &value);
                if (search(root, value))
                    printf("✅ Value %d found in BST.\n", value);
                else
                    printf("❌ Value %d not found in BST.\n", value);
                break;
            
            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = deleteNode(root, value);
                printf("Attempted to delete value %d.\n", value);
                break;

            case 4:
                printf("Inorder traversal: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Preorder traversal: ");
                preorder(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder traversal: ");
                postorder(root);
                printf("\n");
                break;

            case 0:
                printf("Exiting program. Goodbye!\n");
                // In a production application, memory cleanup (freeing all nodes) would go here.
                break;

            default:
                printf("Invalid choice! Please enter a number between 0 and 6.\n");
        }
    } while(choice != 0);

    return 0;
}