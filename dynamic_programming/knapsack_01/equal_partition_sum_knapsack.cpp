#include<iostream>


bool subsetSum(int value[], int sum, int n){
    bool memo[n + 1][sum + 1];

    for(int i = 0; i < n + 1; ++i){
        for(int j = 0; j < sum + 1; ++j){
            if(i == 0){
                memo[i][j] = false;
            }
            if(j == 0){
                memo[i][j] = true;
            }
        }
    }
    for(int i = 1; i < n + 1; ++i){
        for(int j = 1; j < sum + 1; ++j){
            if(value[i - 1] <= j){
                memo[i][j] = memo[i - 1][j - value[i - 1]] || memo[i - 1][j];
            }
            else{
                memo[i][j] = memo[i - 1][j];
            }
        }
    }
    return memo[n][sum];
}


bool equalPartitionSum(int value[], int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += value[i];
    }

    if(sum % 2 != 0){
        return false;   
    }

    else{
        return subsetSum(value, sum / 2, n);
    }

}

int main(){
    int value[] = {4, 3, 2, 8, 5};
    int n = 5;

    std::cout << equalPartitionSum(value, n) << std::endl;
    return 0;
}