#include <iostream>

int pow_func_recurr(int x, int n){
    if(n == 0){
        return 1;
    }

    else if(n == -1){
        return 1/x;
    }

    else if(n % 2 == 0){
        return pow_func_recurr(x, n / 2) * pow_func_recurr(x, n / 2);
    }

    return x * pow_func_recurr(x, (n - 1) / 2) * pow_func_recurr(x, (n - 1) / 2);
}



int pow_func_iter(int x, int n){
    int result = 1;
    if(n < 0){
        x = 1 / x;
        n = -n;
    }

    while(n > 0){
        if(n % 2 == 1){
            result *= x;
        }
        x *= x;
        n >>= 1;
    }

    return result;
}



int main(){

    int x = 3;
    int n = 7;

    std::cout << pow_func_recurr(x, n) << std::endl;
    std::cout << pow_func_iter(x, n) << std::endl;
    return 0;
}