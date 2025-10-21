#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* root = NULL;

struct Node* creation(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertion(struct Node* root , int value){
    if( root == NULL){
        return  creation(value); 
    }
    if(root->left == NULL){
        root->left = insertion(root->left , value);
    }
    else if(root->right == NULL){
        root->right = insertion(root->right , value);
    }
    else{
        root->left = insertion(root->left , value);
    }
    return root;
}

void inorderTraversal(struct Node* root){
    if(root == NULL)return;
    inorderTraversal(root->left);
    printf("%d ",root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(struct Node* root){
    if(root == NULL)return;
    preorderTraversal(root->left);
    preorderTraversal(root->right);
    printf("%d ",root->data);
}

void postOrderTraversal(struct Node* root){
    if(root == NULL)return;
    printf("%d ",root->data);
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return NULL;

    if (root->left == NULL && root->right == NULL) {
        if (root->data == key) {
            free(root);
            return NULL;
        } else {
            return root;
        }
    }

    struct Node* key_node = NULL;
    struct Node* temp = NULL;
    struct Node* last_parent = NULL;
    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        temp = queue[front++];

        if (temp->data == key) {
            key_node = temp;
        }

        if (temp->left) {
            last_parent = temp;
            queue[rear++] = temp->left;
        }
        if (temp->right) {
            last_parent = temp;
            queue[rear++] = temp->right;
        }
    }

    if (key_node != NULL) {
        // Replace key_node data with deepest node data (temp is deepest node)
        key_node->data = temp->data;

        // Delete deepest node
        if (last_parent->right == temp) {
            free(temp);
            last_parent->right = NULL;
        } else if (last_parent->left == temp) {
            free(temp);
            last_parent->left = NULL;
        }
    } else {
        printf("Node with value %d not found.\n", key);
    }

    return root;
}


int main(){
    int value,choice;
    do{
        printf("\n --- Binary Tree --- \n");
        printf("1.insertion \n 2.Inorder \n 3.preorder \n 4.postorder \n 5.exit");
        scanf("%d",&choice);

        switch(choice){
            case 1: printf("Enter value: \n");
                    scanf("%d",&value);
                    root = insertion(root , value);
                    break;
            
            case 2: printf("Display :\n");
                    inorderTraversal(root);   
                    break; 
                    
            case 3: printf("Display :\n");
                    preorderTraversal(root);   
                    break; 
                    
            case 4: printf("Display :\n");
                    postOrderTraversal(root);   
                    break;  
                    
            case 5: printf("Enter value: \n");
                    scanf("%d",&value);
                    deleteNode(root , value);
                    break;    

            case 6: printf("exiting");
                    break;
                    
            default: printf("Invalid choice");        
        }
    }while(choice != 6);
}