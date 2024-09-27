#include <iostream>
using namespace std;

struct record{
	int value;
	
	struct record *next;
};

int main(){
	int in1;
	struct record *p;
	p = new struct record;
	
	cout << "Enter : ";
	cin >> in1;
	
	p->value = in1;
	cout << "Value=" << p -> value;	
}
