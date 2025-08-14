#include <stdio.h>

int array[20], front = -1, rear = -1;

void display() {
    if (front == -1)
        printf("\nQueue is empty.");
    else {
        printf("\nElements in the deque:\n");
        for (int i = front; i <= rear; i++)
            printf("%d ", array[i]);
    }
}

void enqueueRear(int n, int size) {
    if (rear == size - 1)
        printf("Overflow at rear\n");
    else {
        if (front == -1)
            front = rear = 0;
        else
            rear++;
        array[rear] = n;
        display();
    }
}

void enqueueFront(int n, int size) {
    if (front == 0 && rear != -1)
        printf("Overflow at front\n");
    else {
        if (front == -1)
            front = rear = 0;
        else
            front--;
        array[front] = n;
        display();
    }
}

void dequeueFront() {
    if (front == -1 || front > rear) {
        printf("Underflow at front\n");
        front = rear = -1;
    } else {
        printf("Deleted element from front: %d\n", array[front]);
        front++;
        if (front > rear)
            front = rear = -1;
        display();
    }
}

void dequeueRear() {
    if (rear == -1 || front > rear) {
        printf("Underflow at rear\n");
        front = rear = -1;
    } else {
        printf("Deleted element from rear: %d\n", array[rear]);
        rear--;
        if (front > rear)
            front = rear = -1;
        display();
    }
}

void main() {
    int size, choice = 1, op, num;
    printf("Enter maximum size of array: ");
    scanf("%d", &size);

    while (choice == 1) {
        printf("\n1. Enqueue Front");
        printf("\n2. Enqueue Rear");
        printf("\n3. Dequeue Front");
        printf("\n4. Dequeue Rear");
        printf("\nEnter your choice: ");
        scanf("%d", &op);

        switch (op) {
            case 1:
                printf("Enter number to insert at front: ");
                scanf("%d", &num);
                enqueueFront(num, size);
                break;
            case 2:
                printf("Enter number to insert at rear: ");
                scanf("%d", &num);
                enqueueRear(num, size);
                break;
            case 3:
                dequeueFront();
                break;
            case 4:
                dequeueRear();
                break;
            default:
                printf("Invalid option.\n");
        }

        printf("\nDo you want to continue? Enter 1 for Yes, 0 for No: ");
        scanf("%d", &choice);
    }
}