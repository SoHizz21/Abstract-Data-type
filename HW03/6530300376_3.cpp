#include <iostream>
using namespace std;
int P1 = 0,P2 = 0;

struct record {
	int value;
	struct record *next;
};

struct record *insert(struct record *head,int data){
	struct record *node,*p;
	if(head == NULL){
		head = new struct record;
		head->value = data;
		head->next = NULL;
	}
	else{
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


void process(struct record *head){
	int as_pol_check = 1;
	struct record *p = head;
	cout << "Longer: ";
	while(p){
		if(as_pol_check%2 != 0){
			if(p->next->value == 0){
				cout << p->value;
			}else if(p->next->value == 1){
				cout << p->value << "x";
			}else{
				cout << p->value << "x^";
			}
		}
		else{
			if(p->value == 0){
				continue;
			}else if(p->value == 1){
				cout << " + ";
			}else{
				cout << p->value << " + ";
			}
			
		}
		as_pol_check++;
		p = p->next;
	}	
}

int main(){
	int data;
	struct record *head_1 = NULL;
	struct record *head_2 = NULL;
	cout << "Input P1 : ";
	do{
		cin >> data;
		if (data < 0)
			break;
		else
			P1++;
			head_1 = insert(head_1,data);
	}while(data >= 0);
	cout << "Input P2 : ";
	do{
		cin >> data;
		if (data < 0)
			break;
		else
			P2++;
			head_2 = insert(head_2,data);
	}while(data >= 0);
	if(P1 > P2){
		process(head_1);
	}
	else{
		process(head_2);
	}
    return 0;
}
