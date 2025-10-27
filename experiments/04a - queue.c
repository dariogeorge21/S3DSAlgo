#include<stdio.h>
#define limit 6

int queue[limit];
int front = -1, rear = -1;

int isFull(){
    return (rear == limit - 1);
}

int isEmpty(){
    return (front == -1 || front > rear);
}

void enqueue(int n){
    if (isFull()) {
        printf("Queue is full! Cannot insert %d\n", n);
        return;
    }
    if (front == -1) front = 0;
    rear++;
    queue[rear] = n;
    printf("Element %d inserted to queue\n", n);
}

void dequeue(){
    if (isEmpty()) {
        printf("Queue is empty! Cannot dequeue\n");
        return;
    }
    printf("Element %d dequeued\n", queue[front]);
    front++;
    
    // Reset queue when empty
    if (front > rear) {
        front = rear = -1;
    }
}

void display(){
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
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
    
    return 0;
}