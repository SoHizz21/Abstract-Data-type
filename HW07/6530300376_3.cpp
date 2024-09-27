#include <iostream>
using namespace std;
struct node{
	string value;
	struct node *left;
	struct node *right;
};
struct record{
	struct node *treenode;
	struct record *next;
};

struct record *CreateStack(){
	struct record *S;
	S = new struct record;
	S->next = NULL;
	if(S == NULL){
		cout << "Out of Space!";
	}
	return S;
}

struct record *S = CreateStack();
bool IsEmpty(struct record *S){
	return S->next == NULL;
}

int menu(){
	int in1;
	cout << "=========MENU========" << endl;
	cout << "1. Input postorder"<< endl;
	cout << "2. Print Expression tree"<< endl;
	cout << "3. Exit"<<endl;
	cout << "Please choose> ";
	cin >> in1;
	return in1;
}

void pInorder(struct node *tree){
    if(tree == NULL){
        return;
    }
    else{
        pInorder(tree->left);
        cout << tree->value << " ";
        pInorder(tree->right);
    }
}

void pPostorder(struct node *tree){
    if(tree == NULL){
        return;
    }
    else{
        pPostorder(tree->left);
        pPostorder(tree->right);
        cout << tree->value << " ";
    }
}

void Push(struct node *data,struct record *S){
	struct record *TmpCell;
	TmpCell = new struct record;
	if(TmpCell == NULL){
		cout << "Out of space!!";
	}
    else{
		TmpCell->treenode = data;
		TmpCell->next = S->next;
		S->next = TmpCell;
	}
}

void Pop(struct record *S){
	struct record *FirstCell;
	if(IsEmpty(S)){
		cout << "Empty Stack!";
	}
    else{
		FirstCell = S->next;
		S->next = S->next->next;
		delete FirstCell;
	}
}

void createnode(string data){
	struct node *nodetree = NULL;
	nodetree = new struct node;
	nodetree->value = data;
	nodetree->left = nodetree->right = NULL;
	Push(nodetree,S);
}

struct node *insert(struct node *tree,string data){
    if(tree == NULL){
        tree = new struct node;
        tree->value  = data;
        tree->right = S->next->treenode;
        Pop(S);
		tree->left = S->next->treenode;
		Pop(S);
    }
    else if (data == "+" || data == "-" || data == "*" || data == "/"){
  		tree = new struct node;
  		tree->value = data;
    	tree->right = S->next->treenode;
    	Pop(S);
		tree->left = S->next->treenode;
    	Pop(S);
    }
    return tree;
}

int main(){
	struct node *tree = NULL;
	char in1[30];
	char number;
	while(true){
		switch(menu()){
			case 1:
				cout << "Input: ";
				while(true){
					cin >> in1;
					if(in1[0] == '.'){
						break;
					}
					if(in1[0]>='0'&& in1[0]<='9'){
						createnode(in1);
					}
                    else{
						tree = insert(tree,in1);
						Push(tree,S);
					}
				}
				break;
			case 2:
				cout << "Inorder: ";
				pInorder(S->next->treenode);
				cout << endl << "Postorder: ";
				pPostorder(S->next->treenode);
				cout << endl;
				break;
			case 3:
				cout << "Exit!";
				return 0;
				break;
			default:
				cout << "Please data Try again";
				break;
			} 
		}
	return 0;
}