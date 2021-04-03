#include<stdio.h>

int stackSize = 100, top = -1;
char stack[100], expression[100];

void push(char rValue){
	if((top + 1) == stackSize)
		printf("OVERFLOW condition reached !\n");
	else{
		stack[top + 1] = rValue;
		++top;
	}

};

char pop(void ){
	if(top == -1)
		printf("UNDERFLOW condition reached !\n");
	else
		--top;
	return stack[top + 1];
};

bool operatorOrParenthesisChecker(char ex){
	if(ex == '+' || ex == '-' || ex == '*' || ex == '/' || ex == '^' || ex == '(' || ex == ')')
		return 0;
	else
		return 1;
};

int precedenceChecker(char op){
	switch(op){
		case '+':
		case '-': return 1;
		case '*':
		case '/':return 2;
		case '^':return 4;
	}
	return 0;
};

bool associativityChecker(char op){
	switch(op){
		case '+':
		case '-':
		case '*':
		case '/':return 1; //L --> R
		case '^':break; //R --> L 
	}
	return 0;
}

void infixToPostfixConversation(void ){
	printf("enter the infix expression :\n");
	scanf("%s", expression);
	for(int i = 0; i < stackSize; ++i){
		if(operatorOrParenthesisChecker(expression[i]))
			printf("%c", expression[i]);
		else if(expression[i] == '(' || precedenceChecker(expression[i]) > precedenceChecker(stack[top]))
			push(expression[i]);
		else if(precedenceChecker(expression[i]) == precedenceChecker(stack[top]) && associativityChecker(expression[i]) & associativityChecker(stack[top])){
			printf("%c", pop());
			--i;
		}
		else if(precedenceChecker(expression[i]) < precedenceChecker(stack[top])){
			printf("%c", pop());
			--i;
		}
		else if(expression[i] == ')'){
			while(stack[top] != '(')
				printf("%c", pop());
			pop();
		}
		else
			push(expression[i]);
	}
	while(top != -1)
		printf("%c", pop());
	printf("\n");
};

//driver code
int main(){
	infixToPostfixConversation();
	return 0;
}