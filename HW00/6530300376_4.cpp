//Peerapat Saengphoem 6530300376
#include <iostream>
using namespace std;

int main(){	
	int Num;
	
	cout <<  "input : ";
	cin >> Num;
	
	for(int i=1 ; i<=Num ; i++){//loop1
		for(int j=i ; j<=Num ; j++){//loop2
			for(int k=i ; k<=j ; k++){//loop3
				cout << k ;
			}
			cout << " ";
			if(i == Num){
				cout << Num;
			}			
		}
	cout << endl;
	}
	return 0;
}
