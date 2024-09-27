//Peerapat Saengphoem 6530300376
#include <iostream>
using namespace std;

int main(){
	
	int in1;
	cout << "Enter : ";
	cin >> in1;
	
	int x[15]={0,1,1};
	
	for(int i=3; i<15; i++){
		x[i] = x[i-1]+x[i-2];
	}
	
	for(int i=0 ; i<15 ;i++){
		if(in1 == i){
			cout << "Fibonacci of "<< i << " = " << x[i];
		}
		else if(in1 >=  15){
			cout << "Error, more than 15";
			break;
		}
	}	
}
