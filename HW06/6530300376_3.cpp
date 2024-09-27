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
    cout << "2)Print"<< endl;
    cout << "3)Find min"<< endl;
    cout << "4)Exit"<< endl;
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
        }else if(x > tree->value){
            tree->right = insert(tree->right,x);
        }
    }
    return tree;
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

void printPre(struct node *tree){
    if(tree == NULL){
        return;
    }
    else{
        cout << tree->value << " ";
        printPre(tree->left);
        printPre(tree->right);
    }
}

void printIn(struct node *tree){
    if(tree == NULL){
        return;
    }
    else{
        printIn(tree->left);
        cout << tree->value << " ";
        printIn(tree->right);
    }
}

void printPost(struct node *tree){
    if(tree == NULL){
        return;
    }
    else{
        printPost(tree->left);
        printPost(tree->right);
        cout << tree->value << " ";
    }
}

int main() {
    struct node *tree = NULL;
    struct node *min;
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
                cout << "Preorder: ";
                printPre(tree);
                cout << endl << endl << "Inorder: ";
                printIn(tree);
                cout << endl << endl << "Postorder: ";
                printPost(tree);
                cout << endl;
                break;
            case 3:
                 min = find_min(tree);
                 cout << "Min = " << min->value << endl;
                break;
            case 4:
                return 0;
                cout << "Bye!";
                break;
            default:
                break;
        }
    }
    return 0;
}