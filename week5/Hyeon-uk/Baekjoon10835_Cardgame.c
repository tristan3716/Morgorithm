#include <stdio.h>

typedef struct _Deck {
	int n;
	int *l;
	int *r;
	int (*dp)[2000];
} Deck;

__inline int max(int a, int b) {
	return a > b ? a : b;
}

int solve(Deck *d, int a, int b) {
	if (d->n == max(a, b)) {
		return 0;
	}
	int *dp = &d->dp[a][b];
	int al = *dp;
	if (al != -1) {
		return al;
	}
	int left = d->l[a];
	int right = d->r[b];
	int s1, s2, s3 = 0;
	s1 = solve(d, a + 1, b);
	s2 = solve(d, a + 1, b + 1);
	if (left > right) {
		s3 = solve(d, a, b + 1) + right;
	}
	*dp = al = max(s1, max(s2, s3));
	return al;
}

int main(void) {
	int n;
	int i, j;
	int dp[2000][2000];
	for (i = 0; i < 2000; ++i) {
		for (j = 0; j < 2000; ++j) {
			dp[i][j] = -1;
		}
	}
	int left[2000];
	int right[2000];
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &left[i]);
	for (i = 0; i < n; i++)
		scanf("%d", &right[i]);

	Deck d;
	d.n = n;
	d.l = left;
	d.r = right;
	d.dp = dp;
	printf("%d", solve(&d, 0, 0));
}