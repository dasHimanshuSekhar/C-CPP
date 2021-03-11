#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int *stackArr = NULL;
int top = -1;
int stackSize;
char command[10], intro[]="Commands:\n\t1>Push >> For INSERTING an element\n\t2>Pop >>For REMOVE an element\n\t3>Peek >>For ACCESS the last element\n\t4>Size >>For number of STORED element\n\t5>IsEmptyStack >>To know whether stack is EMPTY\n\t6>IsFullStack >>To know whether the stack is FULL\n\t7>Display >>To DISPLAY all the stored element\n\t8>command >>To see the all COMMANDS\n\t9>exit >>Destroy the STACK or EXIT from the program\n\t10>cls >>Clear the screen\n\nThese all commands are case-sensitive !!\n\n";
char banner[]="\t\t\t\t\t\t\t\t\t-----!!!!STACK!!!!-----\n";
void Push(void );
void DisplayStack(void );
void Pop(void );
void Peek(void );
void Size(void );
int IsEmptyStack(void );
int IsFullStack(void );
void stack (void ){
	printf("Enter the size of the stack:\n>>");
	scanf("%d",&stackSize);
	stackArr = (int *) malloc(stackSize * (sizeof(int)));
	if(stackArr == NULL){
		printf("Memmory is full !\n");
		exit (0);
	}
	else
	{
		while(1){
			printf(">>");
			scanf("%s",command);
			if(!strcmp(command, "exit"))
				exit (0);
			else if(!strcmp(command, "cls")){
				system("cls");
				printf("%s", banner);
			}
			else if(!strcmp(command, "command"))
				printf("%s", intro);
			else if(!strcmp(command, "Push")){
				Push();
			}
			else if(!strcmp(command, "Pop")){
				Pop();
			}
			else if(!strcmp(command, "Peek")){
				Peek();
			}
			else if(!strcmp(command, "Size")){
				Size();
			}
			else if(!strcmp(command, "IsEmptyStack")){
				if(IsEmptyStack())
					printf("True !\n");
				else
					printf("False !\n");
			}
			else if(!strcmp(command, "Display")){
				DisplayStack();
			}
			else if(!strcmp(command, "IsFullStack")){
				if(IsFullStack())
					printf("True !\n");
				else
					printf("False !\n");
			}
			else{
				printf("ERROR !\n");
			}
		}
	}

}
//driver code
int main(){
	
	printf("%s", banner);
	printf("%s", intro);
	stack();
	return 0;
}
void Push(){
	if(top == (stackSize - 1))
		printf("stack is full !\n");
	else{
		printf("Enter the number:\n");
		scanf("%d", (stackArr + (top + 1)));
		printf("%d is Pushed successfully !\n", *(stackArr + (top + 1)));
		top++;
	}
}
void Pop(){
	if(top == -1){
		printf("stack is empty !\n");
	}
	else{
		*(stackArr + (top + 1)) = 0;
		if(!*(stackArr + (top + 1)))
			printf("%d is Poped successfully !\n", *(stackArr + (top + 1)));
		top--;
	}
}
void Peek(){
	if(top == -1){
		printf("stack is empty !\n");
	}
	else{
		printf("%d\n", *(stackArr + top));
	}
}
void Size(){
	printf("%d out of %d\n", (top + 1), stackSize);
}
int IsEmptyStack(){
	return(top == -1);
}
int IsFullStack(){
	return((top + 1) == stackSize);
}
void DisplayStack(){
	if(top == -1)
		printf("stack if empty !\n");
	else{
		int decreament = (top + 1);
		while(decreament--){
			printf("%d\n", *(stackArr + decreament));
		}
	}
}