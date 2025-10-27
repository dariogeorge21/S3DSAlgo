// Binary Tree

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Node {
    char data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(char data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

void prefixTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    printf("%c ", root->data);
    prefixTraversal(root->left);
    prefixTraversal(root->right);
}

void postfixTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    postfixTraversal(root->left);
    postfixTraversal(root->right);
    printf("%c ", root->data);
}

struct Node* buildExampleTree() {
    struct Node* root = newNode('+');
    root->left = newNode('a');
    root->right = newNode('*');
    root->right->left = newNode('b');
    root->right->right = newNode('c');
    return root;
}

int main() {
    struct Node* root = buildExampleTree();

    printf("Prefix (Pre-order) Traversal: ");
    prefixTraversal(root);
    printf("\n");

    printf("Postfix (Post-order) Traversal: ");
    postfixTraversal(root);
    printf("\n");

    return 0;
}
