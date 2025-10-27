#include<stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;
int count = 0;  // Track number of elements

int isFull(){
    return (count == SIZE);
}

int isEmpty(){
    return (count == 0);
}

void enqueue(int data){
    if(isFull()){
        printf("Queue is full!\n");
        return;
    }
    
    if(isEmpty()){
        front = rear = 0;
    }
    else{
        rear = (rear + 1) % SIZE;
    }
    
    queue[rear] = data;
    count++;
    printf("Inserted: %d\n", data);
}

void dequeue(){
    if(isEmpty()){
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Deleted: %d\n", queue[front]);
    front = (front + 1) % SIZE;
    count--;
    
    if(isEmpty()){
        front = rear = -1;  // Reset when empty
    }
}

void display(){
    if(isEmpty()){
        printf("Queue is empty!\n");
        return;
    }
    
    printf("Queue: ");
    for(int i = 0; i < count; i++){
        int index = (front + i) % SIZE;
        printf("%d ", queue[index]);
    }
    printf("\n");
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    
    dequeue();
    display();
    
    enqueue(40);
    enqueue(50);
    display();
    
    return 0;
}