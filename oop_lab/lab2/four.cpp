#include<iostream>

using namespace std;

int main(){
    int arr[100];
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int greatest = arr[0], smallest = arr[0];
    for(int i = 0; i < n; i++){
        if(greatest < arr[i]){
            greatest = arr[i];
        }
        if(smallest > arr[i]){
            smallest = arr[i];
        }
    }

    printf("Greatest no. : %d\nSmallest no. : %d\n", greatest, smallest);
    

}