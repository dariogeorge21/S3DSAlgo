// Browser Navigation Simulation using Doubly Linked List in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char url[100];
    struct Node* prev;
    struct Node* next;
};

// Global variables for simplicity
struct Node* current = NULL;  // Current page we're viewing

// Function to create a new node
struct Node* createNode(char* url) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    strcpy(newNode->url, url);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to visit a new page
void visitPage(char* url) {
    struct Node* newNode = createNode(url);
    
    if (current == NULL) {
        // First page visit
        current = newNode;
    } else {
        // Clear forward history (pages after current)
        struct Node* temp = current->next;
        while (temp != NULL) {
            struct Node* toDelete = temp;
            temp = temp->next;
            free(toDelete);
        }
        
        // Link new page to current
        current->next = newNode;
        newNode->prev = current;
        current = newNode;
    }
    
    printf("Visited: %s\n", url);
}

// Function to go back to previous page
void goBack() {
    if (current == NULL) {
        printf("No pages visited yet!\n");
        return;
    }
    
    if (current->prev == NULL) {
        printf("No previous page to go back to!\n");
        return;
    }
    
    current = current->prev;
    printf("Went back to: %s\n", current->url);
}

// Function to go forward to next page
void goForward() {
    if (current == NULL) {
        printf("No pages visited yet!\n");
        return;
    }
    
    if (current->next == NULL) {
        printf("No next page to go forward to!\n");
        return;
    }
    
    current = current->next;
    printf("Went forward to: %s\n", current->url);
}

// Function to display current page
void displayCurrent() {
    if (current == NULL) {
        printf("No current page!\n");
    } else {
        printf("Current page: %s\n", current->url);
    }
}

// Function to display all history
void displayHistory() {
    if (current == NULL) {
        printf("No browsing history!\n");
        return;
    }
    
    // Go to the beginning of history
    struct Node* start = current;
    while (start->prev != NULL) {
        start = start->prev;
    }
    
    printf("\nBrowsing History:\n");
    printf("================\n");
    
    struct Node* temp = start;
    int position = 1;
    
    while (temp != NULL) {
        if (temp == current) {
            printf("%d. %s <-- (Current)\n", position, temp->url);
        } else {
            printf("%d. %s\n", position, temp->url);
        }
        temp = temp->next;
        position++;
    }
    printf("\n");
}

int main() {
    int choice;
    char url[100];
    
    printf("=== Browser Navigation Simulator ===\n");
    printf("1. Visit new page\n");
    printf("2. Go back\n");
    printf("3. Go forward\n");
    printf("4. Show current page\n");
    printf("5. Show history\n");
    printf("6. Exit\n");
    
    while (1) {
        printf("\nEnter your choice (1-6): ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter URL to visit: ");
                scanf("%s", url);
                visitPage(url);
                break;
                
            case 2:
                goBack();
                break;
                
            case 3:
                goForward();
                break;
                
            case 4:
                displayCurrent();
                break;
                
            case 5:
                displayHistory();
                break;
                
            case 6:
                printf("Thank you for using Browser Navigator!\n");
                return 0;
                
            default:
                printf("Invalid choice! Please enter 1-6.\n");
        }
    }
    
    return 0;
}