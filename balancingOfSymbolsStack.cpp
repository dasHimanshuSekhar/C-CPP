#include<iostream>
using namespace std;

int main(){
	char *arr, *stackArr;
	int arrSize, top = -1;
	cin >> arrSize;
	arr = (char *)malloc(arrSize * sizeof(int));
	stackArr = (char *)malloc(arrSize * sizeof(int));
	for(int i = 0; i < arrSize; ++i){
		cin >> *(arr + i);
	}
 	int push = 0, pop = 0, flag = 0;
	for(int i = 0; i < arrSize; ++i){
		if(*(arr + i) == '(' || *(arr + i) == '{' || *(arr + i) == '['){
			*(stackArr + push) = *(arr + i);
			++ push;
			++ pop;
			++ top;
			flag = 1;
		}
		else if(*(arr + i) == ')'){
			if(*(stackArr + pop - 1) == '('){
				*(stackArr + pop - 1) = 0;
				pop = push;
				-- top;
			}
			else if(*(stackArr + pop - 1) == '}'){
				if(*(stackArr + pop - 2) == '[' || *(stackArr + pop - 2) == '('){
					break;
				}
			}
			else if(*(stackArr + pop - 1) == ']'){
				if(*(stackArr + pop - 2) == '{' || *(stackArr + pop - 2) == '('){
					break;
				}
			}
			else if(*(stackArr + pop - 1) == ')'){
				if(*(stackArr + pop - 2) == '[' || *(stackArr + pop - 2) == '{'){
					break;
				}
			}
			else if(*(stackArr + pop - 1) == '[' || *(stackArr + pop - 1) == '{'){
				break;
			}
			else{
				-- i;
				-- pop;
			}
		}
		else if(*(arr + i) == '}'){
			if(*(stackArr + pop - 1) == '{'){
				*(stackArr + pop - 1) = 0;
				pop = push;
				-- top;
			}
			else if(*(stackArr + pop - 1) == '}'){
				if(*(stackArr + pop - 2) == '[' || *(stackArr + pop - 2) == '('){
					break;
				}
			}
			else if(*(stackArr + pop - 1) == ']'){
				if(*(stackArr + pop - 2) == '{' || *(stackArr + pop - 2) == '('){
					break;
				}
			}
			else if(*(stackArr + pop - 1) == ')'){
				if(*(stackArr + pop - 2) == '[' || *(stackArr + pop - 2) == '{'){
					break;
				}
			}
			else if(*(stackArr + pop - 1) == '[' || *(stackArr + pop - 1) == '('){
				break;
			}
			else{
				-- i;
				-- pop;
			}
		}
		else if(*(arr + i) == ']'){
			if(*(stackArr + pop - 1) == '['){
				*(stackArr + pop - 1) = 0;
				pop = push;
				-- top;
			}
			else if(*(stackArr + pop - 1) == '}'){
				if(*(stackArr + pop - 2) == '[' || *(stackArr + pop - 2) == '('){
					break;
				}
			}
			else if(*(stackArr + pop - 1) == ']'){
				if(*(stackArr + pop - 2) == '{' || *(stackArr + pop - 2) == '('){
					break;
				}
			}
			else if(*(stackArr + pop - 1) == ')'){
				if(*(stackArr + pop - 2) == '[' || *(stackArr + pop - 2) == '{'){
					break;
				}
			}
			else if(*(stackArr + pop - 1) == '(' || *(stackArr + pop - 1) == '{'){
				break;
			}
			else{
				-- i;
				-- pop;
			}
		}
		else
		{
			break;
		}

	}

	if(top == -1 && flag == 1)
		cout << "WOW ! congrats it's balanced !!" << '\n';
	else{
		cout << "Unbalanced !!" << endl;
		return 0;
	}

	return 0;
}