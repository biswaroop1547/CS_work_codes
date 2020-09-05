#include <iostream>

using namespace std;
class b;
class a{
    int x;

    public:
        void assign(int t){
            x = t;
        }

        void display(){
            cout << "Value of x is : " << x << endl;
        }
        friend void swap(a &, b &);
};

class b{
    int y;

    public:
        void assign(int w){
            y = w;
        }
        void display(){
            cout << "Value of y is : "<< y << endl;
        }
        friend void swap(a &, b &);
};

void swap(a &c, b &d){
    int temp;
    temp = c.x;
    c.x = d.y;
    d.y = temp;
}

int main(){
    a n;
    b m;
    int a, b;
    cout <<"Enter x: ";
    cin >> a;
    cout << "Enter y: ";
    cin >> b;

    n.assign(a);
    m.assign(b);

    swap(n, m);
    n.display();
    m.display();
}