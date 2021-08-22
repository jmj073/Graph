#include "MST.h"

void Prim(Graph* G, Vertex* StartVertex, Graph* MST) {
	int i = 0;

	PQNode StartNode = { 0, StartVertex };
	PriorityQueue* PQ = PQ_Create(10);

	Vertex* CurrentVertex = NULL;
	Edge* CurrentEdge = NULL;

	int* Weights = (int*)malloc(sizeof(int) * G->VertexCount);
	Vertex** MSTVertices = (Vertex**)malloc(sizeof(int) * G->VertexCount);
	Vertex** Fringes = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);
	Vertex** Precedences = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);

	CurrentVertex = G->Vertices;
	while (CurrentVertex) {
		// 정점 리스트 생성
		Vertex* NewVertex = CreateVertex(CurrentVertex->Data);
		AddVertex(MST, NewVertex);
		// 세팅
		Fringes[i] = NULL;
		Precedences[i] = NULL;
		MSTVertices[i] = NewVertex;
		Weights[i] = 2147000000;
		CurrentVertex = CurrentVertex->Next;
		i++;
	}

	PQ_Enqueue(PQ, StartNode);

	Weights[StartVertex->Index] = 0;

	while (!PQ_IsEmpty(PQ)) {
		// 힙에서 디큐
		PQNode Popped;
		PQ_Dequeue(PQ, &Popped);
		CurrentVertex = (Vertex*)Popped.Data;
		// 인덱스에 현재 정점 저장?
		Fringes[CurrentVertex->Index] = CurrentVertex;
		// 현재 정점의 간선
		CurrentEdge = CurrentVertex->AdjacencyList;
		// 간선 탐색
		while (CurrentEdge) {
			// 현재 간선의 타깃
			Vertex* TargetVertex = CurrentEdge->Target;
			// 간선의 타깃 정점이 저장이 안 되어 있고
			if (Fringes[TargetVertex->Index] == NULL
				// 간선의 가중치가 타깃 정점의 가중치보다 작으면?
				//똑같은 정점에 대해 가중치가 더 작은 쪽을 고르려는 것?
				&& CurrentEdge->Weight < Weights[TargetVertex->Index]) {
				PQNode NewNode = { CurrentEdge->Weight, TargetVertex };
				// 타깃 정점을 가중치화 함께 넣는다
				PQ_Enqueue(PQ, NewNode);

				Precedences[TargetVertex->Index] = CurrentEdge->From;
				Weights[TargetVertex->Index] = CurrentEdge->Weight;
			}
			CurrentEdge = CurrentEdge->Next;
		}
	}

	for (i = 0; i < G->VertexCount; i++) {
		int FromIndex, ToIndex;
		if (Precedences[i] == NULL)
			continue;

		FromIndex = Precedences[i]->Index;
		ToIndex = i;

		AddEdge(MSTVertices[FromIndex],
			CreateEdge(MSTVertices[FromIndex], MSTVertices[ToIndex], Weights[i]));
		AddEdge(MSTVertices[ToIndex],
			CreateEdge(MSTVertices[ToIndex], MSTVertices[FromIndex], Weights[i]));

	}
	free(Fringes);
	free(Precedences);
	free(MSTVertices);
	free(Weights);
}

void Kruskal(Graph* G, Graph* MST) {
	int i;
	Vertex* CurrentVertex = NULL;
	Vertex** MSTVertices = (Vertex**)malloc(sizeof(Vertex*) * G->VertexCount);

	DisjointSet** VertexSet = (DisjointSet**)malloc(sizeof(DisjointSet*) * G->VertexCount);

	PriorityQueue* PQ = PQ_Create(10);

	i = 0;
	CurrentVertex = G->Vertices;
	while (CurrentVertex) {
		VertexSet[i] = DS_MakeSet(CurrentVertex);
		MSTVertices[i] = CreateVertex(CurrentVertex->Data);
		AddVertex(MST, MSTVertices[i]);

		Edge* CurrentEdge = CurrentVertex->AdjacencyList;
		while (CurrentEdge) {
			PQNode NewNode = { CurrentEdge->Weight, CurrentEdge };
			PQ_Enqueue(PQ, NewNode);

			CurrentEdge = CurrentEdge->Next;
		}
		CurrentVertex = CurrentVertex->Next;
		i++;
	}

	while (!PQ_IsEmpty(PQ)) {
		Edge* CurrentEdge;
		int FromIndex;
		int ToIndex;
		PQNode Popped;

		PQ_Dequeue(PQ, &Popped);
		CurrentEdge = (Edge*)Popped.Data;

		FromIndex = CurrentEdge->From->Index;
		ToIndex = CurrentEdge->Target->Index;

		if (DS_FindSet(VertexSet[FromIndex]) != DS_FindSet(VertexSet[ToIndex])) {

			AddEdge(MSTVertices[FromIndex], CreateEdge(MSTVertices[FromIndex], MSTVertices[ToIndex], CurrentEdge->Weight));
			AddEdge(MSTVertices[ToIndex], CreateEdge(MSTVertices[ToIndex], MSTVertices[FromIndex], CurrentEdge->Weight));

			DS_UnionSet(VertexSet[FromIndex], VertexSet[ToIndex]);
		}
	}



	for (i = 0; i < G->VertexCount; i++)
		free(VertexSet[i]);

	free(VertexSet);
	free(MSTVertices);
	PQ_Destroy(PQ);
}