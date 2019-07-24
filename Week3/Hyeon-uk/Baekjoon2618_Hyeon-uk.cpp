#include <stdio.h>
#include <malloc.h>

typedef struct Args {
	int w;
	int **dp;
	int **cases;
	int **record;
} Args;

__inline int min(int a, int b) {
	return a < b ? a : b;
}

__inline int max(int a, int b) {
	return a < b ? b : a;
}

__inline int abs(int x) {
	return x < 0 ? -x : x;
}

int getDistance(int ax, int ay, int bx, int by) {
	return abs(ax - bx) + abs(ay - by);
}

int resolve(Args* args, int a_pos, int b_pos) {
	int level = max(a_pos, b_pos) + 1;

	if (level == args->w)
		return 0;

	else if (args->dp[a_pos][b_pos] != -1) {
		return args->dp[a_pos][b_pos];
	}

	int **dp = args->dp;
	int **cases = args->cases;

	int cx = cases[level][0];
	int cy = cases[level][1];
	int dis1 = resolve(args, level, b_pos) + getDistance(cases[a_pos][0], cases[a_pos][1], cx, cy);
	int dis2 = resolve(args, a_pos, level) + getDistance(cases[b_pos][0], cases[b_pos][1], cx, cy);

	dp[a_pos][b_pos] = min(dis1, dis2);
	if (min(dis1, dis2) ^ dis1) {
		args->record[a_pos][b_pos] = 2;
	}
	else {
		args->record[a_pos][b_pos] = 1;
	}

	return dp[a_pos][b_pos];
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

	int **cases = (int **)malloc((w + 2) * sizeof(int *));
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
	int **record = (int **)malloc((w + 1) * sizeof(int *));
	for (int i = 0; i < w + 2; i++) {
		record[i] = (int *)calloc(w + 1, sizeof(int));
	}

	Args args;
	args.w = w + 2;
	args.dp = dp;
	args.cases = cases;
	args.record = record;
	int total_move = resolve(&args, 0, 1);

	printf("%d\n", total_move);

	for (int a = 0, b = 1; max(a, b) + 1 < w + 2; ) {
		printf("%d\n", record[a][b]);
		if (record[a][b] == 2)
			b = max(a, b) + 1;
		else
			a = max(a, b) + 1;
	}

	return 0;
}