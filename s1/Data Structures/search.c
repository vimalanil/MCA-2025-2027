#include<stdio.h>
int n,a[20],i;

int binary(){
    int low=0,high=n-1,mid,num;
    printf("Enter the key:");
    scanf("%d",&num);
    for(i=0;i<n;i++){
        mid=(low+high)/2;
        if(num==a[mid]){printf("Number %d is Found at position %d",a[mid],mid+1);break;}
        else if(num<a[mid]){high=mid-1;}
        else if(num>a[mid]){low=mid+1;}
        else{printf("Number Not Found:");}
    }

}

int display(){
    for(i=0;i<n;i++){
        printf("%d",a[i]);
    }
}

int main(){
    int choice;
    printf("enter the number of elements:");
    scanf("%d",&n);
    printf("Enter the elements of sorted array:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
     do{
        printf("1.Binary Search \n 2.Linear Search \n 3.exit \n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:binary();
            break;
        // case 2:selection();
        //        display();
        //     break;
        
        case 3:printf("Exitng...");
             break;        
        default:
            break;
        }
    }while(choice!=3);
}