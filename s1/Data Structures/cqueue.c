
#include<stdio.h>
#include<stdlib.h>

#define SIZE 5
int cqueue[SIZE];
int front = -1;
int rear = -1;

void enqueue( int value ){
    if((rear+1) % SIZE == front){
        printf("Queue is Full");
        return;
    }
    if(front == -1){
        front = 0;
        rear = 0;
    } else {
        rear = (rear+1)%SIZE ;
    }
    cqueue[rear] = value;
}

void dequeue(){
    if(front == -1){
        printf("Queue is empty \n");
        return;
    } 
        printf("%d Delete \n",cqueue[front]);
        if(front == rear){
            front = -1;
            rear = -1;
        } else {
            front = (front+1)%SIZE;
        }

}

void count() {
    int cnt;
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }

    if (rear >= front) {
        cnt = rear - front + 1;
    } else {
        cnt = SIZE - front + rear + 1;
    }

    printf("Number of elements in the queue: %d\n", cnt);
}

void display(){
    if(front == -1){
        printf("Queue is empty \n");
        return;
    }
    printf("Queue Elements :");
    int i = front;
    while (1) {
        printf("%d ", cqueue[i]);
        if (i == rear)
            break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main(){
    int choice,value;
    do{
        printf("\n--- Queue Operations ---\n");
        printf("\n 1.Enqueue \n 2. Dequeue \n 3.count \n 4.display \n");
        printf("Enter your choice :\n");
        scanf("%d",&choice);

        switch(choice){
            case 1: printf("Enter the value to insert :\n ");
                    scanf("%d",&value);
                    enqueue(value);
                    break;

            case 2: dequeue();
                    break;
                    
            case 3: count();
                    break;
                    
            case 4: display();
                    break;
                    
            case 5: printf("exiting ... ");
                    break;
              
            default: printf("Invalid input !");
                     break;        
        }
    }while(choice != 5);
}