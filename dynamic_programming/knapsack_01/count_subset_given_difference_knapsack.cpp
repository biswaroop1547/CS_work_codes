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


int countSubsetSumMinDiff(int value[], int n, int diff){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += value[i];
    }
    int s1_sum = (diff + sum + 1) / 2;

    return countSubsetSum(value, s1_sum, n);
}



int main(){
    int value[] = {1, 1, 2, 3};
    int diff = 1;
    int n = 4;

    std::cout << countSubsetSumMinDiff(value, n, diff) << std::endl;
    return 0;
}