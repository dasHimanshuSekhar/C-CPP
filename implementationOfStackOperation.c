#include<stdio.h>
#include <stdlib.h>

int stack[5], stackSize = 5, top = -1;

void push(int rValue){
	if((top + 1) == stackSize)
		printf("OVERFLOW condition reached !\n");
	else{
		stack[top + 1] = rValue;
		++top;
	}
};

void pop(void ){
	if(top == -1)
		printf("UNDERFLOW condition reached !\n");
	else{
		printf("%d is poped successfully !\n", stack[top ]);
		--top;
	}
};

void display(){
	for(int i = top; i >= 0; --i)
		printf("%d\n", stack[i]);
};

//driver code

int main(){
	int choice;
	printf("1.Push Operation\n2.Pop Operation\n3.Display Operation\n4.Exit Operation\n");

	while(1){
		printf("enter your CHOICE ::\n");
		scanf("%d", &choice);

		switch(choice){
			case 1:{
				int value;
				if((top + 1) != stackSize){
					printf("enter the value:\n");
					scanf("%d", &value);
				}
				push(value);
				break;
			}
			case 2:{
				pop();
				break;
			}
			case 3:{
				display();
				break;
			}
			case 4:{
				exit(0);
				break;
			}
			default:{
				printf("ERROR !! CHOOSE the right choice :)");
				break;
			}
		}
	}
	return 0;
}