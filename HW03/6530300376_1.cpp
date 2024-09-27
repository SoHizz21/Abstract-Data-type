//Peerapat Saengphoem 6530300376
#include <iostream>
using namespace std;
int count;

struct record {
	int value;
	struct record *next;
};

int menu(int in1){
	cout << "========MENU=======" << endl;
	cout << "1) Insert" << endl;
	cout << "2) Delete" << endl;
	cout << "3) Print  min to max / max to min" << endl;
	cout << "4) Count node"<< endl;
	cout << "5) Print only odd node" << endl;
	cout << "6) Exit" << endl;
	cout << "Please choose >";
	cin >> in1;
	return in1;
}

struct record *insert(struct record *head,int data){
	struct record *node,*p;
	if(head == NULL){		
		head = new struct record;
		head->value = data;
		head->next = NULL;
		count++;
	}else{
		node = new struct record;
		node->value = data;
		if(data < head->value){ //data < head
			node -> next = head;
			head = node;
		}else{ //data > head
			p = head;
			while (p->next != NULL){ 
				 if(data < p->next->value){
				 	node -> next = p-> next;
				 	p->next = node;
				 	break;
				 }else{
				 	p = p->next;
				 }
			}
			if(p->next == NULL){
				node->next = NULL;
				p->next = node;
			}
		}
		count++;
	}
	return head;
}

struct record *for_delete(struct record *head,int data){ 
	struct record *node ,*tmpfree;
	node = head;

	if(data == head->value){ 
		count--;
        tmpfree = node;
        node = node->next;
    	delete tmpfree;
	}
	else{
		while(node){
			if(data == node -> next -> value){
				tmpfree = node -> next;
				node -> next = node -> next -> next;
				delete(tmpfree);
				break;
			}
			else if(data == node->next->value && node->next->next == NULL){
				tmpfree = node->next;
				node->next = node->next->next;
				delete tmpfree;
				break;
			}
			else node=node->next;
		}
		count--;
	}
	return head;
}

void printData(struct record *head,int select){ 
	if(head == NULL){
		cout << "Empty list!"<<endl;
	}else if(select == 0){
		struct record *p = head;
		while (p){
			cout << p->value << " ";
			p = p->next;
		}
		cout << endl;
	}else if(select == 1){
		int i = count-1;
		while (i>=0){
			int j = 0;
			struct record *p = head;
			while(j <= i){
				if(j == i){
					cout << p->value << " ";
				}
				p = p->next;
				j++;
			}
			i--;
		}
	}else if(select == 2){
		int check = 1;
		struct record *p = head;
		while (p){
			if(check%2!=0){
				cout << p->value << " ";	
			}
			check++;
			p = p->next;
		}
	}
	cout << endl;
}

int main(){
	
	int m=1;
	int in1=0;
	int data;
	
	struct record *keep=NULL;
	
	while(m==1){
	switch(menu(in1)){
			case 1 : //insert 
				cout << "insert : ";
				cin >> data;
				keep = insert(keep , data);
				cout << "Success!" << endl;
				break;
			case 2 : //delete
				cout << "Delete : ";
				cin >> data;
				keep = for_delete(keep , data);
				cout << "Success!" << endl;
				break;
			case 3: //Min to max/Max to min
				cout << "Min to max: ";
				printData(keep,0);
				cout << "Max to min: " ;
				printData(keep,1);
				break;
			case 4: //Count node
				cout << "Number of node = " << count << endl;
				break;
			case 5: //Print only odd node
				cout << "Odd node = ";
				printData(keep,2);
				break;
			case 6 : //Exit
				cout << "Exit!";
				m=0;
				break;
		}
	}
}
