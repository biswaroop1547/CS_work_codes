#include <iostream>
#include <string>
using namespace std;

class Employee{
    private:
        string name;
        int id;
        int salary;

    public:
        Employee(){
            name="name";
            id=0;
            salary=0;
            cout << "Default." << endl;
        }

        Employee(string n, int i, int sal){
            name=n;
            id=i;
            salary=sal;
            cout << "Parameterized." << endl;
        }

        Employee(Employee &n){
            name = n.name;
            id = n.id;
            salary = n.salary;
            cout << "Copy." << endl;
        }

        void display(){
            cout << "Name: " << name << endl;
            cout << "ID: " << id << endl;
            cout << "Salary: Rs. " << salary << endl << endl;
        }
    
};

int main() {
    Employee e1,e2("hello",15,1000),e3;

    e3=e2;

    e1.display();
    e2.display();
    e3.display();
    return 0;
}