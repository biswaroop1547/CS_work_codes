#include <iostream>

using namespace std;

class Entity {
public:
	int data;
	
	Entity() {
		cout << "I am the Constructor" << endl;
	}

	void set(int a) {
		data = a;
		cout << "I am the Method" << endl;
	}
	
	~Entity() {
		cout << "I am the Destructor" << endl;
	}
};

int main(){
	Entity a;
	a.set(10);

	return 0;
}