#include<iostream>


int countSubsetSum(int value[], int sum, int n){

    int memo[n + 1][sum + 1];

    for(int i = 0; i < n + 1; ++i){
        for(int j = 0; j < sum + 1; ++j){
            if(i == 0){
                memo[i][j] = 0;
            }
            if(j == 0){
                memo[i][j] = 1;
            }
        }
    }
    for(int i = 1; i < n + 1; ++i){
        for(int j = 1; j < sum + 1; ++j){
            if(value[i - 1] <= j){
                memo[i][j] = memo[i - 1][j - value[i - 1]] + memo[i-1][j];
            }
            else{
                memo[i][j] = memo[i - 1][j];
            }
        }
    }
    return memo[n][sum];

}

int main(){
    int value[] = {2, 3, 5, 6, 8, 10};
    int sum = 10;
    int n = 6;

    std::cout << countSubsetSum(value, sum, n) << std::endl;
    return 0;
}