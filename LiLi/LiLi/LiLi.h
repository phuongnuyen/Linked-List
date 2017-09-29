#pragma once
#include <iostream>
#include <string>

using namespace std;
struct Node
{
	int index;		// chứa dữ liệu (trong bài này LiLi có phần tử kiểu int)
	Node *pNext;	// contrỏ đến node kế tiếp

	static Node* CreateNode(int value) {
		Node *pNew = new Node;
		if (pNew != NULL) {
			pNew->index = value;
			pNew->pNext = NULL;
		}
		return pNew;
	}

	static void DeleteNode(Node *&node) {
		if (node != NULL) {
			delete node;
			node = NULL;	// gán NULL để khỏi trỏ lung tung
		}
	}
};

class LiLi
{
private:
	Node *pHead;
	Node *pTail;   // không có cũng được nhưng nếu có sẽ tiện hơn rất nhiều.

public:
	LiLi();
	~LiLi();

	int AddNodeHead(int value); // trả về 0 để kiểm tra nếu phương thức thành công, -1 nếu thất bại (không cấp phát được vùng nhớ cho node)
	int AddNodeTail(int value);
	int AddNodeWithPosition(int value, Node *pPos);

	int DeleteNodeHead();
	int DeleteNodeTail();
	int DeleteNodeWithPosition(Node *pPos);
	int ClearAll();

	Node* Search(int value);
	string ToString();
};

