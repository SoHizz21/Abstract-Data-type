#include <iostream>
using namespace std;
struct node{
    int value;
    int height;
    struct node *left;
    struct node *right;
};

int menu(){
    int in1;
    cout << "========MENU======"<< endl;
    cout << "1)Insert"<< endl;
    cout << "2)Print Inorder"<< endl;
    cout << "3)Exit"<< endl;
    cout << "Please choose > ";
    cin >> in1;
    return in1;
}

int hight(struct node *P){
	if(P == NULL){
		return -1;
	}
    else{
		return P->height;
	}
}

struct node *insert(struct node *tree,int x){
    if(tree == NULL){
        tree = new struct node;
        tree->value  = x;
        tree->left = tree->right = NULL;
        tree->height = 0;
    }
    else{
        if(x < tree->value){
            tree->left = insert(tree->left,x);
            if(hight(tree->left)-hight(tree->right) == 2){
            	cout << "You have to rotate trees!" << endl;
            	return NULL;
			}
        }
        else if(x > tree->value){
            tree->right = insert(tree->right,x);
            if(hight(tree->right)-hight(tree->left) == 2){
            	cout << "You have to rotate trees!" << endl;
            	return NULL;
			}
        }
    }
    tree->height = max(hight(tree->left),hight(tree->right)) +1;
    return tree;
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

int main() {
    struct node *tree = NULL;
    int in1;
    while(true){
        switch(menu()){
            case 1:
                cout << "Enter: ";
                cin >> in1;
                tree = insert(tree,in1);
                if(tree != NULL){
                	cout << "Success!"<<endl;
				}
                else{
					return 0;
				}
                break;
            case 2:
                cout << "Inorder: ";
                pInorder(tree);
                cout << endl;
                break;
            case 3:
            	cout << "Exit!";
            	return 0;
                break;
            default:
                cout << "please data try again"<<endl;
                break;
        }
    }
    return 0;
}