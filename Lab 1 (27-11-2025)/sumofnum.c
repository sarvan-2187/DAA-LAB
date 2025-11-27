// O(1) Space Complexity

#include <stdio.h>

int sumOfNums(int n){
  return ((n*(n+1))/2);
}

int main(){
  int  n;
  scanf("%d", &n);
  int sum = sumOfNums(n);
  printf("The sum is: %d\n", sum);
}
