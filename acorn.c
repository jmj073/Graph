#include<stdio.h>
#include <malloc.h>

//#define TEST_PRINT

const int N;
int Path[1000];
int KPath[1000];

typedef struct line {
	int index;
	struct line* l_next;
} Line;

typedef struct node {
	int acorn;
	Line* line;
} Node;

Line* make_line(int i) {
	Line* new_line = (Line*)malloc(sizeof(Line));
	new_line->index = i;
	new_line->l_next = NULL;

	return new_line;
}

void DestroyAll(Node** node) {
	for (int i = 0; i < N; i++) {
		for (Line* line = node[i]->line; line;) {
			Line* cur = line;
			line = line->l_next;
			free(cur);
		}
		free(node[i]);
	}
	free(node);
}

typedef struct stack_ {
	int next;
	int n;
	int acorn;
} stack_t;

void copy_path() {
	for (int i = 0; i < N; i++)
		Path[i] = KPath[i];
}

void dfs(int* max, Node** graph, int n, int cmax, int idx, int end) {
	KPath[n] = idx;
	if (n == N - 1) {
		if (idx == end && *max < cmax + graph[n][idx].acorn) {
			*max = cmax + graph[n][idx].acorn;
			copy_path();
		}
		return;
	}
	for (Line* line = graph[n][idx].line; line; line = line->l_next) {
#ifdef TEST_PRINT
		printf("\nn:%d, idx:%d, acorn:%d", n, idx, graph[n][idx].acorn);
#endif
		dfs(max, graph, n + 1, cmax + graph[n][idx].acorn, line->index, end);
	}
}

int DFS(Node** graph) {
	int max = 0;
	int end = 0;
	for (Node* g = graph[N - 1]; ~((++g)->acorn);end++);
	dfs(&max, graph, 0, 0, 0, end);
	return max;
}

int main() {
	char map[50][50];
	int i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
		scanf("%s", map[i]);

	// 기초 세팅 / 노드 할당 / 영역 개수 / 도토리 개수
	Node** graph = (Node**)malloc(sizeof(Node*) * (N + 1));
	for (i = 0; i < N; i++) {
		int cur_idx = 0;
		graph[i] = (Node*)malloc(sizeof(Node) * ((N + 1) / 2 + 1));
		graph[i][cur_idx].acorn = 0;
		graph[i][cur_idx].line = NULL;

		for (j = 0; j < N; j++) {
			switch (map[i][j]) {
			case 'D':
				graph[i][cur_idx].acorn++;
			case '.':
				map[i][j] = cur_idx;
				break;
			case 'U':
				if (j + 1 < N && map[i][j + 1] != 'U') {
					graph[i][++cur_idx].acorn = 0;
					graph[i][cur_idx].line = NULL;
				}
				break;
			}
		}
		graph[i][cur_idx + 1].acorn = -1;
#ifdef TEST_PRINT
		printf("\n");
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				printf("%c", map[i][j] < '0' ? map[i][j] + '0' : map[i][j]);
			printf("\n");
		}
#endif
	}
#ifdef TEST_PRINT
	printf("\n");
	for (i = 0; i < N; i++) {
		for (j = 0; ~(graph[i][j].acorn); j++)
			printf("%d  ", graph[i][j].acorn);
		printf("\n");
	}
#endif

	// 간선 만들기
	for (i = 0; i < N - 1; i++) {
		Node* node_list = graph[i];
		Line** line = &node_list->line;
		for (int cur = -1, j = 0; j < N; j++) {
			if (map[i][j] == 'U') {
				if (i + 1 < N && map[i][j + 1] != 'U') {
					node_list++;
					line = &node_list->line;
					cur = -1;
				}
			}
			else if (map[i + 1][j] != cur && map[i + 1][j] != 'U') {
				cur = map[i + 1][j];
				if (*line == NULL)
					*line = make_line(cur);
				else {
					(*line)->l_next = make_line(cur);
					line = &(*line)->l_next;
				}
			}
		}
	}
#ifdef TEST_PRINT
	printf("\n");
	for (i = 0; i < N; i++) {
		for (j = 0; ~(graph[i][j].acorn); j++) {
			printf("%d:%d; ", j, graph[i][j].acorn);
			for (Line* cur = graph[i][j].line; cur; cur = cur->l_next)
				printf("%d ", cur->index);
			printf("/");
		}
		printf("\n");
	}
#endif
	int max;
	max = DFS(graph);
	printf("\n\n%d\n", max);
	for (i = 0; i < N; i++)
		printf("%d ", Path[i]);

	DestroyAll(graph);
	getchar();

}
