#include <iostream>
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
	cout << "==========MENU=========" << endl;
	cout << "1) Insert Graph" << endl;
	cout << "2) DFS " << endl;
	cout << "3) Transpose graph " << endl;
	cout << "4) Decompose strongly connected graph " << endl;
	cout << "5) Exit " << endl;
	cout << "Please choose > ";
	cin >> in1;
	return in1;
}

int fMax;
int Stree = 0;
int DFS_Tree = 1;
int time = 0,timeT = 0;
int pass[8],passT[8];
int d[8],dT[8];
int f[8],fT[8],Finish_MaxtoMin[8];
int pred[8],predT[8];
struct record *adjList[8];
struct record *adjList_transpose[8];

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

void print_array(int arr[]){
	for(int i  = 0 ; i < 8 ;i++){
		cout << arr[i] << " ";
	}
}

void print_list(struct record *head){
	struct record *p = head;
	if(head == NULL){
		cout << "Empty List!" << endl; 
	}
	else{
		while(p){
			cout << p->value << " ";
			p = p->next;
		}
	}
}

void TGraph(){	
	struct node box;
	struct record *head = NULL ,*end = NULL;
	int k = 0;
	for(int i = 0 ; i < 8 ;i++){
		adjList_transpose[i] = NULL;
	}
	for(int i = 0 ;i < 8 ;i++){
		for(int j = 0;j < 8;j++){
			struct record *p = adjList[j]; 
			while(p != NULL){
				if(p->value == i){
					box = insert(head,end,j);
					head = box.head;
					end = box.end;
				}
				p = p->next;
			}
		}
		adjList_transpose[i] = head;
		head = NULL;
		end = NULL;
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

void DFS_Visit_Transpose(int uT){
	struct record *node;
	int vT;
	passT[uT] = 1;
	dT[uT] = ++timeT;
	node = adjList_transpose[uT];
	while(node != NULL){
		vT = node->value;
		if(passT[vT] == 0){
			predT[vT] = uT;
			DFS_Visit_Transpose(vT);
		}
		node = node->next;
	}
	passT[uT] = 1;
	fT[uT] = ++timeT;
}

void DFS_Transpose(int uT){
	DFS_Visit_Transpose(uT);
}

void prepareData(){
	int initialvalue,dynamicInitial;
	for(int i = 0 ; i < 8;i++){
		if(predT[i] == -1){
			cout << "(" << i;
			initialvalue = fT[i]; 
			predT[i] = -2;
			break;
		}
	}
	dynamicInitial = initialvalue-1;
	for(int j = 0 ;j < 8;j++){
		if(fT[j] == dynamicInitial && predT[j] != -1){
			if(fT[j] == dynamicInitial && dT[j] == dynamicInitial-1){
				cout << "(" << j << " " << j << ")";
				dynamicInitial=dynamicInitial-2;
				break;
			}
			cout << "(" << j;
			dynamicInitial--;
		}
	}
	for(int j = 0 ;j < 8;j++){
		if(dT[j] == dynamicInitial && predT[j] != -1){
			if(predT[j] == -1 && dT[j] == dynamicInitial && fT[j] == initialvalue){
				cout <<j << ")";
				break;
			}
			else{
				cout<<j << ")";
				dynamicInitial--;
			}			
		}
	}	
}

void printTreeDFSFormat(){
	int tree = 1;
	for(int i = 0;i < 8 ; i++){
		if(predT[i] == -1){
			++Stree;
		}
	}
	for(int i = 0;i <=Stree ; i++){
		for(int j = 0;j<8;j++){
			if(predT[j] == -1){
				cout << tree++;
				prepareData();
				cout << endl;
			}
		}
	}
}

void DecompStronglyConnected(){
	for(int i = 0;i < 8;i++){
		passT[i] = 0;
		predT[i] = dT[i] = fT[i] = -1;
	}
	for(int i = 0;i < 8 ; i++){
		Finish_MaxtoMin[i] = f[i]; 
	}
	int size = sizeof(Finish_MaxtoMin) / sizeof(Finish_MaxtoMin[0]);
	sort(Finish_MaxtoMin, Finish_MaxtoMin + size,greater<int>());
	cout << endl;
	for(int u = 0;u < 8;u++){
		for(int i = 0; i < 8;i++){
			if(Finish_MaxtoMin[u] == f[i] && passT[i] == 0){
				DFS_Transpose(i);
				break;
			}
		}
	}
	printTreeDFSFormat();
}

int main(){
	while(true){
		switch(menu()){
			case 1:
				adjacency_list();
				break;
			case 2:
				int vertex;
				for(int i = 0;i < 8;i++){
					pass[i] = 0;
					pred[i] = d[i] = f[i] = -1;
				}
				cout << "Input source vertex: ";
				cin >> vertex;
				DFS(vertex);
				cout << "Tree = " << DFS_Tree << endl;
				cout << "d: ";
				print_array(d);
				cout << endl << "f: ";
				print_array(f);
				cout << endl << "pred: ";
				print_array(pred);
				cout << endl;
				break;
			case 3:
				cout << endl << "Adjacency list " <<endl;
				for(int i = 0;i<8;i++){
					cout << i << " : ";
					print_list(adjList[i]);
					cout << endl;
				}
				TGraph();
				cout << endl << "Adajacency list transpose  " <<endl;
				for(int i = 0;i<8;i++){
					cout << i << " : ";
					print_list(adjList_transpose[i]);
					cout << endl;
				}
				break;
			case 4:
				DecompStronglyConnected();
				break;
			case 5:
				return 0;
				break;
			default:
				cout << "Please Try again" << endl;
				break;
		}
	}
	return 0;
}
