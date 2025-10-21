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
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertion( struct Node* root , int value){
    if ( root == NULL ){
        return creation(value);
    }
    if( root->left == NULL ){
        root->left = insertion(root->left , value);
    } 
    else if ( root->right == NULL){
        root->left = insertion(root->right , value);
    }
    else{
        root->right = insertion(root->left , value);
    }
    return root;
}

void inorderTraversal(struct Node* root){
    if( root == NULL)return;

    inorderTraversal( root->left);
    printf("%d",root->data);
    inorderTraversal( root->right);
}

int main(){
    int value,choice;
    do{
        printf("\n=== Binary Tree Operations ===\n");
        printf("1.insert \n 2.delete \n 3.traverse \n");
        printf("Enter your choice :");
        scanf("%d",&choice);

        switch(choice){

            case 1: printf("Enter the value to insert :\n");
                    scanf("%d",&value);
                    root = insertion( root , value );
                    break;

            // case 2: printf("Enter the value to delete :\n");
            //         scanf("%d",&value);
            //         delete(value);
            //         break;
                    
            case 3: inorderTraversal(root);
                    break;
                    
            case 4: printf("Exiting ...");
                    break;
                    
            default: printf("Invalid choice !");
                     break;

        }
    }while(choice != 4);
}
