#include "LinkedListQueue.h"

LinkedQueue* LQ_CreateQueue() {
	LinkedQueue* NewQ = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	NewQ->Last = NULL;
	NewQ->First = NULL;

	return NewQ;
}

QNode* LQ_CreateNode(QDataType Data) {
	QNode* NewNode = (QNode*)malloc(sizeof(QNode));
	NewNode->Data = Data;
	NewNode->Rear = NULL;

	return NewNode;
}

void LQ_Enqueue(LinkedQueue* Q, QNode* NewData) {
	if (Q->First == NULL)
		Q->First = NewData;
	else
		Q->Last->Rear = NewData;
	Q->Last = NewData;
	Q->Count++;
}

QNode* LQ_Dequeue(LinkedQueue* Q) {
	QNode* Popped = Q->First;
	Q->First = Q->First->Rear;

	Q->Count--;

	return Popped;
}

void LQ_DestroyQueue(LinkedQueue* Q) {
	QNode* F = Q->First, * S;
	while (F != NULL) {
		S = F;
		F = F->Rear;
		free(S);
	}
	free(Q);
}