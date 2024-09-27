//Peerapat Saengphoem
//6530300376
#include <iostream>
#include <cstdlib>  
using namespace std;

struct Node{
	int value;
	struct Node *Next;
};

typedef struct Node *Stack;

bool IsEmpty(Stack S);
int Top(Stack S);
void Push(int in1,Stack S);
void Pop(Stack S);
Stack CreateStack();

bool IsEmpty(Stack S){
	return S->Next == NULL;
}

int Top(Stack S){
	if(!IsEmpty(S))
		return S->Next->value;
	else
		cout << "Stack Empty!";
}

void Push(int in1,Stack S){
	Stack TmpCell;
	TmpCell = new struct Node;
	if(TmpCell == NULL){
		cout << "Out of space!!";
	}
	else{
		TmpCell->value = in1;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}

void Pop(Stack S){
	Stack FirstCell;
	if(IsEmpty(S)){
		cout << "Empty Stack!";
	}
	else{
		FirstCell = S->Next;
		S->Next = S->Next->Next;
		delete FirstCell;
	}
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

int Sum(Stack S){
	int sum = 0;
	while(!IsEmpty(S)){
		sum += Top(S);
		Pop(S);
	}
	return sum;
}

int main(){
	Stack S = CreateStack();
    char in1[30];   
    cout << "input: ";
    while(in1[0]!='.'){    
		cin >> in1;
		if(in1[0] == '.'){
			break;
		}
		else{
			if(in1[0]>='0'&& in1[0]<='9'){
				cout << in1 << "  digit" <<endl;
            	Push(atoi(in1),S);       
        	}
			else{
        		cout << in1 << "  symbol" <<endl;
			}
		}
	}
	cout << "Output = "<< Sum(S);
}