#include <iostream>
#include <cstdlib>

using namespace std;

long int sum_arr(int *arr, int n){
	long int sum = 0;
	
	for(int i=0; i<10; i++)
		sum += *(arr+i);
	
	return sum;
}

int main(){
	int arr[10];
	
	for(int i=0; i<10; i++)
		arr[i] = rand()%100;

	long int sum = sum_arr(&arr[0], 10);

	cout << sum << endl;

	return 0;
}