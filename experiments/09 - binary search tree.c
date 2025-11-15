#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX 100
char stack[MAX];
int top = -1;
void push(char ch) {
    stack[++top] = ch;}
char pop() {
    return stack[top--];}
char peek() {
    return stack[top];}
int isEmpty() {
    return top == -1;}
int precedence(char op) {
    switch(op) {
        case '+':
        case '-': return 1;
        case '*':
        case '/': return 2;
        case '^': return 3;
        default: return 0;}}
int isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';}
void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char ch;
    while ((ch = infix[i++]) != '\0') {
        if (isspace(ch)) continue;
        if (isalnum(ch)) {
            postfix[j++] = ch;
        } else if (ch == '(') {
            push(ch);
        } else if (ch == ')') {
            while (!isEmpty() && peek() != '(')
                postfix[j++] = pop();
            pop(); // discard '('
        } else if (isOperator(ch)) {
            while (!isEmpty() && precedence(peek()) >= precedence(ch))
                postfix[j++] = pop();
            push(ch);}}
    while (!isEmpty())
        postfix[j++] = pop();
    postfix[j] = '\0';}
typedef struct Node {
    char data;
    struct Node* left;
    struct Node* right;
} Node;
Node* treeStack[MAX];
int treeTop = -1;
void pushTree(Node* node) {
    treeStack[++treeTop] = node;}
Node* popTree() {
    return treeStack[treeTop--];}
Node* buildExpTree(char* postfix) {
    int i = 0;
    char ch;
    while ((ch = postfix[i++]) != '\0') {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = ch;
        newNode->left = newNode->right = NULL;
        if (isOperator(ch)) {
            newNode->right = popTree();
            newNode->left = popTree();}
        pushTree(newNode);}
    return popTree();}
void preorder(Node* root) {
    if (root) {
        printf("%c ", root->data);
        preorder(root->left);
        preorder(root->right);}}
int main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0';
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    Node* root = buildExpTree(postfix);
    printf("Preorder traversal: ");
    preorder(root);
    printf("\n");
    return 0;
}