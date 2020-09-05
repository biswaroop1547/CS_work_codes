#include <iostream>

using namespace std;

typedef struct {
	int real;
	int imag;
} complex;

complex add(complex a, complex b){
	complex sum;
	
	sum.real = a.real + b.real;
	sum.imag = a.imag + b.imag;
	
	return sum;
}

ostream& operator<<(ostream& stream, complex c){
	stream << c.real << '+' << c.imag << 'i';
	return stream;
}

int main(){
	complex a = {1,2};
	complex b = {3,4};

	complex c = add(a,b);

	cout << c << endl;

	return 0;
}