#include<iostream>

using namespace std;

int main(){
    const double PI = 3.1415926535;
    cout << "enter radius of the circle: ";
    double radius;
    cin >> radius;
    cout << "area of the circle is : " << PI * radius * radius << '\n';   
}