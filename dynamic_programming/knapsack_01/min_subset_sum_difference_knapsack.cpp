#include<iostream>
#include<vector>
#include<climits>

int minSubsetSumDifference(int value[], int n){
    int range = 0;
    for(int i = 0; i < n; i++){
        range += value[i];
    }
    bool memo[n + 1][range + 1];

    for(int i = 0; i < n + 1; i++){
        for(int j = 0; j < range + 1; j++){
            if(i == 0){
                memo[i][j] = false;
            }
            if(j == 0){
                memo[i][j] = true;
            }
        }
    }

    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < range + 1; j++){
            if(value[i - 1] <= j){
                memo[i][j] = memo[i - 1][j - value[i - 1]] || memo[i - 1][j];
            }
            else{
                memo[i][j] = memo[i - 1][j];
            }
        }
    }
   std::vector<int> min_vec;
   for(int j = 0; j < ((range + 1) / 2 ) + 1; j++){
       if(memo[n][j] == true){
           min_vec.push_back(j);
       }
   }
   
   int min_diff = INT_MAX;
   
   for(int i = 0; i < min_vec.size(); i++){
       min_diff = std::min(min_diff, range - (2*min_vec[i]));
   }

   return min_diff;
}


int main(){

    int value[] = {1, 2, 7};
    int n = 3;
    std::cout << minSubsetSumDifference(value, n) << std::endl;
    return 0;
}