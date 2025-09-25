#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct ExpNode {
    char data;
    struct ExpNode *left, *right;
} ExpNode;

typedef struct Stack {
    ExpNode* arr[100];
    int top;
} Stack;

void push(Stack* s, ExpNode* node) { s->arr[++(s->top)] = node; }
ExpNode* pop(Stack* s) { return s->arr[(s->top)--]; }

ExpNode* createExpNode(char data) {
    ExpNode* node = (ExpNode*)malloc(sizeof(ExpNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

ExpNode* buildExpressionTree(char postfix[]) {
    Stack s; s.top = -1;
    for (int i = 0; postfix[i]; i++) {
        char ch = postfix[i];
        if (isalnum(ch)) {
            push(&s, createExpNode(ch));
        } else {
            ExpNode* node = createExpNode(ch);
            node->right = pop(&s);
            node->left = pop(&s);
            push(&s, node);
        }
    }
    return pop(&s);
}

void printPrefix(ExpNode* root) {
    if (root) {
        printf("%c ", root->data);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}
void printPostfix(ExpNode* root) {
    if (root) {
        printPostfix(root->left);
        printPostfix(root->right);
        printf("%c ", root->data);
    }
}

int main() {
    char postfix[] = "ab+c*"; 
    ExpNode* root = buildExpressionTree(postfix);

    printf("Prefix : ");
    printPrefix(root);
    printf("\nPostfix: ");
    printPostfix(root);
    printf("\n");
    return 0;
}
	
