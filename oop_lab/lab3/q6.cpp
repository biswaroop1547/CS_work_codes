#include <iostream>
using namespace std;

int increase(int &x)
{
    x++;
    return x;
}

int main()
{
    int n;
    cout << "enter the number" << endl;

    cin >> n;

    cout << "the incremented number is " << increase(n) << endl;
    return 0;
}