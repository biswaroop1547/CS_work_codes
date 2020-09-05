
#include <iostream>

using namespace std;

int main(){
	int a = 10;
	int b = 20;

	int *a_ptr = &a;
	int *b_ptr = &b;

	cout << *a_ptr + *b_ptr << endl;


	return 0;
}