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
 * 메모이제이션 하기 위해 호출 구조 확인.
 * 중복계산하는 부분에 메모이제이션을 적용하기위해 기존 좌표를 인자로 넘기던 방식에서
 * 좌표배열(cases)의 인덱스를 넘겨줌
 * dp[a][b]는 현재 경찰차가 a, b에 있을 때 다음 사건을 해결하기위한 비용
 * ------------------------------------------------------------------------------------------------ */

#include <stdio.h>
#include <malloc.h>

inline int mini(int a, int b) {
	return a & ((a - b) >> 31) | b & (~(a - b) >> 31);
}
inline int maxi(int a, int b) {
	return b & ((a - b) >> 31) | a & (~(a - b) >> 31);
}

inline int absi(int x) {
	return (x ^ (x >> 31)) - (x >> 31);
}

int getDistance(int ax, int ay, int bx, int by) {
	return absi(ax - bx) + absi(ay - by);
}

int resolve(int w, int **dp, int **cases, int **record, int a, int b) {
	int level = maxi(a, b) + 1;

	if (level == w)
		return 0;

	else if (dp[a][b] != -1) {
		return dp[a][b];
	}

	int cx = cases[level][0];
	int cy = cases[level][1];
	int dis1 = resolve(w, dp, cases, record, level, b) + getDistance(cases[a][0], cases[a][1], cx, cy);
	int dis2 = resolve(w, dp, cases, record, a, level) + getDistance(cases[b][0], cases[b][1], cx, cy);

	dp[a][b] = mini(dis1, dis2);
	if (mini(dis1, dis2) ^ dis1) {
		record[a][b] = 2;
	}
	else {
		record[a][b] = 1;
	}

	return dp[a][b];
}

int main(void)
{
	int n;
	int w;
	int x, y;
	scanf("%d %d", &n, &w);

	int **dp = (int **)malloc((w + 1) * sizeof(int *));
	dp[0] = (int *)calloc(w + 1, sizeof(int));
	dp[1] = (int *)calloc(w + 1, sizeof(int));
	for (int j = 0; j < w + 2; j++) {
		dp[0][j] = -1;
		dp[1][j] = -1;
	}

	int **cases = (int **)malloc((n + 2) * sizeof(int *));
	cases[0] = (int *)malloc(2 * sizeof(int));
	cases[1] = (int *)malloc(2 * sizeof(int));
	cases[0][0] = 1;
	cases[0][1] = 1;
	cases[1][0] = n;
	cases[1][1] = n;
	for (int i = 2; i < w + 2; i++) {
		scanf("%d %d", &x, &y);
		cases[i] = (int *)malloc(2 * sizeof(int));
		cases[i][0] = x;
		cases[i][1] = y;
		dp[i] = (int *)malloc((w + 1) * sizeof(int));
		for (int j = 0; j < w + 1; j++) {
			dp[i][j] = -1;
		}
	}
	int **record = (int **)malloc((w+1) * sizeof(int *));
	for (int i = 0; i < w+2; i++) {
		record[i] = (int *)calloc(w+1, sizeof(int));
	}
	int total_move = resolve(w + 2, dp, cases, record, 0, 1);

	printf("%d\n", total_move);

	for (int x = 0, y = 1; maxi(x, y) + 1 < w + 2; ) {
		printf("%d\n", record[x][y]);
		if (record[x][y] == 2)
			y = maxi(x, y) + 1;
		else
			x = maxi(x, y) + 1;
	}

	return 0;
}