#include<iostream>

using namespace std;
 
int main()
{
    int n, sum=0;
    cout << "enter a number: ";
    cin >> n;

    while(n > 0)
    {
        sum += n;
        n--;
    }
    
    cout << "SUM = " << sum << endl;
    
    return 0;
}
