#include <stdio.h>
#include <stdlib.h>

void delete_element(int *arr, int *arr_length, int pos) {

    for(int i = pos + 1; i < *arr_length; i++) {
        arr[i - 1] = arr[i];
    }
    *arr_length -= 1;
    arr = (int*)realloc(arr, *arr_length * sizeof(int));
}

int main(){

    int n;
    printf("Enter the size of the array : ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n*sizeof(int));

    printf("Enter the elements of the array : ");
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n - 1; i++){
        int current_element = arr[i];

        for(int j = i + 1; j < n; j++){
            if(current_element == arr[j]){
                delete_element(arr, &n, j);
                j--;
            }
        }
    }

    printf("Array after removing duplicate elements:\n");

    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}