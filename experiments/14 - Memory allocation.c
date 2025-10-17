
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int id;
    int is_allocated;
    struct Node* next;
} Node;

Node* head = NULL;

void allocate(int id) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (!new_node) {
        printf("Memory allocation failed\n");
        return;
    }
    new_node->id = id;
    new_node->is_allocated = 1;
    new_node->next = head;
    head = new_node;
    printf("Allocated block %d\n", id);
}

void free_block(int id) {
    Node* current = head;
    while (current != NULL) {
        if (current->id == id && current->is_allocated == 1) {
            current->is_allocated = 0;
            printf("Freed block %d\n", id);
            return;
        }
        current = current->next;
    }
    printf("Block %d not found or already freed\n", id);
}

void garbage_collect() {
    Node *current = head, *prev = NULL;
    while (current != NULL) {
        if (current->is_allocated == 0) {
            if (prev == NULL) {
                head = current->next;
                free(current);
                current = head;
            } else {
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
            printf("Garbage collected a freed block\n");
        } else {
            prev = current;
            current = current->next;
        }
    }
}

void display() {
    Node* current = head;
    printf("Current blocks:\n");
    if (!current) {
        printf("No blocks allocated.\n");
        return;
    }
    while (current != NULL) {
        printf("Block ID: %d, Status: %s\n", current->id, current->is_allocated ? "Allocated" : "Freed");
        current = current->next;
    }
    printf("\n");
}

int main() {
    int choice, id;
    while (1) {
        printf("Menu:\n");
        printf("1. Allocate block\n");
        printf("2. Free block\n");
        printf("3. Garbage collect\n");
        printf("4. Display blocks\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter block ID to allocate: ");
                scanf("%d", &id);
                allocate(id);
                break;
            case 2:
                printf("Enter block ID to free: ");
                scanf("%d", &id);
                free_block(id);
                break;
            case 3:
                garbage_collect();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    return 0;
}

