#ifndef LINKED_LIST_QUEUE_H
#define LINKED_LIST_QUEUE_H

#include <malloc.h>
#include "Graph.h"

typedef Vertex* QDataType;

typedef struct _Node {
	QDataType Data;
	struct Node* Rear;
} QNode;

typedef struct _LinkedQueue {
	QNode* First;
	QNode* Last;
	int Count;
} LinkedQueue;

LinkedQueue* LQ_CreateQueue();
QNode* LQ_CreateNode(QDataType Data);
void LQ_Enqueue(LinkedQueue* Q, QNode* NewData);
QNode* LQ_Dequeue(LinkedQueue* Q);
void LQ_DestroyQueue(LinkedQueue* Q);

#endif // LINKED_LIST_QUEUE_H