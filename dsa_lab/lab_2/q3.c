#include<stdio.h>
#include<stdlib.h>

int main(){
    int c, r;
    scanf("%d %d", &c, &r);

    int **a = (int **)malloc(sizeof(int) * r);

    for (int i = 0; i < r; i++){
        a[i] = (int *)malloc(sizeof(int) * c);
    }

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf(" %d", &a[i][j]);
        }
    }

    printf("The 2D matrix we have is:\n");

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    printf("The spiral of the given 2D  matrix is:\n");
    int c_copy = c;
    int r_copy = r;
    int edge_count = 0;
    for(int i = 0; i < r; i++){
        
        if(edge_count % 4 == 0){
            for(int j = 0; j < c; j++){
                printf("%d ", a[i][j]);
            }
        }

        else if(edge_count % 4 == 1){
            for(int i_inside = r - r_copy + 1; i_inside < r_copy; i_inside++){
                printf("%d ", a[i_inside][c_copy - 1]);
            }
        }

        else if(edge_count % 4 == 2){
            for(int j = c_copy - 1; j > 0; j--){
                printf("%d ", a[r_copy - 1][j - 1]);
            }
        }

        else if(edge_count % 4 == 3){
            for(int i_left = r_copy - 1; i_left >= 0; i_left--){
                printf("|hey");
                printf("%d ", a[i_left - 1][c-c_copy]);
                break;
            }
        } 

        edge_count++;

    }


    
}