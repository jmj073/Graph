#include "GraphSort.h"

void TopologicalSort(Vertex* V, LNode** List) {
	while (V != NULL && V->Visited == NotVisited) {
		TS_DFS(V, List);

		V = V->Next;
	}
}

void TS_DFS(Vertex* V, LNode** List) {
	Edge* E = NULL;

	V->Visited = Visited;
	
	for (E = V->AdjacencyList; E != NULL; E = E->Next)
		if (E->Target != NULL && E->Target->Visited == NotVisited)
			TS_DFS(E->Target, List);
	printf("%c\n", V->Data);
	
	SLL_InsertNewHead(List, SLL_CreateNewNode(V));
}