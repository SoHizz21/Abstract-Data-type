#include <iostream>
using namespace std;
struct record{
	int value;
	struct record *next;
};
struct frontback{
	struct record *front;
	struct record *back;
};

int menu(){
	int in1;
	cout << "=======MENU======"<<endl;
	cout << "1.Enqueue"<<endl;
	cout << "2.Dequeue"<<endl;
	cout << "3.Exit"<<endl;
	cout << "Please choose > ";
	cin >> in1;
	return in1;	
}

struct frontback enqueue (struct record *front,struct record *back,int data){
	struct record *node,*p;
	struct frontback box;

	if(front == NULL && back == NULL){
		front = new struct record;
		front->value = data;
		front->next = NULL;
		back = front;
	}else{
		node = new struct record;
		node->value = data;
		node->next = NULL;
		back->next = node;
		back = node;
	}
	box.front = front;
	box.back = back;
	cout << "Success!"<<endl;
	return box;
} 

struct frontback dequeue(struct record *front,struct record *back){
	struct record *temp;
	struct frontback box;
    
	if(front == NULL){
		cout << "Empty! Cant Dequeue"<<endl;
	}else{
		cout << "Dequeue " << front->value<<endl;
		temp = front;
		front = front->next;
		if(front == NULL){
			back = NULL;
		}
		delete temp;
	}
	box.front = front;
	box.back = back;
	return box;
}

int main(){
	int in1;
	struct record *front = NULL,*back = NULL;
	struct frontback box;

	while(true){
		switch(menu()){
			case 1:
				cout << "Enter data: ";
				cin >> in1;
				box = enqueue(front,back,in1);
				front = box.front;
				back = box.back;
				break;
			case 2:
				box = dequeue(front,back);
				front = box.front;
				back = box.back;
				break;
			case 3:
				cout << "Bye!";
				return 0;
				break;
			default:
				break;
		}
	}
	return 0;
}
