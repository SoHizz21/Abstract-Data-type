#include <iostream>
#include <sstream>
using namespace std;

int menu(){
	int in1;
	cout << "=======MENU =======" << endl;
	cout << "1) Insert data to array" << endl;
	cout << "2) Build Heap" << endl;
	cout << "3) Heap Sort" << endl;
	cout << "4) Heap insert" << endl;
	cout << "5) Priority Queue" << endl;
	cout << "6) Extract Max " << endl;
	cout << "Please choose > ";
	cin >> in1;
	return in1;
}

int A[30];
int heapsize=0;
int length;
	
int parents(int i){
	return i/2;
}
int left(int i){
	return 2*i;
}
int right(int i){
	return 2*i+1;
}

int insert(){
	int index = 1;
	string value;
	string tmp = " ";
	
	cout << "input : " ;
	cin.ignore();
	getline(cin,value);
	int size_String = value.size();
	for (int i=0 ; i < size_String;i++){
		
		if(value[i] == ' '){
			stringstream data(tmp);
			data >> A[index++];
			++heapsize;
			tmp = "";
		}
		else{
			tmp+=value[i];
		}
		if(i == size_String-1){
			stringstream data(tmp);
			data >> A[index++];
			++heapsize;
			tmp = "";
		}
	}
}

void Heapify(int A[], int i){
int largest;
	int l = left(i);
	int r = right(i);
	if(l <= heapsize && A[l] > A[i]){
		largest = l;
	}else{
		largest = i;
	}
	if(r <= heapsize && A[r] > A[largest]){
		largest = r;
	}
	if(largest != i){
		swap(A[i],A[largest]);
		Heapify(A,largest);
	}
}

void Build_heap(int A[]){
	length = heapsize; 
	for(int i = length/2;i>=1;i--){
		Heapify(A,i);
	}
}

void Heapsort(int A[]){
	Build_heap(A);
	int l = heapsize;
	for(int i=length ; i >= 2 ; i--){
		swap(A[1],A[i]);
		heapsize = heapsize -1;
		Heapify(A,1);
	}
	heapsize = l;
}

void Heap_Insert(int A[], int key){
	int i;
	heapsize = heapsize+1;
	i= heapsize;
	
	A[heapsize]=key;
	cout << "Array : ";
	for (int i=1 ; i<=heapsize ; i++){
		cout << A[i] << " ";
	}
	cout << endl;
	 
	while(i>1 && A[parents(i)]<key){
		A[i] = A[parents(i)];
		i = parents(i);
		A[i] = key;
	}
}

int Heap_Exact_Max(int A[]){
	int max;
	if(heapsize<1){
		cout << "Heap underflow";
		return 0;
	}
	max = A[1];
	A[1] = A[heapsize];
	heapsize = heapsize-1;
	Heapify(A,1);
	return max;
}

int main(){
	while(1){
		switch(menu()){
			case 1:
				insert();
				break;
			case 2:
				Build_heap(A);
				cout << "Heap : ";
				for (int i=1 ; i<=heapsize ; i++){
					cout << A[i] << " ";
				}
				cout << endl;
				break;
			case 3:
				Heapsort(A);
				cout << "Heap Sort : ";
				for (int i=1 ; i<=heapsize ; i++){
					cout << A[i] << " ";
				}
				cout << endl;
				break;
			case 4:
				int data;
				cout << "insert : ";
				cin >> data;
				
				Heap_Insert(A,data);
				cout << "Heap : ";
				for (int i=1 ; i<=heapsize ; i++){
					cout << A[i] << " ";
				}
				cout << endl;
				break;
			case 5: 
				cout << "Priority Queue Heap : ";
				for (int i=1 ; i<=heapsize ; i++){
					cout << A[i] << " ";
				}
				cout << endl;
				break;
			case 6:
				cout << "Max : " << Heap_Exact_Max(A) << endl;
				cout << "Heap : ";
				for (int i=1 ; i<=heapsize ; i++){
					cout << A[i] << " ";
				}
				cout << endl;
				break;
			default:
				cout << "Please Try again" << endl;			
		}
	}
}
