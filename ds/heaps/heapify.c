#include<stdio.h>
#include<stdlib.h>

void max_heapify(int *arr, int i, int n){
    int left, right, max;

    left = 2*i + 1;
    right = 2*i + 2;

    max = i;

    if(left < n && arr[max] < arr[left]){
        max = left;
    }
    if(right < n && arr[max] < arr[right]){
        max = right;
    }

    if(max != i){
        int temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;

        max_heapify(arr, max, n);
    }
}


void min_heapify(int *arr, int i, int n){
    int left, right, min;

    left = 2*i + 1;
    right = 2*i + 2;

    min = i;

    if(left < n && arr[min] > arr[left]){
        min = left;
    }
    if(right < n && arr[min] > arr[right]){
        min = right;
    }

    if(min != i){
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;

        max_heapify(arr, min, n);
    }
}


int main(){

    int n = 10;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};


    // max heapify
    for(int i = (n / 2) - 1; i >= 0; i--){
        max_heapify(arr, i, n);
    }

    printf("Max heapified version -\n");
    for(int i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");

    // min heapify
    for(int i = (n / 2) - 1; i >= 0; i--){
        min_heapify(arr, i, n);
    }

    printf("Min heapified version -\n");
    for(int i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");

    
    // heap_sort
    for(int j = 0; j < n; j++){
        for(int i = ((n - j) / 2) - 1; i >= 0; i--){
            min_heapify(arr + j, i, n - j);
        }
    }

    printf("After applying heapsort -\n");
    for(int i = 0; i < n; i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");


}