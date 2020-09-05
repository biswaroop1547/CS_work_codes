#include <iostream>

using namespace std;

void swap(int& a, int& b){
	int t = a;
	a = b;
	b = t;
}


int main(){
	int a, b;
	cout << "Enter 2 numbers: ";
	cin >> a >> b;

	cout << "Before Swap: " << a << ' ' << b << endl;
	swap(a,b);
	cout << "After Swap: " << a << ' ' << b << endl;

	return 0;
}