#include<iostream>
using namespace std;
int main(){
	int *arrPointer, arrSize, arrSizeReference;
	cout<<"enter the size of ARRAY you want:";
	cin>>arrSize;
	arrSizeReference = arrSize;
	arrPointer = new int[arrSize];
	for(int i=0; i<arrSize; ++i)
		cin>>*(arrPointer + i);
	for(int i=0; i<arrSize; ++i){
		for(int i=0; i<arrSizeReference; ++i){
			if(*(arrPointer + i) > *(arrPointer + i + 1)){
				int greaterNumber = *(arrPointer + i);
				*(arrPointer + i) = *(arrPointer + i + 1);
				*(arrPointer + i + 1) = greaterNumber;
			}
		}
		--arrSizeReference;
	}

	for(int i=0; i<arrSize; ++i)
		cout<<*(arrPointer + i)<<endl;
	return 0;
}