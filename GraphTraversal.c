#include "GraphTraversal.h"

void DFS(Vertex* V) {
	Edge* E = NULL;
	printf("%d ", V->Data);
	V->Visited = Visited;

	for (E = V->AdjacencyList; E != NULL; E = E->Next)
		if (E->Target != NULL && E->Target->Visited == NotVisited)
			DFS(E->Target);
}

void BFS(Vertex* V) {
	LinkedQueue* Q = LQ_CreateQueue();
	Edge* E = NULL;

	printf("%d ", V->Data);
	V->Visited = Visited;
	LQ_Enqueue(Q, LQ_CreateNode(V));

	while (Q->First != NULL) {
		QNode* Popped = LQ_Dequeue(Q);
		V = Popped->Data;

		for (E = V->AdjacencyList; E != NULL; E = E->Next) {
			V = E->Target;
			if (V != NULL && V->Visited == NotVisited) {
				printf("%d ", V->Data);
				V->Visited = Visited;
				LQ_Enqueue(Q, LQ_CreateNode(V));
			}
		}
	}
	LQ_DestroyQueue(Q);
}