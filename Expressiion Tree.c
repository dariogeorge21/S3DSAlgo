#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100	

struct TreeNode {
    char data;
    struct TreeNode* left;
    struct TreeNode* right;
};

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top < MAX - 1)
        stack[++top] = ch;
}

char pop() {
    if (top >= 0)
        return stack[top--];
    return '\0';
}

char peek() {
    if (top >= 0)
        return stack[top];
    return '\0';
}

int isOperand(char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

int isRightAssociative(char op) {
    return (op == '^');
}

void infixToPostfix(char infix[], char postfix[]) {
    int i, k = 0;
    char ch;
    for (i = 0; i < strlen(infix); i++) {
        ch = infix[i];
        if (ch == ' ') continue;
        if (isOperand(ch)) {
            postfix[k++] = ch;
        }
        else if (ch == '(') {
            push(ch);
        }
        else if (ch == ')') {
            while (peek() != '(' && top != -1)
                postfix[k++] = pop();
            pop();
        }
        else if (isOperator(ch)) {
            while (isOperator(peek()) &&((precedence(ch) < precedence(peek())) ||(precedence(ch) == precedence(peek()) && !isRightAssociative(ch)))) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }
    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

struct TreeNode* createNode(char data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode* buildExpressionTree(char postfix[]) {
    struct TreeNode* stack[MAX];
    int top = -1;
    
    for (int i = 0; i < strlen(postfix); i++) {
        char symbol = postfix[i];
        
        if (isOperand(symbol)) {
            stack[++top] = createNode(symbol);
        }
        else if (isOperator(symbol)) {
            struct TreeNode* right = stack[top--];
            struct TreeNode* left = stack[top--];
            struct TreeNode* node = createNode(symbol);
            node->left = left;
            node->right = right;
            stack[++top] = node;
        }
    }
    
    return stack[top];
}

void inorderTraversal(struct TreeNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%c", root->data);
        inorderTraversal(root->right);
    }
}

void main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    
    struct TreeNode* root = buildExpressionTree(postfix);
    
    printf("In-order traversal of the expression tree: ");
    inorderTraversal(root);
    printf("\n");
}
`
