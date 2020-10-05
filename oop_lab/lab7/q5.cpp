#include <iostream>
using namespace std;

class a
{
public:
    a()
    {
        cout << "first constructor called" << endl;
    }
    ~a()
    {
        cout << "first destructor called" << endl;
    }
};

class d : public a
{
public:
    d()
    {
        cout << "fourth constructor called" << endl;
    }
    ~d()
    {
        cout << "fourth destructor called" << endl;
    }
};

class e : public d
{
public:
    e()
    {
        cout << "fifth constructor called" << endl;
    }
    ~e()
    {
        cout << "fifth destructor called" << endl;
    }
};

int main()
{

    e E;
    return 0;
}