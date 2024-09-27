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

struct frontback enqueue (struct record *front,struct record *back,int data){
	struct record *node,*p;
	struct frontback box;

	if(front == NULL && back == NULL){
		front = new struct record;
		front->value = data;
		front->next = NULL;
		back = front;
	}
	else{
		node = new struct record;
		node->value = data;
		node->next = front;
		back->next = node;
		back = node;
	}
	box.front = front;
	box.back = back;
	return box;
}

struct frontback dequeue(struct record *front,struct record *back){
	struct record *temp;
	struct frontback box;

	if(front == NULL){
		cout << "Empty! Cant Dequeue"<<endl;
	}
	else{
		temp = front;
		front = front->next;
		back->next = front;
		if(front == NULL){
			box.front = NULL;
			box.back = NULL;
			return box;
		}
		delete temp;
	}
	box.front = front;
	box.back = back;
	return box;
}

int josephus(int in1,int in2 ,struct frontback box){
	int c_in1 = 0 , c_del = 0;
	struct record *front = NULL,*back = NULL;

	front = box.front;
	back = box.back;
	while(c_del != in2-1){
		if(c_in1 == in1){
			c_del++;
			box = dequeue(front,back);
			front = box.front;
			back = box.back;
			c_in1 = 0;
		}
		else{
			c_in1++;
			front = front->next;
			back = back->next;
		}
	}
	return front->value;
}

int main(){
	int in1,in2;
	struct record *front = NULL,*back = NULL;
	struct frontback box;

	cout << "Input M: ";
	cin >> in1;
	cout << "Input N: ";
	cin >> in2;
	for(int i = 1;i<=in2;i++){
		box = enqueue(front,back,i);
		front = box.front;
		back = box.back;
	}
	cout << "Winner is : " << josephus(in1,in2,box);
	return 0;
}