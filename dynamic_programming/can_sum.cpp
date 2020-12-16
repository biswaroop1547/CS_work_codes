#include <iostream>
#include <algorithm>

bool canSum(int target_sum, int *numbers, int n){
     bool *result = new bool[target_sum + 1];
     std::fill_n(result, target_sum + 1, false);

     result[0] = true;

     for(int idx_target = 0; idx_target <= target_sum; ++idx_target){
         if(result[idx_target]){
             for(int idx_num = 0; idx_num < n; ++idx_num){
                 if(idx_target + numbers[idx_num] <= target_sum){
                     result[idx_target + numbers[idx_num]] = true;
                 }
             }
         }
     }

     return result[target_sum];
}

int main(){
    int target_sum = 7;
    int numbers[] = {1, 3, 4, 7};
    int n = 4;

    std::cout << (canSum(target_sum, numbers, n)? "True" : "False") << std::endl;
    return 0;
}