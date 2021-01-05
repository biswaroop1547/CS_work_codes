// this problem is the same as count subset given difference knapsack problem.

#include<iostream>


int countSubsetSum(int value[], int sum, int n){
    int memo[n + 1][sum + 1];
    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < sum + 1; j++){
            if(i == 0){
                memo[i][j] = 0;
            }
            if(j == 0){
                memo[i][j] = 1;
            }
        }
    }
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < sum + 1; j++){
            if(value[i - 1] <= j){
                memo[i][j] = memo[i - 1][j - value[i - 1]] + memo[i - 1][j];
            }
            else{
                memo[i][j] = memo[i - 1][j];
            }
        }
    }
    return memo[n][sum];
}



int targetSum(int value[], int n, int target){
    int arr_sum = 0;
    for(int i = 0; i < n; i++){
        arr_sum += value[i];
    }
    int s1_sum = ( arr_sum + target + 1) / 2;
    return countSubsetSum(value, s1_sum, n);
}


int main(){
    int value[] = {1, 1, 2, 3};
    int target = 1;
    int n = 4;

    std::cout << targetSum(value, n, target) << std::endl;
    return 0;
}