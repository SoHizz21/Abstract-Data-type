#include <iostream>
using namespace std;

struct record{
	int value;
	struct record *next;
};
struct node{
	struct record *head;
	struct record *end;
};

int menu(){
	int in1;
	cout << "==========MENU=========" << endl;
	cout << "1) Insert Graph" << endl;
	cout << "2) DFS" << endl;
	cout << "3) Exit" << endl;
	cout << "Please choose > ";
	cin >> in1;
	return in1;
}

int DFS_Tree = 1;
int time = 0;
int pass[8];
int d[8];
int f[8];
int pred[8];
struct record *adjList[8];

struct node insert(struct record *head,struct record *end,int data){
	struct node box;
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

void adjacency_list(){
	struct record *head = NULL ,*end = NULL;
	struct node box;

	for(int i = 0 ; i < 8 ;i++){
		adjList[i] = NULL;
	}
	for(int i = 0;i<8;i++){
		int data = 0;
		cout << "#"<< i << " : ";
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
}

void DFS_Visit(int u){
	struct record *node;
	int v;
	pass[u] = 1;
	d[u] = ++time;
	node = adjList[u];
	while(node != NULL){
		v = node->value;
		if(pass[v] == 0){
			pred[v] = u;
			DFS_Visit(v);
		}
		node = node->next;
	}
	pass[u] = 1;
	f[u] = ++time;
}

void print(int arr[]){
	for(int i  = 0 ; i < 8 ;i++){
		cout << arr[i] << " ";
	}
}

void DFS(int u){
	DFS_Visit(u);
	for(int u = 0;u < 8;u++){
		if(pass[u] == 0){
			DFS_Tree++;
			DFS(u);
		}
	}
}

int main(){
	while(1){
		switch(menu()){
			int vertex;
			case 1:
				adjacency_list();
				break;
			case 2:
				for(int i = 0;i < 8;i++){
					pass[i] = 0;
					pred[i] = d[i] = f[i] = -1;
				}
				cout << "Input source vertex: ";
				cin >> vertex;

				DFS(vertex);
				cout << "Tree = " << DFS_Tree << endl;
				cout << "d: ";
				print(d);
				cout << endl << "f: ";
				print(f);
				cout << endl << "pred: ";
				print(pred);
				cout << endl;
				break;
			case 3:
				return 0;
				break;
			default : 
				cout << "Plaese Try again" << endl;
				break;
		}			
	}
}
