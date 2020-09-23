#include <iostream>

using namespace std;

class a
{

public:
    int x;
    a()
    {
        x = 1;
    }
};
class b
{

public:
    int y;
    b()
    {
        y = 2;
    }
};
class c
{
public:
    a obj1;
    b obj2;
    int z;
    c()
    {
        z = 3;
    }

    void show()
    {
        cout << obj1.x << endl;
        cout << obj2.y << endl;
        cout << z << endl;
    }
};

int main()
{
    c r;
    r.show();
    return 0;
}