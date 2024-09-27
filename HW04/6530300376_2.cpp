#include <iostream>
using namespace std;

struct record{
	int value;
	struct record *next;
	struct record *prev;
};

void menu(){
	cout << "========MENU=======" << endl;
	cout << "1) Insert" << endl;
	cout << "2) Delete" << endl;
	cout << "3) Print" << endl;
	cout << "4) Exit" << endl;
	cout << "Please choose > ";
}

struct record *insert(struct record *head,struct record *tail,int data){
	struct record *p ,*node;
	
	if(head == NULL){
		head = new struct record;
		head -> value = data;
		head -> prev = NULL;
		head -> next = NULL;
		tail = head;
	}
	else{
		node = new struct record;
		node -> value = data;
		
		if(data < head -> value){
			node -> next = head;
			head = node;
			
			node ->prev = tail;
			tail = node;
		}
		else{
			p=head;
			while(p -> next != NULL){
				if(data < p -> next -> value){
					node -> next = p -> next;
					p -> next = node;
					
					p -> next -> prev = tail;
					tail = p;
					break;
				}
				else p = p -> next;
			}
			if(p -> next == NULL){
				node -> next = NULL;
				p-> next = node;
				
				p -> next -> prev = tail;
				tail = p;
			}	
		}
	}
	return head;	
}

struct record *for_delete(struct record *head,struct record *tail,int data){
 	struct record *p = head;
 	
    if (head == NULL) {
        cout << "Empty List!" << endl;
        return head;
    }
    if (head -> value == data) {
        struct record *temp = head;
        head = head -> next;
        if (head == NULL) {
            tail = NULL;
        }
		else{
            head -> prev = tail;
        }
        delete temp;
        return head;
    }
    while (p -> next != NULL) {
        if (p -> next -> value == data) {
            struct record *temp = p -> next;
            p -> next = temp -> next;
            if (temp -> next != NULL) {
                temp -> next -> prev = p; 
            } else {
                tail = p; 
            }
            delete temp;
            return head;
        }
        p = p->next;
    }
}

struct record *print(struct record *head){
	struct record *p = head;
	while(p){
		cout << p -> value << " ";
		p = p -> next;
	}
	cout << endl;
}

int main(){
	int in1=0,in2=0;
	
	struct record *head=NULL , *tail=NULL;
	while(true){
		menu();
		cin >> in1;
		switch(in1){
			case 1 :
				cout << "Insert : ";
				cin >> in2;
				head = insert(head ,tail, in2);
				cout << "Success!" << endl;
				break;
			case 2 :
				cout << "Delete : ";
				cin >> in2;
				head = for_delete(head ,tail, in2);
				cout << "Success" << endl;
				break;
			case 3 :
				cout << "List : ";
				print(head);
				cout << endl;
				break;
			case 4 :
				return 0;
				break;		
			default : 
				cout << "Try Again" << endl;
		}
	}	
}
