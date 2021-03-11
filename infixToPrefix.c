/* 
1. Scan the infix expression from right to left.
2. If the scanned character is an operand, output it. 
3. Else, 
      1 If the precedence of the scanned operator is greater than the precedence of the operator in the stack [or the stack is empty or the stack contains a ‘(‘ ] , push it. 
      2 Else, Pop all the operators from the stack which are greater than or equal to in precedence than that of the scanned operator.
      	After doing that Push the scanned operator to the stack. [If you encounter parenthesis while popping then stop there and push the scanned operator in the stack.] 
4. If the scanned character is an ‘(‘, push it to the stack. 
5. If the scanned character is an ‘)’, pop the stack and and output it until a ‘(‘ is encountered, and discard both the parenthesis. 
6. Repeat steps 2-6 until infix expression is scanned. 
7. Print the output 
8. Pop and output from the stack until it is not empty.
9. Print in right to left.
*/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
char *stackArr = NULL;
int top = -1;
int stackSize;
char command[10], intro[]="Commands:\n\t1>Push >> For INSERTING an element\n\t2>Pop >>For REMOVE an element\n\t3>Peek >>For ACCESS the last element\n\t4>Size >>For number of STORED element\n\t5>IsEmptyStack >>To know whether stack is EMPTY\n\t6>IsFullStack >>To know whether the stack is FULL\n\t7>Display >>To DISPLAY all the stored element\n\t8>command >>To see the all COMMANDS\n\t9>exit >>Destroy the STACK or EXIT from the program\n\t10>cls >>Clear the screen\n\nThese all commands are case-sensitive !!\n\n";
char banner[]="\t\t\t\t\t\t\t\t\t-----!!!!STACK!!!!-----\n";
void Push(char );
void DisplayStack(void );
char Pop(void );
char Peek(void );
void Size(void );
int IsEmptyStack(void );
int IsFullStack(void );
void stack(void );
void infixToPostfix(void );
int operandChecker(char );
int operatorPrecidence(char );
//driver code
int main(){
	
	infixToPostfix();
	return 0;
}
void infixToPostfix(void ){
	int j = 0, size;
	char *result, *expression; 							   //a+b*(c^d-e)^(f+g*h)-i 			abcd^e-fgh*+^*+i-
	printf("enter the size of the EXPRESSION:\n");         //x+y*z/w+u 						++x/*yzwu
	scanf("%d", &size);									   //A * B + C / D      			+ * A B/ C D 
	stackSize = size;									   //(A - B/C) * (A/K-L)            *-A/BC-/AKL
	expression = (char *) malloc(sizeof(char) * size);
	result = (char *) malloc(sizeof(char) * size);
	stackArr = (char *) malloc(sizeof(char) * size);
	printf("write your EXPRESSION:\n");
	for(int i = size; i > 0; --i){
		scanf("%c", (expression + i));
	}
	for(int i = 0; i < size; ++ i){
		if(operandChecker(*(expression + i))){
			*(result + j) = *(expression + i);
			++j;
		}
		else if(*(expression + i) == '(')
			Push(*(expression + i));
		else if(*(expression + i) == ')'){
			while(!IsEmptyStack() && (Peek() != '(')){
				*(result + j) = Pop();
				++j;
			}
			Pop();
		}
		else{
			while((operatorPrecidence(*(expression + i)) <= operatorPrecidence(Peek())) && !IsEmptyStack()){
				*(result + j) = Pop();
				++j;
			}
			Push(*(expression + i));

		}
	}
	while(!IsEmptyStack()){
		*(result + j) = Pop();
		++j;
	}
	*(result + j) = '\0';
	for(int i = size; i > 0; --i)
		printf("%c", *(result + i));
	printf("\n");

}

int operandChecker(char ch){
	if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return 1;
	else
		return 0;
}
int operatorPrecidence(char ch){
	switch(ch){
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		case '^':
			return 3;
		default :
			return 0;
	}
}


void Push(char operat){
	if(top == (stackSize - 1))
		printf("stack is full !\n");
	else{
		*(stackArr + (top + 1)) = operat;
		top++;
	}
}
char Pop(){
		char rtn;
		rtn = *(stackArr + top );
		top--;
		return rtn;
}
char Peek(){
		return *(stackArr + top);
}
int IsEmptyStack(){
	return(top == -1);
}
int IsFullStack(){
	return((top + 1) == stackSize);
}
