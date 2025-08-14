#include <stdio.h>
#include <string.h>
int MAX=100;
char stack[100];
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
    return ((ch >= 'a' && ch <= 'z') ||(ch >= 'A' && ch <= 'Z') ||(ch >= '0' && ch <= '9'));
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
void main() {
    char infix[MAX], postfix[MAX];
    printf("Enter infix expression :");
    scanf("%s", infix);
    infixToPostfix(infix, postfix);
    printf("Postfix expression: %s\n", postfix);
}