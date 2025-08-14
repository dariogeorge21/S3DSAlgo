#include<stdio.h>
int que,arr[10],n;
int front=-1,rear=-1,value;
char b;
void enqueue(){
    
    
        if(front==-1 && rear==-1){
        front=0;
        rear=0;
        printf("enter the number to enqueue :");
        scanf("%d", &value);
        arr[rear]=value;
        for(int i=front;i<=rear;i++){
            printf("%d\t",arr[i]);
        }
        printf("\n");
        

    }

    else if(rear==n-1){
        printf("overflow");
        printf("\n");
    }
    else{
        rear++;
        printf("enter the number to enqueue : ");
        scanf("%d", &value);
        arr[rear]=value;
        for(int i=front;i<=rear;i++){
            printf("%d\t",arr[i]);
        }
        printf("\n");
    }
    

}
void dequeue(){
    
    
        if(front==-1 && rear==-1){
        printf("underflow");
        printf("\n");
    }

    else if(front<=rear){
        
        printf("The deleted element = %d", arr[front]);
        front++;
        printf("\n");
        printf("the queue is now = ");
        for(int i=front;i<=rear;i++){
            printf("%d\t",arr[i]);
        }
        printf("\n");
        
    }
    else{
        printf("underflow");
        printf("\n");
    }
    
    }
void display(){
    for(int i=front;i<=rear;i++){
            printf("%d\t",arr[i]);
        }
        printf("\n");
}


int main(){
    int que,arr[10],a,n;
    printf("enter the number of times it should work : ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
    printf("do you want to enqueue or dequeue? for enqueing enter 1, for dequeing enter 2 : ");
    scanf("%d", &a);
    
    if (a==1){
        enqueue();
        }
    else if (a==2)
    {
       dequeue();
    }
    else{
        display();
    }
    
    }
}