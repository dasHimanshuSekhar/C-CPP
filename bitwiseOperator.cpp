#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
  
  int storeAnd = 0, storeOr = 0, storeXor = 0, i = 1, j = 2;
  for(int a = i; a < n; ++a){
      for(int b = j; b < n; ++b){
        if(((a & b) < k) && ((a & b) >= storeAnd))
            storeAnd = a & b;
        if(((a | b) < k) && ((a | b) >= storeOr))
            storeOr = a | b;
        if(((a ^ b) < k) && ((a ^ b) >= storeXor))
            storeXor = a ^ b;
      }
      i++;
      j++;
  }
  printf("%d\n%d\n%d", storeAnd, storeOr, storeXor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}
