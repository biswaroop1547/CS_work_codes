#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

template <typename T>
bool isDisjoint(const vector <T>&vec1, const vector<T> &vec2) {
    
    unordered_set<T> set;

    for(T &val : vec1){
        set.insert(val);
    }

    for(T val : vec2){
        if(set.find(val) != set.end()) {return false;}
    }

    return true;
}


int main() {

    vector<int> data1{ 9, 4, 7, 1, -2, 6, 5 };
    vector<int> data2{ 7, 1, -2 };

    cout << ((isDisjoint(data1, data2)) ? "True" : "False") << endl;
    
    return 0;
}