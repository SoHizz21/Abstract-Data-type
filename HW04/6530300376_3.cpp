#include <iostream>
using namespace std;

struct Node{
	int value;
	struct Node *next;
};
typedef struct Node *Stack;

void menu(){
	cout << "======MENU======" << endl;
	cout << "1) Push" << endl;
	cout << "2) Pop" << endl;
	cout << "3) Top" << endl;
	cout << "4) Exit" << endl;
	cout << "   Please choose > ";
}

Stack CreateStack(void){
	Stack S;
	S = new struct Node;
	S -> next = NULL;
	if(S == NULL){
		cout << "Out of Space!";
	}
	return S;
}

bool IsEmpty(Stack S){
	return S -> next == NULL;
}

void Push(int X,Stack S){
	Stack TmpCell;
	TmpCell = new struct Node;
	if(TmpCell == NULL){
		cout << "Out of space!!";
	}
	else{
		TmpCell -> value = X;
		TmpCell -> next = S -> next;
		S -> next = TmpCell;
		cout << "Success!" <<endl;
	}
	
}

void Pop(Stack S){
	Stack FirstCell;
	if(IsEmpty(S)){
		cout << "Stack Empty!";
	}
	else{
		FirstCell = S -> next;
		S -> next = S -> next -> next;
		delete FirstCell;
		cout << "Success!" <<endl;
	}
	
}

int Top(Stack S){
	if(IsEmpty(S)){
		cout << "Stack Empty!" << endl;
	}
	else{
		return S -> next -> value;
	}
}

int main(){
	int in1=0,in2=0;
	Stack S = CreateStack();

	while(true){
		menu();
		cin >> in1;
		switch(in1){
			case 1 : 
				cout << "Push: ";
				cin >> in2;
				Push(in2,S);
				break;
			case 2:
				if(IsEmpty(S)){
					Top(S);
				}else{
					cout << "Pop: " << Top(S) << endl;
					Pop(S);	
				}
				break;
			case 3:
				if(IsEmpty(S)){
					Top(S);
				}else{
					cout << "Top : " << Top(S) <<endl;
				}
				break;
			case 4 :
				return 0;
				break;
			default :
				cout << "Try Again" << endl;
		}		
	}	
}

