//Peerapat Saengphoem
//6530300376

#include <iostream>
using namespace std;
struct Node{
	char value;
	struct Node *Next;
};

typedef struct Node *Stack;

void Check(Stack S);
void Push(char symbol,Stack S);
void Pop(Stack S);
char Top(Stack S);
bool IsEmpty(Stack S);

Stack CreateStack();

int main(){
	Stack S = CreateStack();
	char in1;
	cout << "Input: ";
	do{
		cin >> in1;
		if(in1 == '.')
			break;
		else
			Push(in1,S);
	}while(true);
	Check(S);
	return 0;
}

void Check(Stack S){
	Stack S1 = CreateStack();
	int check = 0;
	while(!IsEmpty(S)){
		char in1 = Top(S);
		switch(in1){
			case '{':
			case '[':
			case '(':
			case '<':
				check++;
				Push(in1,S1);
				break;
		}
		Pop(S);
	}
	while(!IsEmpty(S1)){
		cout << Top(S1) << endl;
		Pop(S1);
	}
	cout << "Open = " << check;
}

Stack CreateStack(){
	Stack S;
	S = new struct Node;
	S->Next = NULL;
	if(S == NULL){
		cout << "Out of Space!";
	}
	return S;
}

bool IsEmpty(Stack S){
	return S->Next == NULL;
}

void Push(char symbol,Stack S){
	Stack TmpCell;
	TmpCell = new struct Node;
	if(TmpCell == NULL){
		cout << "Out of space!!";
	}
	else{
		TmpCell->value = symbol;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}
void Pop(Stack S){
	Stack FirstCell;
	if(IsEmpty(S)){
		cout << "Stack Empty!!";
	}
	else{
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		delete FirstCell;
	}
	
}

char Top(Stack S){
	if(!IsEmpty(S)){
		return S->Next->value;
	}
	else{
		cout << "Stack Empty!" << endl;
	}
}


