#include<iostream>

using namespace std;

int main(){
    int a, b, c;
    int greatest;
    printf("Enter the three numbers: ");
    cin >> a >> b >> c;
    if (a > b  &&  a > c){
        cout << "greatest number is: " << a << '\n';
    }
    else if(b > a && b > c){
        cout << "greatest number is: " << b << '\n';
    }

    else if(c > a && c > b){
        cout << "greatest number is: " << c << '\n';
    }

    else{
        cout << "greatest number is: " << a << '\n';
    }

}