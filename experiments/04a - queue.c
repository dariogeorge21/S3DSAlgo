#include <stdio.h>

#define limit 6

int QUEUE[limit];
int front = -1, rear = -1;

int Overflow() {
    return rear == limit - 1;
}

int Underflow() {
    return (front == -1) || (front > rear);
}

void enqueue(int element) {
    if (Overflow()) {
        printf("Queue is full!!\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        QUEUE[rear] = element;
        printf("\nElement has been added successfully!!\n\n");
    }
}

void dequeue() {
    if (Underflow()) {
        printf("Queue is empty!!\n");
    } else {
        printf("Deleted element is %d\n", QUEUE[front]);
        front++;
        if (front > rear) {
            front = -1;
            rear = -1;
        }
    }
}

void display() {
    if (Underflow()) {
        printf("Queue is empty!!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d\t", QUEUE[i]);
        }
        printf("\n");
    }
}

int main() {
    int flow = 1;
    while (flow == 1) {
        int option;
        printf("\nChoose the operations for queue!!\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nOption: ");
        scanf("%d", &option);
        switch (option) {
            case 1: {
                int element;
                printf("Enter the element to be added: ");
                scanf("%d", &element);
                enqueue(element);
                break;
            }
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                flow = 0;
                break;
            default:
                printf("Wrong Option!! Exiting!!\n");
                flow = 0;
                break;
        }
    }
    return 0;
}
