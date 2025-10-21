#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

void createNode(int value){

}
void insertbegin(int value){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
}

void insertEnd(int value){
    struct Node* newNode = ( struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if(head == NULL){
        newNode->prev =NULL; 
        head = newNode;
    }
    
    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteBegin(){
    if(head == NULL){
        printf("List is empty");
        return;
    }

    struct Node* temp = head;
    head = temp->next;
    if(head != NULL){
        head->prev = NULL;
    }
    free(temp);
}

void deleteEnd(){
    if(head == NULL){
        printf("List is Empty");
        return;
    }

    struct Node* temp = head;

    if(temp->next == NULL){
        head = NULL;
        free(temp);
        return;
    }

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
}

void forwardTraverse(){
    struct Node* temp = head;
    if(head == NULL){
        printf("List is empty");
        return;
    }
    while(temp != NULL){
        printf("%d ",temp->data );
        temp = temp->next;
    }
    printf("\n");

}

void backWardTraverse(){
    struct Node* temp = head;
    if(head == NULL){
        printf("List is empty");
        return;
    }
    while(temp->next     != NULL){
        temp = temp->next;
    }
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

void count(){
    int count = 0;
    if(head == NULL){
        printf("List is Empty");
        return;
    }

    struct Node* temp = head;

    while(temp != NULL){
        temp = temp->next;
        count++;
    }
    printf("Number Elements on list is %d",count);
}

int main(){
    int value,choice;
    do{
        printf("---Doubly Linkedlist Operatons");
        printf("\n 1.insertbegin \n 2.insertEnd \n 3.deleteBegin \n 4.delteEnd \n 5.forwardtraverse \n 6.backwardtravese \n 7.count \n 8.exit \n");
        printf("Enter the choice:\n");
        scanf("%d",&choice);

        switch(choice){
            case 1: printf("Enter value to insert :\n");
                    scanf("%d",&value);
                    insertbegin(value);
                    break;

            case 2: printf("enter the value to insert :\n");
                    scanf("%d",&value);
                    insertEnd(value);
                    break;
                    
            case 3: deleteBegin();
                    break;
                   
            case 4: deleteEnd();
                    break;
                   
            case 5: forwardTraverse();
                    break;

            case 6: backWardTraverse();
                    break;       

            case 7: count();
                    break;
                   
            case 8: printf("Exiting from the program ...\n");
                    break;

            default : printf("Invalid Input:\n");
                      break;       

        }
    }while(choice!=8);
}