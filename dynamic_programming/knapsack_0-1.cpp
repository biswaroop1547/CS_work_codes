#include<iostream>
#include<vector>


int knapsack_recurr(int weight[], int value[], int w, int n, std::vector<std::vector<int>> memo){
    if(n == 0 || w == 0){
        return 0;
    }
    if(memo[w][n] != -1){
        return memo[w][n];
    }
    else if(weight[n - 1] <= w){
        memo[w][n] = std::max(value[n - 1] + knapsack_recurr(weight, value, w - weight[n - 1], n - 1, memo), knapsack_recurr(weight, value, w, n - 1, memo));
    }
    else if(weight[n - 1] > w){
        memo[w][n] = knapsack_recurr(weight, value, w, n - 1, memo);
    }
    return memo[w][n];
}




int knapsack_iter(int weight[], int value[], int w, int n){
    int memo[n + 1][w + 1];

    for(int i = 0; i < n + 1; ++i){
        for(int j = 0; j < w + 1; ++j){
            if(i == 0 || j == 0){
                memo[i][j] = 0;
            }
        }
    }
    for(int i = 1; i < n + 1; ++i){
        for(int j = 1; j < w + 1; ++j){
            if(weight[i - 1] <= j){
                memo[i][j] = std::max(value[i - 1] + memo[i - 1][j - weight[i - 1]], memo[i - 1][j]);
            }
            else{
                memo[i][j] = memo[i - 1][j];
            }
        }
    }
    return memo[n][w];
}




int main(){

    int weight[] = {1, 3, 4, 5};
    int value[] = {1, 4, 9, 7};
    int w = 7;
    int n = 4;
    
    std::vector<std::vector<int>> memo(w + 1, std::vector<int>(n + 1, -1));

    std::cout << knapsack_recurr(weight, value, w, n, memo) << std::endl;
    std::cout << knapsack_iter(weight, value, w, n) << std::endl;

    return 0;
}