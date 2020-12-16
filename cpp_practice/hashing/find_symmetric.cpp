#include <iostream>
#include <unordered_set>
#include <vector>
#include <string>
#include <utility>

using namespace std;

template <typename T>
string pair_to_str(const pair<T, T> &data, bool reverse = false){
    return reverse ? "{" + (to_string(data.second) + ", " + to_string(data.first)) + "}": \
                     "{" + (to_string(data.first) + ", " + to_string(data.second)) + "}";
}

template <typename T>
string findSymmetric(const vector<pair <T, T>> &data) {
    
    unordered_set<string> set;
    
    string symmetric = "";

    for(pair<T, T> num_pair : data) {
        if(set.find(pair_to_str(num_pair, true)) == set.end()){
            set.insert(pair_to_str(num_pair));
        }
        else{
            symmetric += pair_to_str(num_pair) + pair_to_str(num_pair, true);
        }
    }
    return symmetric;
}


int main() {

    // int input_length;
    // cin >> input_length;
    // vector<int> data{3, 4, 3, 2, 5, 9, 4, 3, 9, 5, 2, 3, 6, 8};
    vector<pair <int, int>> data = {{3, 4}, {1, 2}, {5, 9}, {4, 3}, {9, 5}};
    // for(int i = 0; i < input_length; ++i){
    //     int num;
    //     cin >> num;
    //     data.push_back(num);
    // }
    cout << findSymmetric(data) << endl;
    
    return 0;
}