#include<stdio.h>
int array[20],front=-1,rear=-1;
void enqueue(int n,int size){
    if((rear+1)%size==front){
        printf("overflow\n");
    }
    else if(front==-1&& rear==-1){
        front=rear=0;
        array[rear]=n;
        printf("elements in the queue\n");
        int i=front;
        while(1){
            printf("%d\n", array[i]);
            if(i==rear)
            break;
            i=(i+1)%size;
        }
    }
    else{
        rear=(rear+1)%size;
        array[rear]=n;
        printf("element in queue : \n");
        int i=front;
        while(1){
            printf("%d\n", array[i]);
            if(i==rear)
            break;
            i=(i+1)%size;
        }
    }
}
void dequeue(int size){
    if(front==-1){
        printf("underflow\n");
    }
    else if(front==rear){
        printf("Deleted element ;%d\n",array[front]);
        front=rear=-1;
    }
    else{
        printf("deleted element :%d\n",array[front]);
        front=(front+1)%size;
        printf("element in the queue is\n");
        int i=front;
        while(1){
            printf("%d\n", array[i]);
            if(i==rear)
            break;
            i=(i+1)%size;
        }
    }
    
}
void main(){
    int size,decision=1,choice,num;
    printf("enter maximum size of circular queue : ");
    scanf("%d",&size);
    while(decision==1){
        printf("\nenter 1 for enqueue, 2 for dequeue : ");
        scanf("%d",&choice);
        if(choice==1){
            printf("\nenter the number to insert : ");
            scanf("%d",&num);
            enqueue(num,size);
        }
        else if(choice==2){
            dequeue(size);
        }
        else{
            printf("invalid option\n");
        }
        printf("\ndo you want to continue : enter 1 for yes, 2 for no : ");
        scanf("%d",&decision);
    }   
}