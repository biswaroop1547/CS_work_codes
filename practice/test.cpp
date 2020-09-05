#include<iostream>

using namespace std;

long long arr[1000000] = {0};

int helper(int n){

    if(n == 1){
        return 0;
    }

    int a = helper(n - 1);
    int min_val = a;

    if(n % 2 == 0){
        int b;
        if(arr[n] == 0){
            b = helper(n / 2);
            arr[n] = b;
        }
        else{
            b = arr[n];
        }
        min_val = min(min_val, b);
    }

    if(n % 3 == 0){
        int c;
        if(arr[n] == 0){
            int c = helper(n / 3);
            arr[n] = c;
        }
        else{
            c = arr[n];
        }
        min_val = min(min_val, c);
    }
    

    return min_val + 1;

}


int main(){
    int n, a[100];
    scanf("%d", &n);

    int result = helper(n);
    printf("%d\n", result);
}