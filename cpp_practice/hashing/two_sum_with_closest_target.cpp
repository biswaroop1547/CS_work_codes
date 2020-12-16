#include <unordered_set>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>

using namespace std;

pair<int, int> longest_movie_pair(vector <int>movie_duration, int flight_duration) {
    sort(movie_duration.begin(), movie_duration.end(), greater<int>());

    int g_index = 0;
    int l_index = movie_duration.size() - 1;
    pair<int, int> req_pair = make_pair(movie_duration.at(g_index), movie_duration.at(l_index));

    int highest_movie_duration_sum = movie_duration.at(l_index);

    while(g_index < l_index ){
        int big_element = movie_duration.at(g_index);
        int small_element = movie_duration.at(l_index);
        int current_movie_duration_sum = big_element + small_element;
        if(current_movie_duration_sum > flight_duration){
            g_index++;
        }
        else if(current_movie_duration_sum < flight_duration){
            if(current_movie_duration_sum > highest_movie_duration_sum){
                highest_movie_duration_sum = current_movie_duration_sum;
                req_pair.first = movie_duration.at(g_index);
                req_pair.second = movie_duration.at(l_index);
            }

            l_index--;
        }

        cout << current_movie_duration_sum << endl;
    }

    return req_pair;
}


int main() {

    int flight_duration = 250;
    vector<int> movie_durations{ 40, 85, 75, 60, 120, 150, 125 };

    pair<int, int> longest_movie_duration_pair = longest_movie_pair(movie_durations, flight_duration - 30);

    int index1, index2;
    for(int idx = 0; idx < movie_durations.size(); ++idx){
        if(longest_movie_duration_pair.first == movie_durations.at(idx)){
            index1 = idx;
        }

        if(longest_movie_duration_pair.second == movie_durations.at(idx)){
            index2 = idx;
        }
    }

    cout << "required indexes are - (" << index1 << "," << index2 << ")" << endl;

    return 0;
}