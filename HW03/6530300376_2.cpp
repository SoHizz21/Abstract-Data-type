#include <iostream>
using namespace std;

struct record {
	char value;
	struct record *next;
};

int menu(int in1){
	cout << "========MENU=======" << endl;
	cout << "1)Insert" << endl;
	cout << "2)Odd,even" << endl;
	cout << "3)Decode " << endl;
	cout << "4)Exit" << endl;
	cout << "Please choose > ";
	cin >> in1;
	return in1;
}

struct record *insert(struct record *head,char data){
	struct record *node,*p;
	if(head == NULL){
		head = new struct record;
		head->value = data;
		head->next = NULL;
	}else{
		node = new struct record;
		node->value = data;
		p = head;
		while(p->next != NULL){
			p = p->next;
		}
		if(p->next == NULL){
			node->next = NULL;
			p->next = node;
		}
	}
	return head;
}

void printData(struct record *head){
	if(head == NULL){
		cout << "Empty list!";
	}else{
		struct record *p = head;
		while (p){
			cout << head->value;
			p = p->next;
		}
	}
	cout << endl;
} 

void Decode(struct record *head,int val){
	int check = val;
	if(head == NULL){
		cout << "Empty list!";
	}else{
		struct record *p = head;
		while (p){
			if(check%2 == 0){
				cout << p->value;
			}
			p = p->next;
			check++;
		}
	}
} 

int main(){
	
	int i=1;
	int in1=0;
	int data;
	
	struct record *keep=NULL;
	
	while(i==1){
	switch(menu(in1)){
			case 1: // Insert
				char c;
				cout << "Enter Code :";
				do {
					c = getchar();
					if (c == '.')
						break;
					else
						keep = insert(keep,c);
				}while (c != '.');
				cout << "List : ";
				printData(keep);
				break;
			case 2: // Odd, even
				cout << "Odd node = ";
				Decode(keep,1);
				cout << endl;
				cout << "Even node = ";
				Decode(keep,2);
				cout << endl;
				break;
			case 3: //Decode 
				cout << "Decode : ";
				Decode(keep,1);
				cout << endl;
				break;
			case 4: //Exit
				i=0;
				break;
		}
	}
}
