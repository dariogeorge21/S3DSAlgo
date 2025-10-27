// convert infix expression to postfix using stack.
#include<stdio.h>
#define limit 100

int stack[limit];

int top = -1;

int push (char c){
	if (top<=limit-1){
		stack[++top]=c;
		return 1;
	}
	else{
		return 0;
	}
}

int pop(){
	if (top>=0){
		return stack[top--];
	}
	else{
		return -1;
	}
}

int peek(){
	if (top>=0){
		return stack[top];
	}
	else{
		return -1;
	}
}

int isEmpty(){
	if (top==-1){
		return 1;
	}
	else{
		return 0;
	}
}

int precedance(char op){
	if (op=='^'){
		return 3;
	}
	else if (op=='*' || op=='/'){
		return 2;
	}
	else if (op=='+' || op=='-'){
		return 1;
	}
	else{
		return 0;
	}
}

int main(){
	char infix[limit],postfix[limit];
	printf("Enter the infix expression: ");
	scanf("%s",infix);
	int j=0;
	for (int i = 0; infix[i]!='\0'; ++i){
		if (infix[i]>='a' && infix[i]<='z' || infix[i]>='A' && infix[i]<='Z'){
			postfix[j++]=infix[i];
		}
		else if (infix[i]=='('){
			push(infix[i]);
		}
		else if (infix[i]==')'){
			while (peek()!='('){
				postfix[j++]=pop();
			}
			pop();
		}
		else{
			while (precedance(peek())>=precedance(infix[i])){
				postfix[j++]=pop();
			}
			push(infix[i]);
		}
	}
	while (!isEmpty()){
		postfix[j++]=pop();
	}
	postfix[j]='\0';
	printf("Postfix expression: %s",postfix);
	return 0;
}