/* ================================================================================================
 * Baekjoon Online Judge
 *		11657 - 타임머신
 *
 * time limit per test : 1 seconds
 * memory limit per test : 256 megabytes
 * standard input/standard output
 *
 * N개의 도시가 있다. 
 * 그리고 한 도시에서 출발하여 다른 도시에 도착하는 버스가 M개 있다. 
 * 각 버스는 A, B, C로 나타낼 수 있는데, 
 * A는 시작도시, B는 도착도시, C는 버스를 타고 이동하는데 걸리는 시간이다. 
 * 시간 C가 양수가 아닌 경우가 있다. C = 0인 경우는 순간 이동을 하는 경우, 
 * C < 0인 경우는 타임머신으로 시간을 되돌아가는 경우이다.
 *
 * 1번 도시에서 출발해서 나머지 도시로 가는 가장 빠른 시간을 구하는 프로그램을 작성하시오.
 *
 * ------------------------------------------------------------------------------------------------
 *
 * Bellman-Ford’s algorithm
 *		optimal substructure
 *			최단 경로의 부분 경로 역시 최단경로
 *		time complexity : O(VE)
 *
 * ------------------------------------------------------------------------------------------------ */

#include <stdio.h>

#define INFINITY 1073741824

typedef struct {
	int source;
	int destination;
	int weight;
} Edge;

int bellman_ford(const Edge *e, int *distance, const int n, const int m) {
	int i, j;
	for (i = 1; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (distance[e[j].source] != INFINITY) {
				if (distance[e[j].destination] > distance[e[j].source] + e[j].weight) {
					distance[e[j].destination] = distance[e[j].source] + e[j].weight;
				}	
			}
		}
	}
	// Check negative cycle
	for (j = 0; j < m; j++) {
		if (distance[e[j].source] != INFINITY) {
			if (distance[e[j].destination] > distance[e[j].source] + e[j].weight) {
				return 0;
			}
		}
	}
	return 1;
}

int main(void) {
	int n, m;
	int i, j;
	int a, b, c;
	Edge e[6000];
	int distance[501];
	scanf("%d %d", &n, &m);

	for (i = 2; i <= n; i++) {
		distance[i] = INFINITY;
	}
	distance[1] = 0;

	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &e[i].source, &e[i].destination, &e[i].weight);
	}

	if (bellman_ford(e, distance, n, m)) {
		for (i = 2; i < n + 1; i++) {
			printf("%d\n", distance[i] == INFINITY ? -1 : distance[i]);
		}
	}
	else {
		printf("%d", -1);
	}
}