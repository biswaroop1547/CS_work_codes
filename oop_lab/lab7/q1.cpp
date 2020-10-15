#include <iostream>

using namespace std;

class Consumer
{
public:
    string c_name;
    int c_number;
    string date;
    int no_of_units;

    void input(){
        cout << "Enter Consumer name: " << endl;
        cin >> c_name;
        cout << "Enter Consumer number: " << endl;
        cin >> c_name;
        cout << "Enter Date: ";
        cin >> date;
        cout << "Enter Number of units: " << endl;
        cin >> no_of_units;
    }
};

class Electricity : public Consumer
{
public:
    int price;
    void calculate(){
        if (no_of_units >= 0 && no_of_units < 50 ){
            price = no_of_units * 2.5;
        } else if (no_of_units >= 50 && no_of_units < 200) {
            price = no_of_units * 4.3;
        } else if (no_of_units >= 200 && no_of_units < 400) {
            price = no_of_units * 5.3;
        } else if (no_of_units >= 400) {
            price = no_of_units * 5.7;
        }
    }
    void display(){
        cout << "Bill of the current month: " << price << endl;
    }
};

int main(){

    Electricity c1;
    c1.input();
    c1.calculate();
    c1.display();
    return 0;
}