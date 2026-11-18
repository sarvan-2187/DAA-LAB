#include <stdio.h>

int sumOfSquaresNums(int n){
  if(n == 0){
    return 0;
  }
  return n*n + sumOfSquaresNums(n-1);
}

int main(){
  int n;
  scanf("%d", &n);
  int sum = sumOfSquaresNums(n);
  printf("The sum is: %d\n", sum);
}
