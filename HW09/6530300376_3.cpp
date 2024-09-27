#include<iostream>
#include <algorithm>
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
	cout << "=======================" << endl << endl;
	cout << "         MENU          " << endl << endl;
	cout << "=======================" << endl;
	cout << "1) Insert Graph" << endl;
	cout << "2) Topological sort " << endl;
	cout << "3) Exit" << endl;
	cout << "Please choose > ";
	cin >> in1;
	return in1;
}

int DFS_Tree = 1;
int time = 0;
int pass[9];
int d[9];
int f[9],fsort[9];
int pred[9];

struct record *adjList[9];
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
	for(int i = 0 ; i < 9 ;i++){
		adjList[i] = NULL;
	}
	for(int i = 0;i<9;i++){
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

void DFS(int u){
	DFS_Visit(u);
	for(int j = 0;j < 9;j++){
		if(pass[j] == 0){
			DFS_Tree++;
			DFS(j);
		}
	}
}

void TopologicalSort(){
	struct record *head = NULL ,*end = NULL;
	struct node box;
	string arrStr[9] = {"Undershort","Pants","Belt","Shirt","Tie","Jacket","Socks","Shoes","Watch"};
	for(int i = 0;i < 9 ; i++){
		fsort[i] = f[i]; 
	}
	int size = sizeof(fsort) / sizeof(fsort[0]);
	sort(fsort, fsort + size,greater<int>());
	for(int i = 0 ; i < 9;i++){
		for(int j = 0;j<9;j++){
			if(fsort[i] == f[j]){
				box = insert(head,end,j);
				head = box.head;
				end = box.end;
			}
		}
	}
	struct record *p = head;
	while(p){
		cout << arrStr[p->value] << " ";
		p = p->next;
	}
	cout << endl;
}

int main(){
	int vertex;
	while(true){
		switch(menu()){
			case 1:
				adjacency_list();
				break;
			case 2:
				for(int i = 0;i < 9;i++){
					pass[i] = 0;
					pred[i] = d[i] = f[i] = -1;
				}
				cout << "Input source vertex: ";
				cin >> vertex;
				DFS(vertex);
				TopologicalSort();
				break;
			case 3:
				return 0;
				break;
			default:
				cout << "Please Try again" << endl;
				break;
		}
	}
}
