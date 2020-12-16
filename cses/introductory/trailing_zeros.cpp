//https://cses.fi/problemset/task/1618

#include <iostream>

int main(){

    unsigned long long int  num;
    std::cin >> num;

    unsigned long long int fives = 0;
    for(unsigned long long int  i = 5; num / i >= 1; i *= 5){
        fives += num / i;
    }
    unsigned long long int  zeros = fives;
    std::cout << zeros << std::endl;
    
    return 0;
}