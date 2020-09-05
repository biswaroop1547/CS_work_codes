#include <iostream>

using namespace std;

class IntClass {
private:
	int data;
public:
	static int run_count;

	void set(int d) {
		run_count++;
		data = d;
	}

	int get() {
		run_count++;
		return data;
	}
};

int IntClass::run_count = 0;

int main(){
	IntClass a;
	IntClass b;
	a.set(10);
	b.set(20);

	cout << a.get() << endl;
	cout << a.get() << endl;
	cout << b.get() << endl;
	cout << b.get() << endl;

	cout << IntClass::run_count << endl;

	return 0;
}