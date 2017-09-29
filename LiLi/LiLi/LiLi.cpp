#include "LiLi.h"



LiLi::LiLi()
{
	pHead = pTail = NULL;
}


LiLi::~LiLi()
{
	ClearAll();
}

int LiLi::AddNodeHead(int value) {
	Node *pNew = Node::CreateNode(value);
	if (pNew == NULL) return -1;

	if (pHead == NULL) {		// LiLi chưa có phần tử
		pHead = pTail = pNew;
	}
	else {
		pNew->pNext = pHead;
		pHead = pNew;
	}
	return 0;
}

int LiLi::AddNodeTail(int value)
{
	Node *pNew = Node::CreateNode(value);
	if (pNew == NULL) return -1;

	if (pHead == NULL) {		// LiLi chưa có phần tử
		pHead = pTail = pNew;
	}
	else {
		pTail->pNext = pNew;
		pTail = pNew;
	}
	return 0;
}

int LiLi::AddNodeWithPosition(int value, Node *pPos)
{
	if (pPos == pTail)
		return AddNodeTail(value);
	if (pPos == NULL) return -1;

	Node *pNew = Node::CreateNode(value);
	if (pNew == NULL) return -1;
		
	pNew->pNext = pPos->pNext;
	pPos->pNext = pNew;
	return 0;
}

int LiLi::DeleteNodeHead()
{
	if (pHead == NULL) return -1;

	if (pHead == pTail) {
		pTail = NULL;
		Node::DeleteNode(pHead);
	} else {
		Node *pDel = pHead;

		pHead = pDel->pNext;
		pDel->pNext = NULL;
		Node::DeleteNode(pDel);
	}
	return 0;
}

int LiLi::DeleteNodeTail()
{
	if (pHead == NULL) return -1;

	if (pHead == pTail) {
		pTail = NULL;
		Node::DeleteNode(pHead);
	} else {
		Node *pDel = pHead;
		while (pDel->pNext != pTail)
			pDel = pDel->pNext;

		pTail = pDel;
		pDel = pDel->pNext;
		pTail->pNext = NULL;
		Node::DeleteNode(pDel);
	}
	return 0;
}

int LiLi::DeleteNodeWithPosition(Node *pPos)
{
	if (pPos == pHead)
		return DeleteNodeHead();
	if (pPos == pTail)
		return DeleteNodeTail();
	if (pPos == NULL) return -1;
	
	Node *pTemp = pHead;
	while (pTemp->pNext != pPos && pTemp != NULL)
		pTemp = pTemp->pNext;

	if (pTemp == NULL)
		return -1;		// Node cần xóa không nằm trong LiLi
	
	pTemp->pNext = pPos->pNext;
	pPos->pNext = NULL;
	Node::DeleteNode(pPos);
	return 0;
}

int LiLi::ClearAll()
{
	while (pHead != NULL)
		DeleteNodeHead();
	return 0;
}

Node * LiLi::Search(int value)
{
	Node *pCur = pHead;
	while (pCur != NULL && pCur->index != value)
		pCur = pCur->pNext;

	return pCur;
}

string LiLi::ToString()
{
	string strLiLi = "{";
	Node *pCur = pHead;

	while (pCur != NULL) {
		strLiLi += std::to_string(pCur->index) + ", ";
		pCur = pCur->pNext;
	}
	return strLiLi + "}";
}
