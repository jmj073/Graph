#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <malloc.h>
#include <stdio.h>

typedef void* LDataType;

typedef struct _LNode {
	LDataType Data;
	struct _Node* Next;
} LNode;

LNode* SLL_CreateNewNode(LDataType NewData);

void SLL_InsertNewHead(LNode** List, LNode* NewHead);

void SLL_DestroyAllLNodes(LNode* Node);

#endif // LINKEDLIST_H