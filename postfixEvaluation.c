#include <stdio.h>
#include <ctype.h>

int stack[12], stackSize = 12, top = -1;
char expression[12] = "53+62/*35*+"; //53+62/*35*+			231*+9-


void push(int rValue){
	if((top + 1) == stackSize)
		printf("OVERFLOW condition reached !\n");
	else{
		stack[top + 1] = rValue;
		++top;
	}

};



int pop(void ){
	if(top == -1)
		printf("UNDERFLOW condition reached !\n");
	else{
		--top;
	}
	return stack[top + 1];
};


int postfixEvaluation(void){
	for(int i = top; (i + 2) < stackSize; ++i){
		if(isdigit(expression[i + 1])){

			push(expression[i + 1] - '0');
		}
		else{
			int op1 = pop(), op2 = pop();
			switch(expression[i + 1]){
				case '+':push(op2 + op1); break;
				case '-':push(op2 - op1); break;
				case '*':push(op2 * op1); break;
				case '/':push(op2 / op1); break;
			}
		}

	}
	return pop();
};


//driver code

int main(){
	printf("The postfix evaluation is %d\n", postfixEvaluation());
	return 0;
}