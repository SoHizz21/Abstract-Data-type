#include <iostream>
using namespace std;
struct node{
    int value;
    struct node *left;
    struct node *right;
};

int menu(){
    int in1;
    cout << "========MENU======"<< endl;
    cout << "1)Insert"<< endl;
    cout << "2)Print Inorder, print leave node, print nonleave node"<< endl;
    cout << "3)Delete"<< endl;
    cout << "4)Find"<< endl;
    cout << "5)Exit"<< endl;
    cout << "Please choose > ";
    cin >> in1;
    return in1;
}

struct node *insert(struct node *tree,int x){
    if(tree == NULL){
        tree = new struct node;
        tree->value  = x;
        tree->left = tree->right = NULL;
    }
    else{
        if(x < tree->value){
            tree->left = insert(tree->left,x);
        }
        else if(x > tree->value){
            tree->right = insert(tree->right,x);
        }
    }
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

void pLeaves(struct node *tree){
	if(tree == NULL){
        return;
    }
    else{
        pLeaves(tree->left);
        if(tree->left == NULL && tree->right == NULL){
        	cout << tree->value << " ";
		}
        pLeaves(tree->right);
    }
}

void pNonLeaves(struct node *tree){
	if(tree == NULL){
        return;
    }
    else{
        pNonLeaves(tree->left);
        if(tree->left != NULL && tree->right != NULL){
        	cout << tree->value << " ";
		}
        pNonLeaves(tree->right);
    }
}

struct node *find_min(struct node *tree){
    if(tree == NULL){
        return NULL;
    }
    else{
        if(tree->left == NULL){
            return tree;
        }
        else{
            return (find_min(tree->left));
        }
    }
}

struct node *deleteTree(struct node *tree,int x){
	struct node *tmpcell,*child;
	if(tree == NULL){
		cout << ("No data!\n");
	}
    else{
		if(x < tree->value){
			tree->left = deleteTree(tree->left,x);
		}
        else{
			if(x > tree->value){
				tree->right = deleteTree(tree->right,x);
			}
            else{
				if(tree->left != NULL && tree->right != NULL){
					tmpcell = find_min(tree->right);
					tree->value = tmpcell->value;
					tree->right = deleteTree(tree->right,tree->value);
				}
                else{
					tmpcell = tree;
					if(tree->left == NULL)
						child = tree->right;
					if(tree->right == NULL)
						child = tree->left;
					delete tmpcell;
					return child;
				}
			}	
		}
	}
	return tree;
}

void Search(struct node *tree,int data){
	if(tree == NULL){
		cout << "Not found!" <<endl;
		return;
	}
    else{
		if(data == tree->value){
			cout << "Found!" <<endl;
			return;
		}
        else{
			if(data < tree->value){
				Search(tree->left,data);
			}if(data > tree->value){
				Search(tree->right,data);
			}
		}
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
                cout << "Success!"<<endl;
                break;
            case 2:
                cout << "Inorder: ";
                pInorder(tree);
                cout << endl << "Leave: ";
                pLeaves(tree);
                cout << endl << "Nonleave: ";
                pNonLeaves(tree);
                cout << endl;
                break;
            case 3:
                cout << "Delete: ";
                cin >> in1;
                tree = deleteTree(tree,in1);
                cout << "Success!"<<endl;
                break;
            case 4:
               	cout << "Search: ";
               	cin >> in1;
               	Search(tree,in1);
                break;
            case 5:
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
