#include "LinkedList.h"

LNode* SLL_CreateNewNode(LDataType NewData) {
	LNode* NewLNode = (LNode*)malloc(sizeof(LNode));

	NewLNode->Data = NewData;
	NewLNode->Next = NULL;

	return NewLNode;
}

void SLL_InsertNewHead(LNode** List, LNode* NewHead) {
	NewHead->Next = *List;
	*List = NewHead;
}

void SLL_DestroyAllLNodes(LNode* Node) {
	LNode* cur;
	while (Node != NULL) {
		cur = Node;
		Node = Node->Next;
		free(cur);
	}
}