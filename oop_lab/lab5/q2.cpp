#include <iostream>

using namespace std;

class Time {
public:
	int hh;
	int mm;

	Time(){
		hh = 0;
		mm = 0;
	}

	Time(int h, int m=0) {
		hh = h;
		mm = m;
	}
	
	Time(const Time& other) {
		hh = other.hh;
		mm = other.mm;
	}

	void print(){
		cout << "The Time is " << hh << ':' << mm << endl;
	}
	
	~Time() {
		cout << "Destructor Invoked" << endl;
	}

};

int main(){
	Time a;
	Time b(10, 21);
	Time c(5);

	Time d = b;

	a.print();
	b.print();
	c.print();
	d.print();

	return 0;
}