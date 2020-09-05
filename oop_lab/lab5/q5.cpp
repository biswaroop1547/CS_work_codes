#include <iostream>

using namespace std;

class Entity {
public:
	static int count;
	
	Entity() {
		count++;
		cout << "I am the Constructor" << endl;
	}

	static void print_count(){
		cout << count << endl;
	}
	
	~Entity() {
		cout << "I am the Destructor" << endl;
	}
};

int Entity::count = 0;

int main(){
	Entity a;
	Entity b;
	Entity c;
	Entity d;

	Entity::print_count();

	return 0;
}