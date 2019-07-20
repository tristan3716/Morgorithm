/* ================================================================================================
 * Baekjoon Online Judge
 *		2618 - 경찰차
 * 어떤 도시의 중심가는 N개의 동서방향 도로와 N개의 남북방향 도로로 구성되어 있다.
 * 이 도시에는 두 대의 경찰차가 있으며 두 차를 경찰차1과 경찰차2로 부른다. 
 * 처음에는 항상 경찰차1은 (1, 1)의 위치에 있고 경찰차2는 (N, N)의 위치에 있다. 
 * 경찰 본부에서는 처리할 사건이 있으면 그 사건이 발생된 위치를 두 대의 경찰차 중 하나에 알려 주고, 
 * 연락 받은 경찰차는 그 위치로 가장 빠른 길을 통해 이동하여 사건을 처리한다. 
 * (하나의 사건은 한 대의 경찰차가 처리한다.)
 * 처리해야 할 사건들이 순서대로 주어질 때, 
 * 두 대의 경찰차가 이동하는 거리의 합을 최소화 하도록 사건들을 맡기는 프로그램을 작성하시오
 * ------------------------------------------------------------------------------------------------
 * 각 구간사이의 거리를 저장해놓고 가까운걸 보내자.
 * 제출했는데 틀려따 ㅠ
 * 그리디가 그 순간에는 최적일 수 있어도, 전체적으론 손해일 수도 있다.
 * ㅎㅎ 넷플릭스나 봐야지
 * ------------------------------------------------------------------------------------------------ */
 
#include <stdio.h>
#include <malloc.h>

int max(int a, int b) {
	return a > b ? a : b;
}

int getDistance(int src, int dst) {
	int res = dst - src;
	return res < 0 ? -res : res;
}

int main(void)
{
	int n;
	int w;
	scanf("%d %d", &n, &w);

	int **distance_map = (int **)calloc(n + 1, sizeof(int *));
	distance_map[0] = (int *)calloc(n + 1, sizeof(int));
	
	for (int i = 1; i <= n; i++) {
		distance_map[i] = (int *)calloc(n + 1, sizeof(int));
		for (int j = 1; j <= n; j++) {
			distance_map[i][j] = max(distance_map[i][j - 1], distance_map[i - 1][j]) + 1;
		}
	}

	int *record = (int *)malloc(w * sizeof(int));

	int x, y;
	int dis1, dis2;
	int x1 = 1, y1 = 1;
	int x2 = n, y2 = n;
	int total_move = 0;
	for (int i = 0; i < w; i++) {
		scanf("%d %d", &x, &y);
		dis1 = getDistance(distance_map[y][x], distance_map[y1][x1]);
		dis2 = getDistance(distance_map[y][x], distance_map[y2][x2]);
		if (dis1 < dis2) {
			y1 = y;
			x1 = x;
			total_move += dis1;
			record[i] = 1;
		}
		else {
			y2 = y;
			x2 = x;
			total_move += dis2;
			record[i] = 2;
		}
	}
	printf("%d\n", total_move);
	for (int i = 0; i < w; i++) {
		printf("%d\n", record[i]);
	}

	return 0;
}