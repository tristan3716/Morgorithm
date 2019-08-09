#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 200000

int visited[MAX_VERTICES] = { 0 };
int temp[MAX_VERTICES] = { 0 };
typedef struct GraphNode {
	int vertex;
	struct GraphNode* link;
}GraphNode;
typedef struct GraphType {
	int n;
	GraphNode *adj_list[MAX_VERTICES];

}GraphType;

void graph_init(GraphType *g,int n)
{
	g->n = n;
	for (int i = 0; i < MAX_VERTICES; i++)
		g->adj_list[i] = NULL;
}

void insert_edge(GraphType *g, int u, int v)
{
	GraphNode *node;

	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
	
	/*vnode = (GraphNode*)malloc(sizeof(GraphNode));
	vnode->vertex = u;
	vnode->link = g->adj_list[v];
	g->adj_list[v] = vnode;*/
	//printf("%d 번에서 %d번으로 vertex: %d\n", u, v, g->adj_list[u]->vertex);
}
//void Graph_Display(GraphType *g)
//{
//	int i;
//	GraphNode *tmp;
//	for (i = 1; i <= g->n; i++) {
//		tmp = g->adj_list[i];
//		printf("%d -> ", i);
//		while (tmp != NULL) {
//			printf("%2d", tmp->vertex);
//			tmp = tmp->link;
//		}
//		printf("\n");
//	}
//}
void dfs(GraphType *g,int v)
{
	GraphNode *w;

	visited[v]++;

	temp[v] += visited[v];
	for (w=g->adj_list[v];w;w=w->link)
	{	
		
			if (!visited[w->vertex])
			{	
				dfs(g, w->vertex);
				//w = g->adj_list[w->vertex];
				
			}
	}
}
int main()
{
	int N, M;
	GraphType g;

	int max = 0;
	scanf("%d %d", &N, &M);
	graph_init(&g,N);

	
	for (int i = 0; i < M; i++)
	{
		int A, B;
		scanf("%d %d", &A, &B);
		insert_edge(&g, A, B);
	}
	//Graph_Display(&g);
	for (int i = 1; i <= N; i++)
	{
		memset(visited, 0, sizeof(visited));
		dfs(&g,i);
	}
	for (int i = 1; i <= N; i++)
	{
	
		if (max < temp[i])
			max = temp[i];
	}
	for (int i = 1; i <= N; i++)
	{

		if (max == temp[i])
			printf("%d ", i);
	}printf("\n");
	//system("pause");
	return 0;
}

