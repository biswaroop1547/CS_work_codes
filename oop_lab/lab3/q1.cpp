#include <iostream>
using namespace std;

typedef struct CIRCLE {
	int radius;
} circle;

typedef struct RECTANGLE {
	int length;
	int breadth;
} rectangle;

typedef struct TRIANGLE {
	int base;
	int height;
} triangle;


float area(circle c) {
	return (float) 3.14159*c.radius*c.radius;
}

float area(rectangle r) {
	return (float) r.length * r.breadth;
}

float area(triangle t) {
	return (float) 0.5 * t.base * t.height; 
}

int main(){
	short int n;

	cout << "Choose a shape: " << endl;
	cout << "1. Circle" << endl;
	cout << "2. Rectangle" << endl;
	cout << "3. Triangle" << endl;
	cout << "Enter Choice: ";
	cin >> n;

	if(n==1){
		int r;
		cout << "Enter Radius: ";
		cin >> r;
		circle c {r};
		cout << "Area is: " << area(c) << endl;

	} else if (n==2) {
		int l,b;
		cout << "Enter L and B: ";
		cin >> l >> b;
		rectangle r { l, b };
		cout << "Area is: " << area(r) << endl;
	} else if (n==3){
		int b,h;
		cout << "Enter B and H: ";
		cin >> b >> h;
		triangle t { b, h };
		cout << "Area is: " << area(t) << endl;
	} else {
		cout << "Invalid Choice" << endl;
	}

	return 0;
}