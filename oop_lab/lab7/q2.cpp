#include<iostream>

using namespace std;

class Biscuit{
    public:
        string company;
        string name;
};

class Dealer: public Biscuit
{   
    public:
        string product_name = name;
        float price;
};

class Retailer: public Dealer
{
    float sell_price;
    public:
        Retailer(string com, string nam, float pr){
            company = com;
            name = nam;
            price = pr;
            sell_price = pr+0.025*pr;
        }
        void calculate(){
            sell_price = 1.025*price;
        }
        void display(){
            cout<<"the name of company: "<<company<<endl;
            cout<<"the name of the product: "<<name<<endl;
            cout<<"price of the product: "<<price<<endl;
            cout<<"sell price: "<<sell_price<<endl;
        }
};
int main()
{
    Retailer r("Parle","G", 10);
    r.display();
    return 0;
}