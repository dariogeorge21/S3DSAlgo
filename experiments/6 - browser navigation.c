  #include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char url[100];
    struct Node* prev;
    struct Node* next;
};

void visitNewPage(struct Node** current);
void goBack(struct Node** current);
void goForward(struct Node** current);
void displayCurrentPage(struct Node* current);

int main() {
    struct Node* current = NULL;
    int choice;

    while (1) {
        printf("\nBrowser Navigation Menu:\n");
        printf("1. Visit New Page\n");
        printf("2. Go Back\n");
        printf("3. Go Forward\n");
        printf("4. Display Current Page\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                visitNewPage(&current);
                break;
            case 2:
                goBack(&current);
                break;
            case 3:
                goForward(&current);
                break;
            case 4:
                displayCurrentPage(current);
                break;
            case 5:
                printf("Exiting Browser Simulation\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

void visitNewPage(struct Node** current) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    char url[100];

    printf("Enter the URL of the new page: ");
    scanf("%s", url);
    strcpy(newNode->url, url);

    newNode->prev = *current;
    newNode->next = NULL;

    if (*current != NULL) {
        (*current)->next = newNode;
    }

    *current = newNode;

    printf("Visited: %s\n", url);
}

void goBack(struct Node** current) {
    if (*current == NULL || (*current)->prev == NULL) {
        printf("Cannot go back.\n");
    } else {
        *current = (*current)->prev;
        printf("Moved back to: %s\n", (*current)->url);
    }
}

void goForward(struct Node** current) {
    if (*current == NULL || (*current)->next == NULL) {
        printf("Cannot go forward.\n");
    } else {
        *current = (*current)->next;
        printf("Moved forward to: %s\n", (*current)->url);
    }
}

void displayCurrentPage(struct Node* current) {
    if (current == NULL) {
        printf("No page visited yet.\n");
    } else {
        printf("Current Page: %s\n", current->url);
    }
}
