#include <stdio.h>
#define SIZE 5  

int deque[SIZE];
int front = -1, rear = -1;


int isFull() {
    return ((front == 0 && rear == SIZE - 1) || (front == rear + 1));
}


int isEmpty() {
    return (front == -1);
}

void insertFront(int value) {
    if (isFull()) {
        printf("Deque is FULL! Cannot insert %d at front.\n", value);
        return;
    }

    if (front == -1) { 
        front = 0;
        rear = 0;
    } 
    else if (front == 0) {
        front = SIZE - 1;
    } 
    else {
        front = front - 1;
    }

    deque[front] = value;
    printf("Inserted %d at front.\n", value);
}


void insertRear(int value) {
    if (isFull()) {
        printf("Deque is FULL! Cannot insert %d at rear.\n", value);
        return;
    }

    if (front == -1) { 
        front = 0;
        rear = 0;
    } 
    else if (rear == SIZE - 1) {
        rear = 0;
    } 
    else {
        rear = rear + 1;
    }

    deque[rear] = value;
    printf("Inserted %d at rear.\n", value);
}


void deleteFront() {
    if (isEmpty()) {
        printf("Deque is EMPTY! Cannot delete from front.\n");
        return;
    }

    printf("Deleted %d from front.\n", deque[front]);

    if (front == rear) { 
        front = -1;
        rear = -1;
    } 
    else if (front == SIZE - 1) {
        front = 0;
    } 
    else {
        front = front + 1;
    }
}


void deleteRear() {
    if (isEmpty()) {
        printf("Deque is EMPTY! Cannot delete from rear.\n");
        return;
    }

    printf("Deleted %d from rear.\n", deque[rear]);

    if (front == rear) { 
        front = -1;
        rear = -1;
    } 
    else if (rear == 0) {
        rear = SIZE - 1;
    } 
    else {
        rear = rear - 1;
    }
}


void display() {
    if (isEmpty()) {
        printf("Deque is EMPTY.\n");
        return;
    }

    printf("Deque elements: ");
    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main() {
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(2);
    display();

    deleteRear();
    display();

    deleteFront();
    display();

    insertRear(15);
    insertFront(1);
    display();

    return 0;
}
