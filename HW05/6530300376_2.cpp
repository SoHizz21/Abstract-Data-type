//Peerapat Saengphoem
//6530300376
 
#include <iostream>
using namespace std;

struct Node{
	char value;
	struct Node *Next;
};
typedef struct Node *Stack;
int open = 0, close = 0;

bool IsEmpty(Stack S);
bool match(char open, char close);
char reverseCheck(char in1);
char Top(Stack S);
void Check(Stack S,Stack s1);
void swapStack(Stack current,Stack newStack,bool bCheck);
void Push(char symbol,Stack S);
void Pop(Stack S);
Stack CreateStack();

int main(){
	char in1;
	Stack openBracket = CreateStack();
	Stack closeBracket = CreateStack();
	cout << "Input: ";
	do{
		cin >> in1;
		if(in1 == '.'){
			break;
		}
		else{
			(in1 == '{') ? (Push(in1,openBracket),open++): 
			(in1 == '[') ? (Push(in1,openBracket),open++):
			(in1 == '(') ? (Push(in1,openBracket),open++):
			(in1 == '<') ? (Push(in1,openBracket),open++): (Push(in1,closeBracket),close++); 			
		}	
	}while(true);
	Check(openBracket,closeBracket);
	return 0;
}

void swapStack(Stack current,Stack newStack,bool bCheck){ 
	if(bCheck){
		while(!IsEmpty(current)){
			Push(reverseCheck(current->Next->value),newStack);
			Pop(current);
		}
	}else{
		while(!IsEmpty(current)){
			Push(current->Next->value,newStack);
			Pop(current);
		}
	}
}

void Check(Stack S,Stack s1){
	Stack s2 = CreateStack();
	int i = 0,Loop;
	swapStack(S,s2,false);
	(open > close) ? Loop = open : Loop = close;	
	while(i < Loop){
		if(IsEmpty(s1)){
			swapStack(s2,S,true);
		}else if (IsEmpty(s2)){
			swapStack(s1,S,true);
		}else{
			if(match(s2->Next->value,s1->Next->value)){
				Pop(s1);
				Pop(s2);	
			}else{
				(open > close) ? (Push(reverseCheck(s2->Next->value),S),Pop(s2),open--) : (Push(reverseCheck(s1->Next->value),S),Pop(s1),close--);

			}
		}	
		i++;
	}
	if(IsEmpty(S)){
		cout << "Complete!";
	}else{
		cout << "Expected ";
		while(!IsEmpty(S)){
			cout << Top(S) << " ";
			Pop(S);
		}	
	}
}

bool match(char open, char close){
    return (open == '{' && close == '}') || (open == '(' && close == ')') || (open == '[' && close == ']') || (open == '<' && close == '>');
}

bool IsEmpty(Stack S){
	return S->Next == NULL;
}

char Top(Stack S){
	if(!IsEmpty(S))
		return S->Next->value;
	else
		cout << "Stack Empty!";
}

char reverseCheck(char in1){
	char rev;
	(in1 == '{') ? rev = '}': 
	(in1 == '[') ? rev = ']':
	(in1 == '(') ? rev = ')':
	(in1 == '<') ? rev = '>':
	(in1 == '}') ? rev ='{': 
	(in1 == ']') ? rev ='[':
	(in1 == ')') ? rev ='(':
	(in1 == '>') ? rev ='<': rev = '0';	
	return rev;
}

void Push(char symbol,Stack S){
	Stack TmpCell;
	TmpCell = new struct Node;
	if(TmpCell == NULL){
		cout << "Out of space!!";
	}else{
		TmpCell->value = symbol;
		TmpCell->Next = S->Next;
		S->Next = TmpCell;
	}
}

void Pop(Stack S){
	Stack FirstCell;
	if(IsEmpty(S)){
		cout << "Empty Stack!";
	}else{
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