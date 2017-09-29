#include <iostream>
#include "LiLi.h"

using namespace std;

int main(){
	LiLi *lili = new LiLi();

	for (int i = 0; i <= 10; i++) {
		//lili->AddNodeHead(i);
		lili->AddNodeTail(i);
	}
	cout << "LiLi: " + lili->ToString() << endl;
	Node *pSearch = lili->Search(3);
	lili->AddNodeWithPosition(0, pSearch);
	int x = 0;
	cout << "After Add " + std::to_string(x) + ": " + lili->ToString() << endl;
	
	lili->DeleteNodeHead();
	cout << "Delete first: " + lili->ToString() << endl;
	lili->DeleteNodeTail();
	cout << "Delete last: " + lili->ToString() << endl;
	lili->DeleteNodeWithPosition(pSearch);
	cout << "Delete 5: " + lili->ToString() << endl;

	lili->ClearAll();
	cout << "Clear all: " + lili ->ToString() << endl;
	return 0;
}