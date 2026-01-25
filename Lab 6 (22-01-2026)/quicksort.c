#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* --------------------------------------------------
   1) QUICK SORT : FIRST ELEMENT AS PIVOT
-------------------------------------------------- */

int partitionFirst(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (i <= j) {
        while (i <= high && arr[i] <= pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i < j)
            swap(&arr[i], &arr[j]);
    }

    swap(&arr[low], &arr[j]);
    return j;
}

void quickSortFirst(int arr[], int low, int high) {
    if (low < high) {
        int p = partitionFirst(arr, low, high);
        quickSortFirst(arr, low, p - 1);
        quickSortFirst(arr, p + 1, high);
    }
}

/* --------------------------------------------------
   2) QUICK SORT : LAST ELEMENT AS PIVOT (LOMUTO)
-------------------------------------------------- */

int partitionLast(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSortLast(int arr[], int low, int high) {
    if (low < high) {
        int p = partitionLast(arr, low, high);
        quickSortLast(arr, low, p - 1);
        quickSortLast(arr, p + 1, high);
    }
}

/* --------------------------------------------------
   3) QUICK SORT : RANDOM ELEMENT AS PIVOT
-------------------------------------------------- */

int partitionRandom(int arr[], int low, int high) {
    int randomIndex = low + rand() % (high - low + 1);
    swap(&arr[randomIndex], &arr[high]);
    return partitionLast(arr, low, high);
}

void quickSortRandom(int arr[], int low, int high) {
    if (low < high) {
        int p = partitionRandom(arr, low, high);
        quickSortRandom(arr, low, p - 1);
        quickSortRandom(arr, p + 1, high);
    }
}

/* --------------------------------------------------
   MAIN FUNCTION
-------------------------------------------------- */

int main() {
    srand(time(NULL));

    int arr1[] = {157, 110 , 147, 122, 111, 149, 151, 141, 123, 112, 117, 133};
    int arr2[] = {157, 110 , 147, 122, 111, 149, 151, 141, 123, 112, 117, 133};
    int arr3[] = {157, 110 , 147, 122, 111, 149, 151, 141, 123, 112, 117, 133};

    int n = sizeof(arr1) / sizeof(arr1[0]);

    printf("Original Array:\n");
    printArray(arr1, n);

    quickSortFirst(arr1, 0, n - 1);
    printf("\nSorted using First Element as Pivot:\n");
    printArray(arr1, n);

    quickSortLast(arr2, 0, n - 1);
    printf("\nSorted using Last Element as Pivot:\n");
    printArray(arr2, n);

    quickSortRandom(arr3, 0, n - 1);
    printf("\nSorted using Random Element as Pivot:\n");
    printArray(arr3, n);

    return 0;
}
