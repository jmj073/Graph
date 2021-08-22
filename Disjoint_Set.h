#ifndef UNION_SET_H
#define UNION_SET_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _Disjoint {
	struct _DisjointSet* Parent;
	void* Data;
} DisjointSet;

void DS_UnionSet(DisjointSet* Set1, DisjointSet* Set2);
DisjointSet* DS_FindSet(DisjointSet* Set);
DisjointSet* DS_MakeSet(void* NewData);

#endif // UNION_SET_H