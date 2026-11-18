#include <stdio.h>

int sumOfNums(int n){
  if(n == 0){
    return 0;
  }
  return n + sumOfNums(n-1);
}

int main(){
  int n;
  scanf("%d", &n);
  int sum = sumOfNums(n);
  printf("The sum is: %d\n", sum);
}
