#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;}
Node* insert(Node* root, int value) {
    if (root == NULL)
        return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;}
Node* search(Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);}
Node* findMin(Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;}
Node* delete(Node* root, int key) {
    if (root == NULL) return NULL;
    if (key < root->data)
        root->left = delete(root->left, key);
    else if (key > root->data)
        root->right = delete(root->right, key);
    else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;}
        else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;}
        Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = delete(root->right, temp->data);}
    return root;}
void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }}
void freeTree(Node* root) {
    if (root != NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }}
void displayMenu() {
    printf("\n~ Binary Search Tree Operations ~\n");
    printf("1. Insert\n");
    printf("2. Search\n");
    printf("3. Delete\n");
    printf("4. Traversals\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");}
int main() {
    Node* root = NULL;
    int choice, number;
    while (1) {
        displayMenu();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter number to insert: ");
                scanf("%d", &number);
                root = insert(root, number);
                printf("%d inserted into BST.\n", number);
                break;
            case 2:
                printf("Enter number to search: ");
                scanf("%d", &number);
                if (search(root, number))
                    printf("%d found in BST.\n", number);
                else
                    printf("%d not found in BST.\n", number);
                break;
            case 3:
                printf("Enter number to delete: ");
                scanf("%d", &number);
                root = delete(root, number);
                printf("%d deleted from BST \n", number);
                break;
            case 4:
                printf("\nInorder   : ");
                inorder(root);
                printf("\n");
                break;
            case 5:
                freeTree(root);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice.\n");
        }}}
