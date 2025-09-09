#include <stdio.h>
#define max 5

int deque[max];
int front = -1, rear = -1;

void insertfront() {
    int item;
    if (front == (rear + 1) % max) {
        printf("overflow");
        return;
    }
    printf("Enter the element ");
    scanf("%d", &item);
    if (front == -1) {
        front = rear = 0;
    } else if (front == 0) {
        front = max - 1;
    } else {
        front--;
    }
    deque[front] = item;
}

void insertrear() {
    int item;
    if (front == (rear + 1) % max) {
        printf("overflow");
        return;
    }
    printf("Enter the element ");
    scanf("%d", &item);
    if (front == -1) {
        rear = front = 0;
    } else {
        rear = (rear + 1) % max;
    }
    deque[rear] = item;
}

void deletionfront() {
    if (front == -1) {
        printf("underflow");
        return;
    }
    printf("deleted element is %d", deque[front]);
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % max;
    }
}

void deletionrear() {
    if (front == -1) {
        printf("underflow");
        return;
    }
    printf("deleted element is %d", deque[rear]);
    if (front == rear) {
        front = rear = -1;
    } else if (rear == 0) {
        rear = max - 1;
    } else {
        rear--;
    }
}

void display() {
    if (front == -1) {
        printf("queue is empty");
        return;
    }
    printf("Queue Elements:");
    for (int i = front;; i = (i + 1) % max) {
        printf("%d ", deque[i]);
        if (i == rear)
            break;
    }
}

int main() {
    int choice;
    do {
        printf("\n1.insert at front\n2.insert at rear\n3.deletion from front\n4.deletion from rear\n5.Display\n6.Exit\n");
        printf("Enter the Choice:");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertfront();
                break;
            case 2:
                insertrear();
                break;
            case 3:
                deletionfront();
                break;
            case 4:
                deletionrear();
                break;
            case 5:
                display();
                break;
            case 6:
                printf("Exiting....");
                break;
            default:
                printf("invalid Choice");
        }
    } while (choice != 6);
    return 0;
}
