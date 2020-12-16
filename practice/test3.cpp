#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <utility>

/* 3 5 0
B8B3B
53243
32452

2 2 2

  38

  4B
*/

using namespace std;

template <typename DataType>
class Heap {
    vector<DataType> data;
    bool is_max_heap;
    vector<int> i;
    vector<int> j;

    int getParentIndex(int child_index) {
        return (child_index - 1) / 2;
    }

    int getLeftChildIndex(int parent_index) {
        return 2 * parent_index + 1;
    }

    int getRightChildIndex(int parent_index) {
        return 2 * parent_index + 2;
    }

    void maxHeapify(int parent_index) {
        int max_ele_ind = parent_index;
        int left_child_ind = getLeftChildIndex(parent_index);
        int right_child_ind = getRightChildIndex(parent_index);

        if (left_child_ind < this->getSize() && data.at(left_child_ind) > data.at(max_ele_ind)) {
            max_ele_ind = left_child_ind;
        }
        if (right_child_ind < this->getSize() && data.at(right_child_ind) > data.at(max_ele_ind)) {
            max_ele_ind = right_child_ind;
        }
        if (max_ele_ind != parent_index) {
            swap(data.at(max_ele_ind), data.at(parent_index));
            swap(i.at(max_ele_ind), i.at(parent_index));
            swap(j.at(max_ele_ind), j.at(parent_index));
            maxHeapify(max_ele_ind);
        }
    }

    void minHeapify(int parent_index) {
        int min_ele_ind = parent_index;
        int left_child_ind = getLeftChildIndex(parent_index);
        int right_child_ind = getRightChildIndex(parent_index);

        if (left_child_ind < this->getSize() && data.at(left_child_ind) < data.at(min_ele_ind)) {
            min_ele_ind = left_child_ind;
        }
        if (right_child_ind < this->getSize() && data.at(right_child_ind) < data.at(min_ele_ind)) {
            min_ele_ind = right_child_ind;
        }
        if (min_ele_ind != parent_index) {
            swap(data.at(min_ele_ind), data.at(parent_index));
            swap(i.at(min_ele_ind), i.at(parent_index));
            swap(j.at(min_ele_ind), j.at(parent_index));
            minHeapify(min_ele_ind);
        }
    }

   public:
    Heap(string type) {
        this->is_max_heap = (type.compare("max") == 0) ? true : false;
    }

    void push(DataType key, int i_ind, int j_ind) {
        data.push_back(key);
        i.push_back(i_ind);
        j.push_back(j_ind);
        if (is_max_heap) {
            maxHeapify(this->getParentIndex(this->getSize() - 1));
        } else {
            minHeapify(this->getParentIndex(this->getSize() - 1));
        }
    }

    void pop() {
        if (this->getSize() > 0) {
            swap(this->data.at(0), this->data.at(this->getSize() - 1));
            swap(this->i.at(0), this->i.at(this->getSize() - 1));
            swap(this->j.at(0), this->j.at(this->getSize() - 1));
            this->data.pop_back();
            this->i.pop_back();
            this->j.pop_back();
            // cout << "lol" << endl;
            if (is_max_heap) {
                maxHeapify(0);
            } else {
                minHeapify(0);
            }
        }
    }

    int getSize() {
        return this->data.size();
    }

    int getTop() {
        return this->data.front();
    }

    int getTopI() {
        return this->i.front();
    }
    int getTopJ() {
        return this->j.front();
    }

    void display() {
        for (int ind = 0; ind < this->getSize(); ++ind) {
            cout << this->data.at(ind) << " " << this->i.at(ind) << " " << this->j.at(ind) << endl;
        }
        cout << "\n";
    }
};

void extractIntegerWords(string str, int &n, int &m, int &k){ 
    stringstream ss;
    ss << str;
    string temp; 
    int found; 
    int num_found = 0;
    while (!ss.eof()) { 
        ss >> temp; 
        if (stringstream(temp) >> found){
          if(num_found == 0) n = found;
          else if(num_found == 1) m = found;
          else k = found;
          num_found++;
        }
            
        temp = ""; 
    } 
} 

int to_num(char ch) {
    return ch - '0';
}


int main(int argc, char *argv[]) {


  string line;
  int index = 1;
  int n = 0, m = 0, k = 0;
  getline(cin, line);
  extractIntegerWords(line, n, m, k);
  int element = 0, bomb = 1, burst = 2;
  char arr[n][m][3]; // 0 contains the element, 1 contains if it is a bomb, 2 contains if it will burst
  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      cin >> arr[i][j][element];
      if(arr[i][j][element] == 'B'){
        arr[i][j][bomb] = '1';

      }
      else{
        arr[i][j][bomb] = '0';
      }

      arr[i][j][burst] = '0';
    }
  }

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      if(arr[i][j][bomb] == '1'){
        for(int col = 0; col < m; ++col){
          arr[i][col][burst] = '1';
        }

        for(int row = 0; row < n; ++row){
          arr[row][j][burst] = '1';
        }

      }
    }
  }

  Heap<int> not_affected("min");
  Heap<int> is_affected("max");

  for(int i = 0; i < n; ++i){
    for(int j = 0; j < m; ++j){
      if(arr[i][j][burst] == '1'){
        is_affected.push(to_num(arr[i][j][element]), i, j);
      }
      else if(arr[i][j][burst] == '0'){
          not_affected.push(to_num(arr[i][j][element]), i, j);
      }
    }
  }
    // cout << is_affected.getTop() << ", " << not_affected.getTop() << endl;
    while (k--) {
        if (is_affected.getTop() < not_affected.getTop()) {
            // cout << "hello lol" << endl;
            break;
        }
        swap(arr[is_affected.getTopI()][is_affected.getTopJ()][element], arr[not_affected.getTopI()][not_affected.getTopJ()][element]);
        is_affected.pop();
        not_affected.pop();
    }

    int final_sum = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(!to_num(arr[i][j][burst])){
                final_sum += to_num(arr[i][j][element]);
            }   
        }
    }

    cout << final_sum << endl;

    return 0;
}
