//Peerapat Saengphoem 6530300376
#include <iostream>
using namespace std;

int main(){
	
	int Num[10];
	
	cout << "Enter : ";
	
	for(int i=0; i< 10 ; i++){
		cin >> Num[i];
	}
	
	cout << "Output :";
	for(int j=9; j>=0 ; j--){
		
		cout << " " << Num[j];
	}
	
	return 0;
}
