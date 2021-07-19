#ifndef LINKED_LIST_QUEUE_H
#define LINKED_LIST_QUEUE_H

#include <malloc.h>
#include "Graph.h"

typedef Vertex* DataType;

typedef struct _Node {
	DataType Data;
	struct Node* Rear;
} Node;

typedef struct _LinkedQueue {
	Node* First;
	Node* Last;
	int Count;
} LinkedQueue;

LinkedQueue* LQ_CreateQueue();
Node* LQ_CreateNode(DataType Data);
void LQ_Enqueue(LinkedQueue* Q, Node* NewData);
Node* LQ_Dequeue(LinkedQueue* Q);
void LQ_DestroyQueue(LinkedQueue* Q);

#endif // LINKED_LIST_QUEUE_H