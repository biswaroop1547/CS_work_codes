
#include <iostream>

using namespace std;

typedef struct {
	int data[3][3] = {0};
} matrix;

matrix multiply(matrix a, matrix b){
	matrix product;

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			int p = 0;

			for(int k=0; k<3; k++)
				p += a.data[i][k] + b.data[k][j];

			product.data[i][j] = p;
		}
	}

	return product;
}



int main(){
	matrix a;
	matrix b;

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cin >> a.data[i][j];
		}
	}

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cin >> b.data[i][j];
		}
	}


	matrix c = multiply(a,b);

	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			cout << c.data[i][j] << ' ';
		}

		cout << endl;
	}

	return 0;
}