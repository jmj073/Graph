//#include "Graph.h"
//#include "GraphSort.h"
//
//void main(void) {
//	int i;
//	LNode* SortedList = NULL;
//	LNode* CurrentNode = NULL;
//	Vertex* VertexList[10];
//
//	Graph* graph = CreateGraph();
//
//	for (i = 0; i < 8; i++)
//		VertexList[i] = CreateVertex('A' + i);
//
//
//	AddVertex(graph, VertexList[0]);
//	AddVertex(graph, VertexList[2]);
//	AddVertex(graph, VertexList[1]);
//	AddVertex(graph, VertexList[3]);
//	AddVertex(graph, VertexList[4]);
//	AddVertex(graph, VertexList[5]);
//	AddVertex(graph, VertexList[6]);
//	AddVertex(graph, VertexList[7]);
//
//	AddEdge(VertexList[0], CreateEdge(VertexList[0], VertexList[2], 0));
//	AddEdge(VertexList[0], CreateEdge(VertexList[0], VertexList[3], 0));
//
//	AddEdge(VertexList[1], CreateEdge(VertexList[1], VertexList[2], 0));
//	AddEdge(VertexList[1], CreateEdge(VertexList[1], VertexList[4], 0));
//
//	AddEdge(VertexList[2], CreateEdge(VertexList[2], VertexList[5], 0));
//
//	AddEdge(VertexList[3], CreateEdge(VertexList[3], VertexList[5], 0));
//	AddEdge(VertexList[3], CreateEdge(VertexList[3], VertexList[6], 0));
//
//	AddEdge(VertexList[4], CreateEdge(VertexList[4], VertexList[6], 0));
//
//	AddEdge(VertexList[5], CreateEdge(VertexList[5], VertexList[7], 0));
//
//	AddEdge(VertexList[6], CreateEdge(VertexList[6], VertexList[7], 0));
//
//	TopologicalSort(graph->Vertices, &SortedList);
//
//	printf("Topological Sort Result : ");
//
//	for (CurrentNode = SortedList; CurrentNode != NULL; CurrentNode = CurrentNode->Next)
//		printf("%C ", ((Vertex*)CurrentNode->Data)->Data);
//
//	DestroyGraph(graph);
//
//	SLL_DestroyAllLNodes(SortedList);
//}