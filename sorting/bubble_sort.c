#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int* arr, int length) {
    int i, j, temp, has_swapped;
    for (i = 0; i < length - 1; ++i) {
        has_swapped = 0;
        for (j = 0; j < length - 1 - i; ++j) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
                has_swapped = 1;
            }
        }
        if (!has_swapped) {
            break;
        }
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
    bubble_sort(arr, sizeof(arr) / sizeof(arr[0]));
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}