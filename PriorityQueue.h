#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

typedef int PriorityType;

typedef struct _PQNode {
	PriorityType Priority;
	void* Data;
} PQNode;

typedef struct _PriorityQueue {
	PQNode* Nodes;
	int Capacity;
	int UsedSize;
} PriorityQueue;

PriorityQueue* PQ_Create(int InitialSize);
void PQ_Destroy(PriorityQueue* PQ);
void PQ_Enqueue(PriorityQueue* PQ, PQNode NewData);
void PQ_Dequeue(PriorityQueue* PQ, PQNode* Root);
void PQ_SwapNodes(PriorityQueue* PQ, int index1, int index2);
int PQ_GetParent(int Index);
int PQ_GetLeftChild(int Index);
int PQ_IsEmpty(PriorityQueue* PQ);

#endif // PRIORITYQUEUE_H