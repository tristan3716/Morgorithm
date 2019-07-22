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
 * 
 * 그럼 답은 재귀다
 * 양쪽 다 가보고 결과가 가까운 곳을 선택
 * (양 쪽 모두 이동했다 가정하고, 가장 마지막 테스트케이스부터 거꾸로 거슬러올라옴)
 * 근데 시간초과네 메모이제이션을 어떻게 해야할지 모르겠다
 * 트레이싱도...
 * ------------------------------------------------------------------------------------------------ */
 
#include <stdio.h>
#include <malloc.h>

inline int mini(int a, int b) {
	return a & ((a - b) >> 31) | b & (~(a - b) >> 31);
}

int absi(int x) {
	return (x ^ (x >> 31)) - (x >> 31);
}

inline int abs(int x) {
	return x < 0 ? -x : x;
}

int getDistance(int ax, int ay, int bx, int by) {
	return abs(ax - bx) + abs(ay - by);
}

int resolve(int level, int w, int **cases, int *record, int x1, int y1, int x2, int y2) {
	if (level == w)
		return 0; 
	for (int i = 0; i < level; i = -~i) {
		printf("\t");
	}
	printf("Current case : %d (%d, %d)\n", level, cases[level][0], cases[level][1]);
	printf("police1 pos : (%d, %d)\n", x1, y1);
	printf("police1 pos : (%d, %d)\n", x2, y2);
	int cx = cases[level][0];
	int cy = cases[level][1];
	int dis1 = resolve(level + 1, w, cases, record, cx, cy, x2, y2) + getDistance(x1, y1, cx, cy);
	int dis2 = resolve(level + 1, w, cases, record, x1, y1, cx, cy) + getDistance(x2, y2, cx, cy);

	int ret = mini(dis1, dis2);
	for (int i = 0; i < level; i++) {
		printf("\t");
	}
	printf("%d : %d\n", 1, getDistance(x1, y1, cx, cy));
	for (int i = 0; i < level; i++) {
		printf("\t");
	}
	printf("%d : %d\n", 2, getDistance(x2, y2, cx, cy));
	for (int i = 0; i < level; i++) {
		printf("\t");
	}
	printf("ret : %d\n", ret);
	return ret;
}

int main(void)
{
	int n;
	int w;
	int x, y;
	scanf("%d %d", &n, &w);

	int **cases = (int **)malloc(n * sizeof(int *));
	for (int i = 0; i < w; i++) {
		scanf("%d %d", &x, &y);
		cases[i] = (int *)malloc(2 * sizeof(int));
		cases[i][0] = x;
		cases[i][1] = y;
	}
	int *record = (int *)calloc(w, sizeof(int));

	int total_move = resolve(0, w, cases, record, 1, 1, n, n);

	printf("%d\n", total_move);

	for (int i = 0; i < w; i++) {
		printf("%d\n", record[i]);
	}

	return 0;
}