#include "GraphTraversal.h"

void DFS(Vertex* V) {
	Edge* E = NULL;
	printf("%d ", V->Data);
	V->Visited = Visited;
	E = V->AdjacencyList;
	while (E != NULL) {
		if (E->Target != NULL && E->Target->Visited == NotVisited)
			DFS(E->Target);
		E = E->Next;
	}
}

void BFS(Vertex* V, LinkedQueue* Q) {
	Edge* E = NULL;
	printf("%d ", V->Data);
	V->Visited = Visited;

	LQ_Enqueue(Q, LQ_CreateNode(V));

	while (Q->First != NULL) {
		Node* Popped = LQ_Dequeue(Q);
		V = Popped->Data;
		E = V->AdjacencyList;

		while (E != NULL) {
			V = E->Target;
			if (V != NULL && V->Visited == NotVisited) {
				printf("%d ", V->Data);
				V->Visited = Visited;
				LQ_Enqueue(Q, LQ_CreateNode(V));
			}
			E = E->Next;
		}
	}
}