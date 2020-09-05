#include <iostream>

using namespace std;

class Complex {
public:
	int real, imag;

	Complex() {
		real = 0;
		imag = 0;
	}

	Complex(int r, int i) {
		real = r;
		imag = i;
	}

	Complex(const Complex& other){
		real = other.real;
		imag = other.imag;
	}

	void print(){
		cout << real << '+' << imag << 'i' << endl;
	}

	~Complex(){
		cout << "Destructor Invoked" << endl;
	}
};

int main(){
	Complex a;
	Complex b(1,2);

	Complex c = b;

	a.print();
	b.print();
	c.print();

	return 0;
}