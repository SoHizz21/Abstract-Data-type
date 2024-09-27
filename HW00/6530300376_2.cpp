//Peerapat Saengphoem 6530300376
#include <iostream>
#include <cmath>
using namespace std;

int Checkprime(int Num){	
	if(Num<2){
		return false;
	}
	else{
		int i=2;
		while(i <= sqrt(Num)){
			if (Num%i == 0){
				return false;
			}
			i++;
		}
		return true;
	}
}

int main(){
	int Num;
	
	cout << "input : ";
	cin >> Num;
	
	if(Checkprime(Num)==1){
		cout << "Prime";	
	}
	else{
		cout << "Not Prime";
	}
	return 0;
}
