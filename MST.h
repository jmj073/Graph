#ifndef MST_H
#define MST_H

#include "Graph.h"
#include "Disjoint_Set.h"

void Prim(Graph* G, Vertex* StartVertex, Graph* MST);
void Kruskal(Graph* G, Graph* MST);

#endif