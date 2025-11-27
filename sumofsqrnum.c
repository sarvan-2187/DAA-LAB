// O(1) Space Complexity

#include <stdio.h>

int sumOfSquaresNums(int n){
  return ((n*(n+1)*(2*n+1))/6);
}

int main(){
  int  n;
  scanf("%d", &n);
  int sum = sumOfSquaresNums(n);
  printf("The sum is: %d\n", sum);
}
