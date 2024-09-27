//Peerapat Saengphoem 6530300376
#include <iostream>
using namespace std;

int main(){
	
	int matrix[3][3];
	
	for(int i=0 ; i<3 ; i++){//row loop
		cout << "Enter row #" << i << " : ";
		for(int j=0 ; j<3 ; j++){//col loop
			cin >> matrix[i][j];
		}
		cout << endl ;
	}
	
	cout << "Transpose" << endl << endl;
	
	for(int i=0 ; i<3 ; i++){//row loop
		for(int j=0 ; j<3 ; j++){//col loop
			cout << matrix[j][i] << " ";
		}
		cout << endl << endl;
	}	
	return 0;
}
