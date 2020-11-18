#include<stdio.h>
#include<stdlib.h>


void add_two_matrices(int **a, int **b, int c1, int r1, int c2, int r2, int **result){
    
    if(c1 != c2 || r1 != r2){
        printf("Addition not possible due to different dimensions.\n");
        return;
    }

    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c1; j++){
            result[i][j] = a[i][j] + b[i][j];
        }
    }
    
}

int main(){
    int c1, r1, c2, r2;

    printf("Enter the number of columns and rows for the first matrix : ");
    scanf("%d %d", &c1, &r1);

    printf("Enter the number of columns and rows for the second matrix : ");
    scanf("%d %d", &c2, &r2);

    int **a = (int **)malloc(r1 * sizeof(int));

    for(int i = 0; i < r1; i++){
        a[i] = (int *)malloc(c1 * sizeof(int));
    }

    printf("Enter the elements in the first matrix :\n");

    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c1; j++){
            scanf("%d", &a[i][j]);
        }
    }
    printf("\n");

    
    int **b = (int **)malloc(r2 * sizeof(int));

    for(int i = 0; i < r2; i++){
        b[i] = (int *)malloc(c2 * sizeof(int));
    }

    printf("Enter the elements in the second matrix :\n");

    for(int i = 0; i < r2; i++){
        for(int j = 0; j < c2; j++){
            scanf("%d", &b[i][j]);
        }
    }

    int **result = (int **)malloc(r1 * sizeof(int));
    for(int i = 0; i < r1; i++){
        result[i] = (int *)malloc(c1 * sizeof(int));
    }

    add_two_matrices(a, b, c1, r1, c2, r2, result);

    printf("Resulting matrix after addition :\n");

    for(int i = 0; i < r1; i++){
        for(int j = 0; j < c1; j++){
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}