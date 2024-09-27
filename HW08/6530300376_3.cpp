#include <iostream>
#include <queue> 
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
	cout << "1)Input adjacency list "<< endl;
	cout << "2)BFS"<< endl;
	cout << "3)Search path"<< endl;
	cout << "4)Exit"<< endl;
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
		while(p){
			cout << p->value << " ";
			p = p->next;
		}
	}
}

int d[8];
int pred[8];
int s = 2;
struct record *adjList[8];

void adjacency_list(){
	struct record *head = NULL ,*end = NULL;
	struct head_end box;
	for(int i = 0 ; i < 8 ;i++){
		adjList[i] = NULL;
	}
	for(int i = 0;i<8;i++){
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
	for(int i = 0;i<8;i++){
		cout << "#"<< i << " : ";
		print(adjList[i]);
		cout << endl;
	}
}

void BFS(){
	int pass[8];
	int u,v;
	struct record *node;
	queue<int> q;
	q.push(s);
	for(int i = 0 ; i < 8 ;i++){
			pass[i] = 0;
			d[i] = -1;
			pred[i] = -1;	
	}
	pass[s] = 1;
	d[s] = 0;
	pred[s] = s;
	while(q.size() != 0){
		u = q.front();
		node = adjList[u];
		while(node != NULL){
			v = node->value;
			if(pass[v] == 0){
				pass[v] = 1;
				d[v] = d[u]+1;
				pred[v] = u;
				q.push(v);
			}
			node = node->next;
		}
		q.pop();
	}
	cout << "| d | pred" << endl;
	cout << "=============" << endl;
	for(int i = 0 ; i < 8;i++){
		cout << i << " | " << d[i] << " | " << pred[i] << endl;
	}
}

void search(){
	int j=0,parent,vertex,distance,i,k;
	cout << "Enter end point : ";
	cin >> vertex;
	if(vertex == s){
		cout << "no Path!";
	}
    else{
		cout << "Path = ";
		distance = d[vertex];
		int arrPred[distance]; 
		int arrVertex[distance]; 
		i = distance;
		k = distance-1;
		parent = pred[vertex];
		while(i > 0){
			arrPred[j] = parent;
			arrVertex[j] = vertex;
			vertex = pred[vertex];
			parent = pred[vertex];
			i--;
			j++;
		}
		while(k >= 0){
			if(k == 0){
				cout << "(" << arrPred[k] << "," << arrVertex[k] << ")";
			}
            else{
				cout << "(" << arrPred[k] << "," << arrVertex[k] << "),";
			}
			k--;
		}
	}
	cout << endl << "Distance : " << distance << endl;
}

int main(){
	while(true){
		switch(menu()){
			case 1:
				adjacency_list();
				break;
			case 2:
				BFS();
				break;
			case 3:
				search();
				break;
			case 4:
				cout << "Exit!";
				return 0;
				break;
			default:
				cout << "please try again";
				break;
		}
	}
	return 0;
}