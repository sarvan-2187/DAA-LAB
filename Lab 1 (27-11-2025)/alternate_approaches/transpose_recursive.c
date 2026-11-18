#include <stdio.h>

int arr[3][3];

void readTranspose(int k){
  if(k == 9){
    return;
  }
  scanf("%d", &arr[k%3][k/3]);
  readTranspose(k+1);
}

void printMatrix(int k){
  if(k == 9){
    return;
  }
  printf("%d ", arr[k/3][k%3]);
  if(k%3 == 2){
    printf("\n");
  }
  printMatrix(k+1);
}

int main(){
  readTranspose(0);
  printMatrix(0);
}
