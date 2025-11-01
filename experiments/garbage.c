#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    int id;
    int inUse;
    struct Node *prev, *next;
} Node;

Node *head = NULL;
Node* createBlock(int id)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->inUse = 1;
    newNode->prev = newNode->next = NULL;
    return newNode;
}
void allocateBlock(int id)
{
    Node* newNode = createBlock(id);
    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    printf("Block %d allocated.\n", id);
}
void markUnused(int id)
{
    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->id == id)
        {
            temp->inUse = 0;
            printf("Block %d marked as unused (garbage).\n", id);
            return;
        }
        temp = temp->next;
    }
    printf("Block %d not found.\n", id);
}
void garbageCollect()
{
    Node* temp = head;
    while (temp != NULL)
    {
        Node* nextNode = temp->next;
        if (temp->inUse == 0)
        {
            printf("Garbage Collector: Freeing block %d\n", temp->id);
            if (temp->prev != NULL)
                temp->prev->next = temp->next;
            else
                head = temp->next;
            if (temp->next != NULL)
                temp->next->prev = temp->prev;
            free(temp);
        }
        temp = nextNode;
    }
}
void displayBlocks()
{
    Node* temp = head;
    printf("\nCurrent Memory Blocks:\n");
    if (temp == NULL)
    {
        printf("No memory blocks allocated.\n");
        return;
    }
    while (temp != NULL)
    {
        printf("Block %d | Status: %s\n", temp->id,
               temp->inUse ? "In Use" : "Garbage");
        temp = temp->next;
    }
}
int main()
{
    int choice, id;
    while (1)
    {
        printf("\n=== Garbage Collector Simulation ===\n");
        printf("1. Allocate Memory Block\n");
        printf("2. Mark Block as Unused\n");
        printf("3. Run Garbage Collector\n");
        printf("4. Display Memory Blocks\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter block ID to allocate: ");
                scanf("%d", &id);
                allocateBlock(id);
                break;
            case 2:
                printf("Enter block ID to mark unused: ");
                scanf("%d", &id);
                markUnused(id);
                break;
            case 3:
                garbageCollect();
                break;
            case 4:
                displayBlocks();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
}
