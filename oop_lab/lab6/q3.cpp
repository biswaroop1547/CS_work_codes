#include<iostream>

using namespace std;

class Circle{
    private:
        int radius;
    public:
        Circle(){
            radius=0;
        }
        void get_radius(){
            cout<<("enter the radius: ");
            cin>>radius;
        }
        float calculate_area(){
            float area;
            area = 3.14*radius*radius;
            return area;
        }
        void show_details(){
            cout<<"radius of the circle: "<<radius<<endl;
            cout<<"Area of the circle: "<<calculate_area()<<endl;
        }
        ~Circle(){
            cout<<"Destructor Invoked"<<endl;
        };
};
int main(){
    Circle c1;
    c1.get_radius();
    c1.show_details();
    return 0;
}