// Expression Tree from Infix Expression

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
typedef struct Node {
    char data;
    struct Node *left, *right;
} Node;

typedef struct Stack {
    int top;
    unsigned capacity;
    void** array;
} Stack;
Stack* createStack(unsigned capacity) {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (void**)malloc(stack->capacity * sizeof(void*));
    return stack;
}
int isEmpty(Stack* stack) {
    return stack->top == -1;
}
void push(Stack* stack, void* item) {
    stack->array[++stack->top] = item;
}
void* pop(Stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top--];
}
void* peek(Stack* stack) {
    if (isEmpty(stack))
        return NULL;
    return stack->array[stack->top];
}
typedef struct CharStack {
    int top;
    int capacity;
    char* array;
} CharStack;
CharStack* createCharStack(int capacity) {
    CharStack* stack = (CharStack*) malloc(sizeof(CharStack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*) malloc(stack->capacity * sizeof(char));
    return stack;
}
int isCharStackEmpty(CharStack* stack) {
    return stack->top == -1;
}
void pushChar(CharStack* stack, char c) {
    stack->array[++stack->top] = c;
}
char popChar(CharStack* stack) {
    if (isCharStackEmpty(stack))
        return '\0';
    return stack->array[stack->top--];
}
char peekChar(CharStack* stack) {
    if (isCharStackEmpty(stack))
        return '\0';
    return stack->array[stack->top];
}
int precedence(char op) {
    switch(op) {
        case '+': case '-': return 1;
        case '*': case '/': return 2;
        case '^': return 3;
    }
    return 0;
}
int isOperator(char c) {
    return c=='+' || c=='-' || c=='*' || c=='/' || c=='^';
}
void infixToPostfix(char* infix, char* postfix) {
    CharStack* stack = createCharStack(strlen(infix));
    int k = 0;
    for(int i=0; infix[i]; i++) {
        char c = infix[i];
        if (c == ' ' || c == '\t') continue;
        if (isalnum(c)) {
            postfix[k++] = c;
        } else if (c == '(') {
            pushChar(stack, c);
        } else if (c == ')') {
            while (!isCharStackEmpty(stack) && peekChar(stack) != '(') {
                postfix[k++] = popChar(stack);
            }
            if (!isCharStackEmpty(stack) && peekChar(stack) == '(')
                popChar(stack); // Remove '('
        } else if (isOperator(c)) {
            while (!isCharStackEmpty(stack) && precedence(peekChar(stack)) >= precedence(c)) {
                postfix[k++] = popChar(stack);
            }
            pushChar(stack, c);
        } }
    while (!isCharStackEmpty(stack)) {
        postfix[k++] = popChar(stack);
    }
    postfix[k] = '\0';
    free(stack->array);
    free(stack);
}
Node* createNode(char data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}
Node* buildExpressionTree(char* postfix) {
    Stack* stack = createStack(strlen(postfix));
    for(int i=0; postfix[i]; i++) {
        char c = postfix[i];
        if (isalnum(c)) {
            Node* node = createNode(c);
            push(stack, node);
        } else if (isOperator(c)) {
            Node* right = (Node*) pop(stack);
            Node* left = (Node*) pop(stack);
            Node* node = createNode(c);
            node->left = left;
            node->right = right;
            push(stack, node);
        } }
   Node* root = (Node*) pop(stack);
    free(stack->array);
    free(stack);
    return root;
}
void preorder(Node* root) {
    if (root) {
        printf("%c", root->data);
        preorder(root->left);
        preorder(root->right);
    }}
void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c", root->data);
    }}
int main() {
    char infix[100], postfix[100];
    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    int len = strlen(infix);
    if(infix[len-1] == '\n') infix[len-1] = '\0';
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
    Node* root = buildExpressionTree(postfix);
    printf("Prefix expression (Preorder): ");
    preorder(root);
    printf("\n");
    printf("Postfix expression (Postorder): ");
    postorder(root);
    printf("\n");
    return 0;
}
