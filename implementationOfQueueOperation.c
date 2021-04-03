#include <stdio.h>
#include <stdlib.h>

int queue[5], front = -1, rare = -1, queueSize = 5;
void enqueue(int rValue){
	if(rare == queueSize)
		printf("OVERFLOW condition reached !\n");
	else{
		queue[rare] = rValue;
		++rare;
	}
};

int dequeue(void ){
	if(front >= rare)
		printf("UNDERFLOW condition reached !\n");
	else
		++front;
	return queue[front - 1];
};

int main(){
	int choice, counter = 0;
	printf("1.Enqueue Operation\n2.Dequeue Operation\n3.Exit Operation\n\n");

	while(1){
		printf("enter your CHOICE ::\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:{
				if(counter == 0)
					front = rare = 0;
				int value;
				if(rare != queueSize){
					printf("enter the value :\n");
					scanf("%d", &value);
				}
				enqueue(value);
				break;
			}
			case 2:{
				if(front < rare)
					printf("%d is dequeued successfully !\n", dequeue());
				else
					dequeue();
				break;
			}
			case 3:{
				exit(0);
				break;	
			}
			default:{
				printf("ERROR !! CHOOSE the right choice :)\n");
				break;
			}
		}
		++counter;
	}
	return 0;
}