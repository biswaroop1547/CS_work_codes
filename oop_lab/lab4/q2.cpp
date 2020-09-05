#include<iostream>
using namespace std;

class Length_feet;
class Length_meters;

class Length_meters{
    private:
        int meters, centimeters;
    public:
        void input_length()
        {   
            int length; 
            cout<<"Enter a length in centimeters";
            cin>> length;
            meters = length/100;
            centimeters = length%100;
        }
        void output_length(){
            cout << "Length = "<< meters<< " meters "<< centimeters << " centimeters"<<endl;
        }
        friend void compare_lengths(Length_meters m, Length_feet f);
};

class Length_feet{
    private:
        int feet, inches;
    public:
        void input_length(){
            int length;
            cout<<"Enter a length in inches";
            cin>>length;
            feet = length / 12;
            inches = length % 12;
        }
        void output_length(){
            cout << "Length = "<< feet << " feet "<< inches << " inches"<<endl;
        }
        friend void compare_lengths(Length_meters m, Length_feet f);
};

void compare_lengths(Length_meters m, Length_feet f){
    float len_cm, len_in;
    len_cm = m.meters*100 + m.centimeters;
    len_in = f.feet*12 + f.inches;

    cout<<"The larger lentgh is: ";
    if(2.54*len_in > len_cm){
        cout << "Length = "<< f.feet << " feet "<< f.inches << " inches"<<endl;
    }
    else{
        cout << "Length = "<< m.meters<< " meters "<< m.centimeters << " centimeters"<<endl;
    }
}

int main(){

    Length_feet in_len;
    Length_meters cm_len;

    cm_len.input_length();
    cm_len.output_length();
    in_len.input_length();
    in_len.output_length();

    compare_lengths(cm_len, in_len);

    return 0;
}