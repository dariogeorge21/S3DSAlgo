// convert infix expression to postfix using stack.
#include<stdio.h>
#define limit 100
#include<ctype.h>

char STACK[limit];
int top=-1;

char push(char c){
	if (top<limit-1){
		STACK[++top]=c;
	}
	return '\0';
}

char pop(){
	if (top>=0){
		return STACK[top--];
	}
	return '\0';
}

char peek(){
	if (top>=0){
		return STACK[top];
	}
	return '\0';
}

int precedence(char op) {
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
    	return 0;
}

int main() {
    	char infix[limit], postfix[limit];
    	int i = 0, j = 0;
    	char ch;
	printf("Enter infix exp: ");
   	scanf("%s", infix);

    	while ((ch = infix[i++]) != '\0') {
        	if (isalnum(ch)) {
               		 postfix[j++] = ch;
        	}
        	else if (ch == '(') {
            	push(ch);
        	}
        	else if (ch == ')') {
            		while (top != -1 && peek() != '(') {
                		postfix[j++] = pop();
            		}
            		pop();
        		}
       		 else {

            		while (top != -1 && precedence(peek()) >= precedence(ch)) {
                		postfix[j++] = pop();
            		}
            		push(ch);
        	}
    	}
	while (top != -1) {
		postfix[j++] = pop();
	}

   	postfix[j] = '\0';
	printf("Postfix expression: %s\n", postfix);
	return 0;
}
