#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include "PriorityQueue.h"

enum VisitMode {Visited, NotVisited};

typedef int ElementType;

typedef struct _Vertex {
	ElementType Data;
	int Visited;
	int Index;

	struct _Vertex* Next;
	struct _Edge* AdjacencyList;
} Vertex;

typedef struct _Edge {
	int Weight;
	struct _Edge* Next;
	Vertex* From;
	Vertex* Target;
} Edge;

typedef struct _Graph {
	Vertex* Vertices;
	int VertexCount;
} Graph;


Graph* CreateGraph();
void DestroyGraph(Graph* G);
Vertex* CreateVertex(ElementType Data);
void DestroyVertex(Vertex* V);
Edge* CreateEdge(Vertex* From, Vertex* Target, int Weight);
void AddVertex(Graph* G, Vertex* V);
void AddEdge(Vertex* V, Edge* E);
void PrintGraph(Graph* G);

#endif // GRAPH_H