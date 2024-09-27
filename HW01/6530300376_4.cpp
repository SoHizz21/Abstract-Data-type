//Peerapat Saengphoem 6530300376
#include <iostream>
using namespace std;

int main(){
	int in1;
	string db[14]={"STLY", "THEME", "THE" , "THEM" , "HE" , "ME" , "AN" , "GO", "AGO", "ROPE", "OPE", "OGA", "CUT", "OR"};
	char a[5][5]={ 
	{'S','T','L','Y','R'}, 
	{'T','H','E','M','E'}, 
	{'A','N','A','G','O'}, 
	{'R','O','P','E','S'},
	{'K','T','T','U','C'}};
	
	cout << "===========================" << endl;
	cout << "\t  MENU" << endl;
	cout << "===========================" << endl;
	cout << "1.Print from front" << endl;
	cout << "2.Print from back" << endl;
	cout << "3.Match data base" << endl;
	
	cout << "Please choose > ";
	cin >> in1;
	
	if(in1 == 1){
		cout << "OUTPUT : ";
		for(int z=0; z<5 ; z++){
		
			for(int i=0 ; i<5 ;i++){
				for(int j=i ; j<5 ; j++){
					for(int k=i ; k<=j ; k++){
						cout << a[z][k];
					}
					cout << " ";
				}
			}
			cout << endl;
		}
	}
	
	
	else if(in1 == 2){
	cout << "OUTPUT : ";
	for(int z=0; z<5 ; z++){
		
		for(int i=4 ; i>=0 ;i--){
			for(int j=i ; j>=0 ; j--){
				for(int k=i ; k>=j ; k--){
					cout << a[z][k];
				}
				cout << " ";
			}
		}
		cout << endl;
	}
	}
	
	
	else if(in1 == 3)
	{
		int count = 0 ;
		string Checkdb="";
		
		for(int z=0; z<5 ; z++){
			for(int i=0 ; i<5 ;i++){
				for(int j=i ; j<5 ; j++){
					for(int k=i ; k<=j ; k++){
						cout << a[z][k];
						Checkdb += a[z][k];
						for(int l=0 ; l<14 ; l++){
							if(Checkdb == db[l]){
								count++;
								cout << " Found " << count;
								db[l] = "";
							}
						}
					}
					Checkdb.clear();
					cout << endl;
				}
			}
		}
		
		for(int z=0; z<5 ; z++){
			for(int i=4 ; i>=0 ;i--){
				for(int j=i ; j>=0 ; j--){
					for(int k=i ; k>=j ; k--){
						cout << a[z][k];
						Checkdb += a[z][k];
						for(int l=0 ; l<14 ; l++){
							if(Checkdb == db[l]){
								count++;
								cout << " Found " << count;
								db[l]="";
							}
						}
					}
					Checkdb.clear();
					cout << endl;
				}
			}
		}
		cout << "total = " << count;		
	}
}
