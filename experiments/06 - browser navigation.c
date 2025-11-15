#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#define MAX 100 
 
typedef struct Node { 
    char url[MAX]; 
    struct Node* prev; 
    struct Node* next; 
} Node; 
Node* current = NULL; 
Node* createNode(const char* url) { 
    Node* temp = (Node*)malloc(sizeof(Node)); 
    strncpy(temp->url, url, MAX - 1); 
    temp->url[MAX- 1] = '\0'; 
    temp->prev = NULL; 
    temp->next = NULL; 
    return temp;} 
void NewPage(const char* url) { 
    Node* newNode = createNode(url); 
    if (current != NULL) { 
        Node* temp = current->next; 
        while (temp != NULL) { 
            Node* toFree = temp; 
            temp = temp->next; 
            free(toFree);} 
        current->next = NULL; 
        current->next = newNode; 
        newNode->prev = current; 
        newNode->next = NULL;} 
    else { 
        newNode->prev = NULL; 
        newNode->next = NULL;} 
    current = newNode; 
    printf("Visited: %s\n", url);} 
void goBack() { 
    if (current == NULL) { 
        printf("No current page.\n"); 
        return;} 
    if (current->prev == NULL) { 
        printf("You are at the first page.\n"); 
        return;} 
    current = current->prev; 
    printf("Moved back to: %s\n", current->url);} 
void goForward() { 
    if (current == NULL || current->next == NULL) { 
        printf("Not possible\n"); 
    } else { 
        current = current->next; 
        printf("Moved forward to: %s\n", current->url); 
    }} 
void display() { 
    if (current == NULL) { 
        printf("No page visited yet\n"); 
    } else { 
        printf("Current Page: %s\n", current->url); 
    }} 
void freeNode(Node* head) { 
    Node* temp; 
    while (head != NULL) { 
        temp = head; 
        head = head->next; 
        free(temp); 
    }} 
Node* findHead(Node* node) { 
    while (node != NULL && node->prev != NULL) { 
        node = node->prev;} 
    return node;} 
int main() { 
    int choice; 
    char url[MAX]; 
    while (1) { 
        printf("\nMenu:\n 1.Visit New Page\n 2.Go Back\n 3.Go Forward\n 4.Display current page \n 5.Exit \n"); 
        printf("Enter your choice: "); 
        if (scanf("%d", &choice) != 1) { 
            while (getchar() != '\n'); 
            printf("Invalid input. Please enter a number.\n"); 
            continue;} 
        switch (choice) { 
            case 1: 
                printf("Enter URL: "); 
                scanf(" %99[^\n]", url); 
                NewPage(url); 
                break; 
            case 2: 
                goBack(); 
                break; 
            case 3: 
                goForward(); 
                break; 
            case 4: 
                display(); 
                break; 
            case 5: 
                printf("Exiting \n"); 
                if (current != NULL) { 
                    Node* head = findHead(current); 
                    freeNode(head);} 
                return 0; 
            default: 
                printf("Invalid choice\n"); 
}}}