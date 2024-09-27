#include <iostream>
using namespace std;
struct record{
	int value;
	struct record *next;
};
struct head_end{
	struct record *head;
	struct record *end;
};

int menu(){
	int in1;
	cout << "===========MENU==========" << endl;
	cout << "1)Input adjacency list" << endl;
	cout << "2)Input adjacency matrix" << endl;
	cout << "3)Show self loop from adjacency list" << endl;
	cout << "4)Exit" << endl;
	cout << "Please choose > ";
	cin >> in1;
	return in1;
}

struct head_end insert(struct record *head,struct record *end,int data){
	struct head_end box;
	struct record *node;
	if(head == NULL && end == NULL){
		head = new struct record;
		head->value = data;
		head->next = NULL;
		end = head;
	}
	else{
		node = new struct record;
		node->value = data;
		node->next = NULL;
		end->next = node;
		end = node;
	}
	box.head = head;
	box.end = end;
	return box;
}

void print(struct record *head){
	struct record *p = head;
	if(head == NULL){
		cout << "Empty List!" << endl; 
	}
	else{
		cout << "List : ";
		while(p){
			cout << p->value << " ";
			p = p->next;
		}
	}
}

struct record *adjList[6];
int adjMatrix[6][6];

void adjacency_list(){
	struct record *head = NULL ,*end = NULL;
	struct head_end box;
	for(int i = 0 ; i < 6 ;i++){
		adjList[i] = NULL;
	}
	for(int i = 0;i<6;i++){
		int data = 0;
		cout << "Enter #"<< i << " : ";
		while(data != -1){
			cin >> data;
			if(data < 0){
				break;
			}
			box = insert(head,end,data);
			head = box.head;
			end = box.end;
		}
		adjList[i] = head;
		head = NULL;
		end = NULL;
	}
	cout << endl << "ADJACENCY LIST" <<endl;
	for(int i = 0;i<6;i++){
		cout << "#"<< i << " : ";
		print(adjList[i]);
		cout << endl;
	}
}

void adjacency_matrix(){
	for(int i = 0;i < 6;i++){
		for(int j = 0;j < 6;j++){
			adjMatrix[i][j] = 0;
		}
	}
	for(int i = 0;i < 6;i++){
		int data = 0;
		cout << "Enter #"<< i << " : ";
		while(data != -1){
			cin >> data;
			if(data < 0){
				break;
			}
			adjMatrix[i][data] = 1;
		}
	}
	cout << endl << "ADJACENCY Matrix" << endl;
	cout << "---------------------------" << endl;
	for(int i = 0;i < 6;i++){
		for(int j = 0;j < 6;j++){
			cout << adjMatrix[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Show_selfloop(){
	cout << "Selfloop: ";
	for(int i = 0;i < 6;i++){
		struct record *p = adjList[i];
		while(p){
			if(p->value == i)
				cout << p->value << " ";
			p = p->next;
		}
	}
	cout << endl;
}

int main(){
	while(true){
		switch(menu()){
			case 1:
				adjacency_list();
				break;
			case 2:
				adjacency_matrix();
				break;
			case 3:
				Show_selfloop();
				break;
			case 4:
				cout << "Exit";
				return 0;
				break;
			default:
				cout << "Please Try again" << endl;
				break;
		}
	}
}