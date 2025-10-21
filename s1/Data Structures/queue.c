#include<stdio.h>
int arr[20],n,i,front=-1,rear=-1;
int enque(){
    int vul;
 if(rear==n-1){
    printf("queue is full"); 
}
else{
    printf("enter the value to insert");
    scanf("%d",&vul);
    if(front==-1)front=front+1;
    rear = rear+1;
    arr[rear]=vul;
}}

int deque(){
    if(front==-1 || front > rear)printf("Queue is underflow");
    printf("deleted element:%d",arr[front++]);

}
int display(){
    if(front==-1 || front > rear)printf("Queue is empty");
    else{
        printf("Queue is :");
        for(i=front;i<=rear;i++){
            printf("%d",arr[i]);
        }
    }
}
int main(){

    int choice;
    printf("Ente the size of the queue:");
    scanf("%d",&n);
    do{
        printf("1.enqueue \n 2.dequeue \n 3.display \n 4.exit");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:enque();
            break;
        case 2:deque();
            break;
        case 3:display();
            break;
        case 4:printf("Exitng...");        
        default:
            break;
        }
    }while(choice!=4);
}