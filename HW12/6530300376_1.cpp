#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
struct record{
	long long id;
	string name;
};

struct Separate_Chaining{
	struct record *data;
	struct Separate_Chaining *next;
};

struct Linear{
	struct record *data;
};

struct Quardratic{
	struct record *data;
};

struct Double_Hashing{
	struct record *data;
};


int menu(){
	int in1;
	cout << "===========MENU=========="<<endl;
	cout << "1. Separate Chaining "<<endl;
	cout << "2. Linear Probling  "<<endl;
	cout << "3. Quardratic Probling "<<endl;
	cout << "4. Double Hashing  "<<endl;
	cout << "5. Exit  "<<endl;
	cout << "Please choose > ";
	cin >> in1;
	return in1;
}

int standard(long long key,int size){
	return key%size;
}

struct Separate_Chaining *insertSepChaining(struct Separate_Chaining *head,struct record *stu){
	if(head == NULL){
		head = new struct Separate_Chaining;
		head->data = stu;
		head->next = NULL;
	}else{
		struct Separate_Chaining *node,*p = head;
		node = new struct Separate_Chaining;
		while(p->next != NULL){
			p = p->next;
		}
		node->data = stu;
		node->next = NULL;
		p->next = node;	
	}
	return head;
}

void Separate_Chaining(int size){
	string data;
	struct Separate_Chaining *arrstu[size];
	for(int i = 0 ; i < size ;i++){
		arrstu[i] = NULL;
	}
	ifstream ReadFile("ADT.txt");
	while(!ReadFile.eof()){
		struct record *stu = new struct record;
		ReadFile >> data;
		stringstream ss(data);
		ss >> stu->id;
		ReadFile >> data;
		stu->name = data;
		int index = standard(stu->id,size);
		arrstu[index] = insertSepChaining(arrstu[index],stu);
	}

	cout << "Index id"<<endl <<endl;
	for(int i = 0 ;i < size;i++){
		struct Separate_Chaining *p = arrstu[i];
		cout << i << "     ";
		while(p){
			cout << p->data->id << " " << p->data->name << endl;
			p = p->next;
			cout << "      ";
		}
		cout <<endl;
	}
	ReadFile.close();
}

void Linear(int size){
	string data;
	struct Linear *arrLinearstu[size];
	for(int i = 0 ; i < size ;i++){
		arrLinearstu[i] = NULL;
	}
	ifstream ReadFile("ADT.txt");
	while(!ReadFile.eof()){
		struct record *stu = new struct record;
		ReadFile >> data;
		stringstream ss(data);
		ss >> stu->id;
		ReadFile >> data;
		stu->name = data;
		int index = standard(stu->id,size);
		int f = 1;
		while(arrLinearstu[index] != NULL){
			index = (standard(stu->id,size) + (f)) % size;
			if(++f > 100){
				cout << "Error, can not insert data!";
				break;
			}
		}
		(arrLinearstu[index] == NULL)? (arrLinearstu[index] = new struct Linear , arrLinearstu[index]->data = stu) : '\0'; 
	}
	cout << "Index id"<<endl <<endl;
	for(int i = 0 ;i < size;i++){
		cout << i << "     ";
		if(arrLinearstu[i] == NULL){
			cout << endl;
			continue;
		}
		struct Linear *p = arrLinearstu[i];
		cout << p->data->id << " " << p->data->name << endl;
		cout << "      ";
		cout <<endl;
	}
}

void Quardratic(int size){
	string data;
	struct Quardratic *arrQuardraticstu[size];
	for(int i = 0 ; i < size ;i++){
		arrQuardraticstu[i] = NULL;
	}
	ifstream ReadFile("ADT.txt");
	while(!ReadFile.eof()){
		struct record *stu = new struct record;
		ReadFile >> data;
		stringstream ss(data);
		ss >> stu->id;
		ReadFile >> data;
		stu->name = data;
		int index = standard(stu->id,size);
		int f = 1;
		while(arrQuardraticstu[index] != NULL){
			index = (standard(stu->id,size) + (f*f)) % size;
			if(++f > 100){
				cout << "Error, can not insert data!"<<endl << endl;
				break;
			}
		}
		(arrQuardraticstu[index] == NULL)?(arrQuardraticstu[index] = new struct Quardratic , arrQuardraticstu[index]->data = stu) : '\0'; //add data to index
	}
	cout << "Index id"<<endl <<endl;
	for(int i = 0 ;i < size;i++){
		cout << i << "     ";
		if(arrQuardraticstu[i] == NULL){
			cout << endl;
			continue;
		}
		struct Quardratic *p = arrQuardraticstu[i];
		cout << p->data->id << " " << p->data->name << endl;
		cout << "      ";
		cout <<endl;
	}
}

void Double_Hashing(int size){
	string data;
	struct Double_Hashing *arrDouble_Hashingstu[size];
	for(int i = 0 ; i < size ;i++){
		arrDouble_Hashingstu[i] = NULL;
	}
	ifstream ReadFile("ADT.txt");
	while(!ReadFile.eof()){
		struct record *stu = new struct record;
		ReadFile >> data;
		stringstream ss(data);
		ss >> stu->id;
		ReadFile >> data;
		stu->name = data;
		int index = standard(stu->id,size);
		int f = 1;
		while(arrDouble_Hashingstu[index] != NULL){
			index = (standard(stu->id,size) + f*(7-(stu->id%7))) % size;
			if(++f > 100){
				cout << "Error, can not insert data!"<<endl << endl;
				break;
			}
		}
		(arrDouble_Hashingstu[index] == NULL)?(arrDouble_Hashingstu[index] = new struct Double_Hashing , arrDouble_Hashingstu[index]->data = stu) : '\0'; //add data to index
	}
	cout << "Index id"<<endl <<endl;
	for(int i = 0 ;i < size;i++){
		cout << i << "     ";
		if(arrDouble_Hashingstu[i] == NULL){
			cout << endl;
			continue;
		}
		struct Double_Hashing *p = arrDouble_Hashingstu[i];
		cout << p->data->id << " " << p->data->name << endl;
		cout << "      ";
		cout <<endl;
	}
}

int main(){
	int size = 5;
	while(true){
		switch(menu()){
			case 1:
				Separate_Chaining(size);
				break;
			case 2:
				Linear(size);
				break;
			case 3:
				Quardratic(size);
				break;
			case 4:
				Double_Hashing(size);
				break;
			case 5:
				cout << "Exit";
				return 0;
				break;
			default:
				cout << "Please Try again!";
				break;
		}
	}
	return 0;
}
