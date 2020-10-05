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
class b
{
public:
    b()
    {
        cout << "second constructor called" << endl;
    }
    ~b()
    {
        cout << "second destructor called" << endl;
    }
};

class c : public a, public b
{
public:
    c()
    {
        cout << "tisra constructor called" << endl;
    }
    ~c()
    {
        cout << "third destructor called" << endl;
    }
};

int main()
{

    c C;

    return 0;
}