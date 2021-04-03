#include<stdio.h>
#include<stdlib.h>

int arr[5], arrSize = 5;
// 0 1 2 3 4
void insertInBeginning(int rvalue){
	int arrSize1 = arrSize, i = 0;
	for(i = (arrSize1 - 1); i > 0; --i)
		arr[i] = arr[i - 1];
	arr[i] = rvalue;
};

void insertInMiddle(int rvalue){
	int arrSize1 = arrSize, i = 0;
	for(i = (arrSize1 - 1); i > ((arrSize1 - 1) / 2); --i)
		arr[i] = arr[i - 1];
	arr[i] = rvalue;
};

void insertInEnd(int rvalue){
	arr[arrSize - 1] = rvalue;
};

void display(void ){
	for(int i = 0; i < arrSize; ++ i)
		printf("%d\n", arr[i]);
}

//driver code
int main(){
	int choice;
	//printf("enter the ODD-SIZE of array:\n");
	//scanf("%d", &arrSize);
	//arr = (int *) malloc(sizeof(int ) * arrSize);
	printf("1. Insertion In Beginning\n2. Insertion In Middle\n3. Insertion In End\n");
	printf("enter all the %d values for ARRAY:\n", arrSize);
	for(int i = 0; i < arrSize; ++i)
		scanf("%d", &arr[i]);
	

	while(1){
		printf("enter your CHOICE ::\n");
		scanf("%d", &choice);

		switch(choice){
			int value;
			case 1:{
				printf("enter the value::\n");
				scanf("%d", &value);
				insertInBeginning(value);
				break;
			}
			case 2:{
				printf("enter the value::\n");
				scanf("%d", &value);
				insertInMiddle(value);
				break;
			}
			case 3:{
				printf("enter the value::\n");
				scanf("%d", &value);
				insertInEnd(value);
				break;
			}
			case 4:{
				display();
				break;
			}
			case 5:{
				exit(0);
				break;
			}
			default:{
				printf("ERROR !! CHOOSE the right choice :)");
				//break; 
				exit(1);
		}

	}
	
	}
}