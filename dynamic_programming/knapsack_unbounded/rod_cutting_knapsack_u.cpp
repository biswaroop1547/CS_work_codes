#include<iostream>


int rodCutting(int price[], int length, int n){
    int memo[length + 1][n + 1];
    int *length_arr = new int[length];
    for(int i = 0; i < length; i++){
        length_arr[i] = i + 1;
    }

    for(int i = 0; i < length + 1; i++){
        for(int j = 0; j < n + 1; j++){
            if(i == 0 || j == 0){
                memo[i][j] = 0;
            }
        }
    }
    for(int i = 1; i < length + 1; i++){
        for(int j = 1; j < n + 1; j++){
            if(length_arr[i - 1] <= j){
                memo[i][j] = std::max(price[i - 1] + memo[i][j - length_arr[i - 1]], memo[i - 1][j]);
            }
            else{
                memo[i][j] = memo[i - 1][j];
            }
        }
    }
    delete[] length_arr;
    return memo[length][n];
}


int main(){

    int price[] = {1,3, 4, 5};
    int length = 4;
    int n = 4;
    
    std::cout << rodCutting(price, length, n) << std::endl;

    return 0;
}