#include <stdio.h>

int factorial(int n){
  int res = 1;
  for(int i = 2; i <= n; i++){
    res = res * i;
  }
  return res;
}

int main(){
  int n;
  scanf("%d", &n);
  int res = factorial(n);
  printf("The factorial is: %d\n", res);
}
