#include<stdio.h>
int arr[20],n,i,j;

int bubble(){
    int temp;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
            
        }
    }
}

int selection(){
    int min,t;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++)
        if(arr[j]<arr[min])min=j;
        t=arr[i];
        arr[i]=arr[min];
        arr[min]=t;

    }
}

int display(){
    for(i=0;i<n;i++){
        printf("%d",arr[i]);
    }
}
int main(){

    int choice;
    printf("Ente the size of the array:");
    scanf("%d",&n);
    printf("Enter array elements");
    for(i=0;i<n;i++){
         scanf("%d",&arr[i]);
    }
   
    do{
        printf("1.Bubble sort \n 2.Selection Sort \n 3.exit \n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:bubble();
               display();
            break;
        case 2:selection();
               display();
            break;
        
        case 3:printf("Exitng...");
             break;        
        default:
            break;
        }
    }while(choice!=3);
}