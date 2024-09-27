#include <iostream>
using namespace std;

struct record {
		int value;
		struct record *next;
};

int menu(int in1){
		cout << "========MENU=======" << endl;
		cout << "1)Insert" << endl;
		cout << "2)Print All data" << endl;
		cout << "3)Print first and last" << endl;
		cout << "4)Exit" << endl;
		cout << "Please Choose > ";
		cin >> in1;
		return in1;
}

struct record *insert(struct record *head,int data){
	struct record *p ,*node;
	if(head==NULL){
		head = new struct record;
		head -> value = data;
		head -> next = NULL;
	}
	else{
		node = new struct record;
		node -> value = data;
		if(data < head -> value){
			node -> next = head;
			head = node;
		}
		else{
			p=head;
			while(p->next!=NULL){
				if( data < p->next->value){
					node->next=p->next;
					p->next = node;
					break;
				}
				else p=p -> next;
			}
			if(p->next==NULL){
				node->next=NULL;
				p->next=node;
			}
		}
		return head;
	}
}

void printFandL(struct record *head){
	cout << "Frist : " << head -> value << endl;
	
	cout << "Last : ";
	while(head->next != NULL){
		head = head->next;
	}
	cout << head -> value << endl;
}

void print(struct record *head){
	cout << "List : ";
	struct record *tmp;
	tmp=head;
	
	if(tmp == NULL){
		cout << "Empty list" << endl;
	}
	else{
		while(tmp!=NULL){
			cout << tmp->value << " ";
			tmp=tmp->next;
		}	
	}
	cout << endl;
}

int main(){
	int i=1;
	int in1=0;
	int data;
	
	struct record *keep=NULL;
	
	while(i==1){
	switch(menu(in1)){
			case 1 :
				cout << "insert : ";
				cin >> data;
				keep = insert(keep , data);
				cout << "Success!" << endl;
				print(keep);
				break;
			case 2 :
				print(keep);
				break;
			case 3 :
				printFandL(keep);
				break;
			case 4 : 
				cout << "Exit!";
				i=0;
				break;
		}
	}
	return 0;
}
