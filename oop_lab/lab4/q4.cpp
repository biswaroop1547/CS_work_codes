#include <iostream>
#include <string>

using namespace std;

class Student {
private:
	string name;
	int roll_number = 0;
	int total_marks = 0;
public:
	static float average_m;
	
	void set(string &name, int &roll, int &total) {
		name = name;
		roll_number = roll;
		total_marks = total;
	}

	friend float average(Student *s, int n);
};

float average(Student *s, int n) {
	float avg = 0;

	for(int i=0; i<n; i++){
		avg += (float) (s+i)->total_marks;
	}

	return  avg/(float) n;
}

float Student::average_m = 0;

int main(){
	int n;
	cout << "Enter Number of Students: ";
	cin >> n;

	Student students[n];

	for(int i=0; i<n; i++){
		string name;
		int roll_n, total;

		cout << "Enter Students's Name: ";
		cin >> name;

		cout << "Enter Roll Number: ";
		cin >> roll_n;

		cout << "Enter Total Marks: ";
		cin >> total;

		students[i].set(name, roll_n, total);
	}

	Student::average_m = average(students, n);

	cout << Student::average_m << endl;

	return 0;
}