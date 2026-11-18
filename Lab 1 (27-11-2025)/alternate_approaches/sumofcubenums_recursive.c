#include <stdio.h>

int sumOfCubeNums(int n){
  if(n == 0){
    return 0;
  }
  return n*n*n + sumOfCubeNums(n-1);
}

int main(){
  int n;
  scanf("%d", &n);
  int sum = sumOfCubeNums(n);
  printf("The sum is: %d\n", sum);
}
