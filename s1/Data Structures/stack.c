#include<stdio.h>

int arr[20],n,top=-1;
void push(){
    int item;
    printf("Enter the element to insert:");
    scanf("%d",&item);
    if(top>=n-1){
        printf("stack overflow");
    }
    else{
        top=top+1;
        arr[top]=item;
    }
}

void pop(){
    if(top==-1){
        printf("stack underflow:\n");
    }
    else{
        printf("poped element is :%d \n",arr[top]);
        top--;
    }

}

void display(){
    if(top==-1){
        printf("stack is empty \n");
    }
    int i;
    printf("Stack is :");
    for(i=0;i<=top;i++){
        printf("%d",arr[i]);
    }
}    

int main(){
    int choice;
    printf("enter the size of the stack:\n");
    scanf("%d",&n);

do{
    printf(" 1.push \n 2.pop \n 3.display \n 4.exit \n");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:push();
        break;
    case 2:pop();
        break;    
    case 3:display();
        break;
    case 4:printf("exiting...");
        break;    
    default:
        break;
    }
}while(choice!=4);
}