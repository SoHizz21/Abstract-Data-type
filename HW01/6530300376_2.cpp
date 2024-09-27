//Peerapat Saengphoem 6530300376
#include <iostream>
using namespace std;

int main(){
	int in1 ,in2=0,in3 ,arr[10], size;
	int loop=1;
	
	while(loop){
		cout << "========MENU======" << endl;
		cout << "   1) Insert the first value" << endl;
		cout << "   2) Insert front" << endl;
		cout << "   3) Insert last" << endl;
		cout << "   4) Insert middle" << endl;
		cout << "   5) Exit" << endl;
		cout << "Please choose > ";
		
		cin >> in1;
		
		if(in1 == 1){
			cout  << "Data in list = ";
			cin >> in2;
			arr[0] = in2 ;
			size++;
			in2 = 0;	
		}
		
		else if(in1 == 2){
			cout << "Enter data : ";
			cin >> in2;
			cout << "Move = " << size << " Position" <<endl;
			for(int i=8 ; i>=0 ; i--){
				arr[i+1] = arr[i];
			}
			arr[0] = in2;
			size++;
			in2 = 0;
			
			cout << "Data in list : ";
			for(int i=0 ; i<size ; i++){
				cout << arr[i] << " ";
			}	
			cout << endl;
		}
		
		else if(in1 == 3){
			cout << "Enter data : ";
			cin >> in2;
			cout << "Move = " << size << " Position" <<endl;
			arr[size] = in2;
			size++;
			in2 = 0;
			
			cout << "Data in list : ";
			for(int i=0 ; i<size ; i++){
				cout << arr[i] << " ";
			}	
			cout << endl;
		}
		else if(in1 == 4){
			cout << "Enter data : ";
			cin >> in2;
			cout << "Move = " << size << "Position" << endl;
			for(int i=8 ; i>=size/2 ; i--){
				arr[i+1] = arr[i];
			}
			arr[size/2] = in2;
			size++;
			in2 = 0;
			
			cout << "Data in list : ";
			for(int i=0 ; i<size ; i++){
				cout << arr[i] << " ";
			}
			cout << endl;
		}
		else if(in1 == 5){
			cout << "Enter : -1" << endl << "Output = Bye";
			loop=0;
		}
	}
}
