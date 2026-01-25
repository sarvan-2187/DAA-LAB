#include <stdlib.h>

int partitionRandom(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);

    int temp = arr[randomIndex];
    arr[randomIndex] = arr[high];
    arr[high] = temp;

    return partitionLast(arr, low, high);
}

void quickSortRandom(int arr[], int low, int high) {
    if (low < high) {
        int p = partitionRandom(arr, low, high);
        quickSortRandom(arr, low, p - 1);
        quickSortRandom(arr, p + 1, high);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {157, 110 , 147, 122, 111, 149, 151, 141, 123, 112, 117, 133};
    int n = sizeof(arr) / sizeof(arr[0]);

    quickSortRandom(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}
