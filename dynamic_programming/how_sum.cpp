#include <iostream>
#include <vector>
#include <algorithm>

 std::vector<int> howSum(int target_sum, std::vector<int> numbers){
    std::vector<std::vector<int>> result(target_sum + 1);
    std::vector<bool> flag(target_sum + 1, false);

    flag[0] = true;

    for(int i = 0; i <=target_sum; i++){
        if(flag[i] == true){
            for(int j = 0; j < numbers.size(); j++){
                if(i + numbers[j] <= target_sum){
                    result[i + numbers[j]] = result[i];
                    result[i + numbers[j]].push_back(numbers[j]);
                    flag[i + numbers[j]] = true;
                }
            }
        }
    }

    return result[target_sum];
}

int main(){
    int target_sum = 7;
    std::vector <int> numbers = {3, 4, 7};
    std::vector<int> result = howSum(target_sum, numbers);

    for(auto v : result){
        std::cout << v <<" ";
    }
    std::cout << std::endl;

    return 0;
}