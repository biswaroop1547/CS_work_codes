#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, x, y;
        cin >> n >> x >> y;
        long long start_range = pow(10, n - 1);
        long long end_range = pow(10, n);
        long long out = 0;
        for(long long i = start_range; i < end_range; i++){
            if((i % x == 0)&&(i % y == 0)){
                out = (out + 1) % (long long)(pow(10, 9) + 7);
            }
        }

        printf("%lld\n", out);
    }
}