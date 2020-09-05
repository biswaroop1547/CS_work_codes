#include<iostream>
using namespace std;

void print_char(char ch, int n){
    for(int i=0;i<n;i++){
        cout<<ch<<" ";
    }
    cout<<endl;
}
void print_char(char ch){
    for(int i=0;i<80;i++){
        cout<<ch<<" ";
    }
    cout<<endl;
}
void print_char(){
    for(int i=0;i<80;i++){
        cout<<"* ";
    }
    cout<<endl;
}
int main(){

    int n;
    char ch1, ch2;

    cout<<"Enter both the character and no. of times: ";
    cin>>ch1>>n;
    cout<<"Enter only the character: ";
    cin>>ch2;
    print_char(ch1, n);
    print_char(ch2);
    print_char();
    
    return 0;
}