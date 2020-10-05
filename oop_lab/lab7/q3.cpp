#include <iostream>
#include <string>

using namespace std;

class College {
private:
	string name = "College Name";
public:
	void showIt() {
		cout << name << endl;
	}
};

class Board {
private:
	string name;
public:
	void inputName() {
		cout << "Enter Name: ";
		cin >> name;
	}
};

class MyClass : public College, public Board {
private:
	string myname;
public:
	void input(){
		cout << "Enter Name: ";
		cin >> myname;
	}
};

int main() { 
	College c;
	Board b;
	MyClass m;

	m.showIt();
	m.inputName();
	m.input();

	return 0;
}