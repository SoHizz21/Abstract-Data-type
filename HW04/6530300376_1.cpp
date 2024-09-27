#include <iostream>
using namespace std;
int P_1 = 0,P_2 = 0;

struct record {
	int value,pow;
	struct record *next;
};

struct record *insert(struct record *head,int data,int pow){
	struct record *node,*p;
	if(head == NULL){		
		head = new struct record;
		head -> value = data;
		head -> pow = pow;
		head -> next = NULL;
	}
	else{
		node = new struct record;
		node -> value = data;
		node -> pow = pow;
		p = head;
		while(p -> next != NULL)
			p = p -> next;
		if(p -> next == NULL){
			node -> next = NULL;
			p -> next = node;
		}
	}
	return head;
}

void process(struct record *head){
	if(head -> pow == 0){
		cout << head -> value;
	}	
	else if(head -> pow == 1){
		cout << head -> value << "x";
	}
	else{
		cout << head -> value << "x^"<<head -> pow;
	}	
	if(head -> next == NULL){
		cout << "";
	}
	else{
		cout << " + ";
	}
}

void p1sump2(struct record *head_1,struct record *head_2){
	int i = 0,count;
	struct record *P1 = head_1;
	struct record *P2 = head_2;
	if(P_1 > P_2){
		count = P_1;
	}
	else{
		count = P_2;
	}
	while(i < count){
		if(P2 == NULL && P1 != NULL ){
			process(P1);
			P1 = P1 -> next;
		}
		else if(P1 == NULL && P2 != NULL ){
			process(P2);
			P2 = P2 -> next;
		}
		else{
			if(P1 -> pow != P2 -> pow){
				if(P1 -> pow > P2 -> pow){
					process(P1);
					P1 = P1 -> next;
				}
				else{
					process(P2);
					P2 = P2 -> next;
				}
				count++;
			}
			else{
				cout << P1 -> value + P2 -> value << "x^" << P1 -> pow;
				cout << " + ";
				P1 = P1 -> next;
				P2 = P2 -> next;
			}	
		}
		i++;
	}
}

int main(){
	int data,pow;
	struct record *head_1 = NULL;
	struct record *head_2 = NULL;
	cout << "Input P1 : ";
	do{
		cin >> data;
		if (data < 0)
			break;
		cin >> pow;
		P_1++;
		head_1 = insert(head_1,data,pow);
	}
	while(data >= 0);
	cout << "Input P2 : ";
	do{
		cin >> data;
		if (data < 0)
			break;
		cin >> pow;
		P_2++;
		head_2 = insert(head_2,data,pow);
	}
	while(data >= 0);
	p1sump2(head_1,head_2);
    return 0;
}
