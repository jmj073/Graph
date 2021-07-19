#include "LinkedListQueue.h"

LinkedQueue* LQ_CreateQueue() {
	LinkedQueue* NewQ = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	NewQ->Last = NULL;
	NewQ->First = NULL;

	return NewQ;
}

Node* LQ_CreateNode(DataType Data) {
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = Data;
	NewNode->Rear = NULL;

	return NewNode;
}

void LQ_Enqueue(LinkedQueue* Q, Node* NewData) {
	if (Q->First == NULL)
		Q->First = NewData;
	else
		Q->Last->Rear = NewData;
	Q->Last = NewData;
	Q->Count++;
}

Node* LQ_Dequeue(LinkedQueue* Q) {
	Node* Popped = Q->First;
	Q->First = Q->First->Rear;

	Q->Count--;

	return Popped;
}

void LQ_DestroyQueue(LinkedQueue* Q) {
	Node* F = Q->First, * S;
	while (F != NULL) {
		S = F;
		F = F->Rear;
		free(S);
	}
	free(Q);
}