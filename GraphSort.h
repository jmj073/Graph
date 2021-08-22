#ifndef GRAPHSORT_H
#define GRAPHSORT_H

#include "Graph.h"
#include "linkedList.h"



void TopologicalSort(Vertex* V, LNode** List);

void TS_DFS(Vertex* V, LNode** List);

#endif // GRAPHSORT_H