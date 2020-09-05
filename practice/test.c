// #include<stdio.h>
// #include<stdlib.h>

// void shift(int *arr, int n, int shift_size){
//     for(int j = 0; j < shift_size; j++){
//         int temp = arr[n - 1]; //taking a temp variable to store an element so that space for shift can be made.
//         for(int i=0; i < n; i++){
//             arr[(n - 1) - i] = arr[(n - 1) - 1 - i];
//         }
//         arr[0] = temp;
//     }
// }

// int main(){
//     int n;
//     printf("Enter the number of elements in the array: ");
//     scanf("%d", &n);
    
//     int *arr = (int *)malloc(n*sizeof(int));
//     printf("Enter the elements in the array: ");
//     for(int i=0; i<n; i++){
//         scanf(" %d", &arr[i]);
//     }

//     printf("Enter start_index, end_index, shift_size: ");
//     int start_index, end_index, shift_size;
//     scanf("%d %d %d", &start_index, &end_index, &shift_size);
    
//     printf("\nArray before shift: ");
//     for(int i=0; i<n; i++){
//         printf("%d ", arr[i]);
//     }

//     shift(arr + start_index, end_index - start_index + 1, shift_size);

//     // for(int j = 0; j < shift; j++){
//     //     int temp = arr[end_index]; //taking a temp variable to store an element so that space for shift can be made.
//     //     for(int i=0; i < end_index - start_index + 1; i++){
//     //         arr[end_index - i] = arr[end_index - i - 1];
//     //     }
//     //     arr[start_index] = temp;
//     // }
//     printf("\nArray after shift: ");
//     for(int i=0; i<n; i++){
//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

#include<stdio.h>

int helper(int n){

    int first, second, third, fourth;

    if(n == 1){
        return 1;
    }

    if(n == 0){
        return 1;
    }
    if(n % 3 == 0 && n % 2 == 0){
        first =  helper(n - 1) + helper(n / 3) + helper(n / 2);
    }

    else if(n % 3 == 0){
        second =  helper(n - 1) + helper(n / 3);
    }

    else if(n % 2 == 0){
        third =  helper(n - 1) + helper(n / 2);
    }

    else{
        fourth =  helper(n - 1);
    }

    int a[4] = {first, second, third, fourth};
    int least = a[0];
    for(int i = 0; i < 4; i++){
        if(least < a[i]){
            least = a[i];
        }
        printf("%d ", a[i]);
    }
    

    return least;

}


int main(){
    int n;
    scanf("%d", &n);

    int result = helper(n);
    printf("%d", result);
}