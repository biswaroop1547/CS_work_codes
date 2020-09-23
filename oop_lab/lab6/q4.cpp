#include <iostream>
#include <string>

using namespace std;

class student {
    
public:
	string name;
	int roll;
	int age;

	student(string n, int r, int a): name(n), roll(r), age(a) {}
};

class test: public student {

public:
	int marks[5];

	test(string name, int roll, int age): student(name, roll, age) {};
	
	void take_input(){
		cout << "Enter marks: ";
		
		for(int i=0; i<5; i++){
			cin >> marks[i];
		}
	}

	void print_details(){
		cout << "Name: " << name << endl;
		cout << "Age: " << age << endl;
		cout << "Roll Number: " << roll << endl;

		cout << "Marks: ";

		for(int i=0; i<5; i++){
			cout << marks[i] << ' ';
		}

		cout << endl;
	}
};

int main(){
	int age, roll_no;
	string name;
	cout << "Enter Name Age and Roll Number: ";

	cin >> name >> age >> roll_no;

	test t(name, age, roll_no);
	t.take_input();
	t.print_details();

	return 0;
}