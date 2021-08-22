#include "PriorityQueue.h"

PriorityQueue* PQ_Create(int InitialSize) {
	PriorityQueue* NewPQ = (PriorityQueue*)malloc(sizeof(PriorityQueue));
	NewPQ->Capacity = InitialSize;
	NewPQ->UsedSize = 0;
	NewPQ->Nodes = (PQNode*)malloc(sizeof(PQNode) * InitialSize);

	return NewPQ;
}

void PQ_Destroy(PriorityQueue* PQ) {
	free(PQ->Nodes);
	free(PQ);
}

void PQ_Enqueue(PriorityQueue* PQ, PQNode NewNode) {
	int CurrentPosition = PQ->UsedSize;
	int ParentPosition = PQ_GetParent(CurrentPosition);

	if (CurrentPosition == PQ->Capacity) {
		if (PQ->Capacity == 0)
			PQ->Capacity = 1;

		PQ->Capacity *= 2;
		PQNode* keep = (PQNode*)realloc(PQ->Nodes, sizeof(PQNode) * PQ->Capacity);
		if (keep == NULL) {
			keep = (PQNode*)malloc(sizeof(PQNode) * PQ->Capacity);
			memmove(keep, PQ->Nodes, sizeof(PQNode) * CurrentPosition);
			free(PQ->Nodes);
		}
		PQ->Nodes = keep;
	}

	PQ->Nodes[CurrentPosition] = NewNode;

	while (CurrentPosition > 0
			&& PQ->Nodes[CurrentPosition].Priority < PQ->Nodes[ParentPosition].Priority) {
		PQ_SwapNodes(PQ, CurrentPosition, ParentPosition);

		CurrentPosition = ParentPosition;
		ParentPosition = PQ_GetParent(CurrentPosition);
	}
	PQ->UsedSize++;
}

void PQ_SwapNodes(PriorityQueue* PQ, int index1, int index2) {
	PQNode Temp = PQ->Nodes[index1];
	PQ->Nodes[index1] = PQ->Nodes[index2];
	PQ->Nodes[index2] = Temp;
}

void PQ_Dequeue(PriorityQueue* PQ, PQNode* Root) {
	int ParentPosition = 0,
		LeftPosition = 0,
		RightPosition = 0;

	*Root = PQ->Nodes[0];

	PQ_SwapNodes(PQ, 0, --PQ->UsedSize);

	LeftPosition = PQ_GetLeftChild(0);
	RightPosition = LeftPosition + 1;

	while (1) {
		int SelectedChild = 0;

		if (LeftPosition >= PQ->UsedSize)
			break;
		if (RightPosition >= PQ->UsedSize)
			SelectedChild = LeftPosition;
		else {
			if (PQ->Nodes[LeftPosition].Priority > PQ->Nodes[RightPosition].Priority)
				SelectedChild = RightPosition;
			else
				SelectedChild = LeftPosition;
		}
		if (PQ->Nodes[SelectedChild].Priority < PQ->Nodes[ParentPosition].Priority) {
			PQ_SwapNodes(PQ, SelectedChild, ParentPosition);
			ParentPosition = SelectedChild;
		}
		else
			break;

		LeftPosition = PQ_GetLeftChild(ParentPosition);
		RightPosition = LeftPosition + 1;
	}

	if (PQ->Nodes < PQ->Capacity / 2) {
		PQ->Capacity /= 2;
		PQ->Nodes = (PQNode*)realloc(PQ->Nodes, sizeof(PQNode) * PQ->Capacity);
	}
}

int PQ_GetParent(int Index) {
	return (Index - 1) / 2;
}

int PQ_GetLeftChild(int Index) {
	return Index * 2 + 1;
}

int PQ_IsEmpty(PriorityQueue* PQ) {
	return PQ->UsedSize == 0;
}