#include <stdio.h>
#include <stdlib.h>

void selection_sort(int* arr, int length) {
    int i, j, min, temp;
    for (i = 0; i < length; ++i) {
        min = i;
        for (j = i + 1; j < length; ++j) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr[] = {3, 2, 1, 5, 4};

    printf("Unsorted array :\n");
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Sorted array :\n");
    selection_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}