//Peerapat Saengphoem 6530300376
#include <iostream>
using namespace std;

int main(){
	int in1[5],in2;
	
	cout<< "Enter : " ;
	for(int i=0 ; i<5 ; i++){
		cin >> in1[i];
	}
	
	cout << "(index) | ";
	for(int i=0 ; i<5 ; i++){
		cout << i << " ";
	}
	
		cout <<endl<<endl << "--------|--------------------"<<endl;
		cout << "(value) | ";
		
		for(int i=0 ; i<5 ; i++){
			cout << in1[i] << " ";
		}
		
	cout <<endl<< "Enter value : ";
	cin >> in2 ;
	if(in2 > in1[4]){
		cout << "No Number";
	}
	else{
		for(int i=0 ; i<5 ; i++){
			if(in2 < in1[i]){
				cout << "index = "<<i;
				break;
			}
		}
	}
}
