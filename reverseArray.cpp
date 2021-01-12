#include <bits/stdc++.h>

using namespace std;

// Complete the reverseArray function below.
int main()
{
    int *arr, sizeOfArry, flag, arrValue, sizeOfArry1, flagCount;
    cin>>sizeOfArry;
    sizeOfArry1 = sizeOfArry;
    arr = (int *)malloc(sizeOfArry * sizeof(int ));
    for(int i = 0; i < sizeOfArry; ++i){
        cin>>*(arr + i);
    }
    if((sizeOfArry % 2) == 0){
        flag = sizeOfArry / 2;
        flagCount = 1;
    }
    else{
        flag = sizeOfArry / 2;
        sizeOfArry --;
        flagCount = 0;
        sizeOfArry1--;
    }
    
    //cout<<"flag"<<flag<<endl;
    for(int i = 0; flag; ++i){
        arrValue = *(arr + i);
        *(arr + i) = *(arr + sizeOfArry);
        *(arr + sizeOfArry) = arrValue;
        sizeOfArry--;
        flag--;
    }

    for(int i = flagCount; i <= sizeOfArry1; ++i){
        cout<<*(arr + i)<<" ";
    }

    return 0;
}