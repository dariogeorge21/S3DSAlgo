#include <stdio.h>
#include <stdlib.h>

struct Block {
    int size;
    int isFree;
    int pid;
    struct Block *prev, *next;
};

struct Block *head = NULL;

struct Block* createBlock(int size) {
    struct Block *newBlock = (struct Block*)malloc(sizeof(struct Block));
    newBlock->size = size;
    newBlock->isFree = 1;
    newBlock->pid = -1;
    newBlock->prev = newBlock->next = NULL;
    return newBlock;
}
void insertBlock(int size) {
    struct Block *newBlock = createBlock(size);
    if (head == NULL) {
        head = newBlock;
        return;
    }
    struct Block *temp = head;
    while (temp->next != NULL) 
        temp = temp->next;
    temp->next = newBlock;
    newBlock->prev = temp;
}
void displayMemory() {
    struct Block *temp = head;
    printf("\nMemory Blocks:\n");
    while (temp != NULL) {
        if (temp->isFree)
            printf("[ Free | Size: %d ] <-> ", temp->size);
        else
            printf("[ P%d | Size: %d ] <-> ", temp->pid, temp->size);
        temp = temp->next;
    }
    printf("NULL\n");
}
void garbageCollector() {
    struct Block *temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->isFree && temp->next->isFree) {
            temp->size += temp->next->size;
            struct Block *del = temp->next;
            temp->next = del->next;
            if (del->next != NULL)
                del->next->prev = temp;
            free(del);
        } else {
            temp = temp->next;
        }
    }
}
void allocate(int pid, int size, int choice) {
    struct Block *temp = head, *selected = NULL;
    
    if (choice == 1) {  // First Fit
        while (temp != NULL) {
            if (temp->isFree && temp->size >= size) {
                selected = temp;
                break;
            }
            temp = temp->next;
        }
    } else if (choice == 2) {  // Best Fit
        int bestSize = 1e9;
        while (temp != NULL) {
            if (temp->isFree && temp->size >= size && temp->size < bestSize) {
                bestSize = temp->size;
                selected = temp;
            }
            temp = temp->next;
        }
    } else if (choice == 3) {  // Worst Fit
        int worstSize = -1;
        while (temp != NULL) {
            if (temp->isFree && temp->size >= size && temp->size > worstSize) {
                worstSize = temp->size;
                selected = temp;
            }
            temp = temp->next;
        }
    }
    
    if (selected == NULL) {
        printf("Process %d of size %d cannot be allocated\n", pid, size);
        displayMemory();
        return;
    }
    
    if (selected->size > size) {
        struct Block *newBlock = createBlock(selected->size - size);
        newBlock->next = selected->next;
        if (selected->next != NULL) 
            selected->next->prev = newBlock;
        newBlock->prev = selected;
        selected->next = newBlock;
        selected->size = size;
    }
    
    selected->isFree = 0;
    selected->pid = pid;
    printf("Process %d allocated %d units\n", pid, size);
    displayMemory();
}
void freeProcess(int pid) {
    struct Block *temp = head;
    int found = 0;
    while (temp != NULL) {
        if (temp->pid == pid) {
            temp->isFree = 1;
            temp->pid = -1;
            found = 1;
            printf("Process %d freed\n", pid);
            break;
        }
        temp = temp->next;
    }
    if (!found) 
        printf("Process %d not found\n", pid);
    garbageCollector();
    displayMemory();
}
int main() {
    int n, choice, size, pid = 1;
    printf("Enter number of memory blocks: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter size of block %d: ", i + 1);
        scanf("%d", &size);
        insertBlock(size);
    }
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Allocate Process\t 2. Free Process\t 3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            printf("Enter process size: ");
            scanf("%d", &size);
            printf("Choose allocation method: 1.First Fit 2.Best Fit 3.Worst Fit : ");
            scanf("%d", &choice);
            allocate(pid++, size, choice);
        }
        else if (choice == 2) {
            printf("Enter process ID to free: ");
            scanf("%d", &size);
            freeProcess(size);
        }
        else if (choice == 3) {
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }
    return 0;
}