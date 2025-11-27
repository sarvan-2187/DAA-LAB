#include <stdio.h>

int sumOfCubeNums(int n){
  return ((n*n*(n+1)*(n+1))/4);
}

int main(){
  int  n;
  scanf("%d", &n);
  int sum = sumOfCubeNums(n);
  printf("The sum is: %d\n", sum);
}
