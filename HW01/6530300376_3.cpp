//Peerapat Saengphoem 6530300376
#include <iostream>
using namespace std;

int main(){
	int i,j,in1;
	char a[5][5]={ 
	{'S','T','L','Y','R'}, 
	{'T','H','E','M','E'}, 
	{'A','N','A','G','O'}, 
	{'R','O','P','E','S'},
	{'K','T','T','U','C'}};
	
	cout << "input : ";
	cin >> in1;
	
	for(i=0 ; i<=5 ; i++){
		for(j=0;j<i;j++){
			cout << a[in1-1][j];
		}
		if(i>0){
			cout <<  " ";
		}
	}
}
