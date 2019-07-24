#include <stdio.h>

int horizon[16];
int right_diagonal[31];
int left_diagonal[31];

void print(int *d) {
	for (int i = 0; i < 31; i++) {
		printf("%d", right_diagonal[i]);
	}
	puts("");
}

int solve(int r, const int n) {
	if (r > n) {
		return 1;
	}
	
	int sum = 0;

	for (int i = 1; i <= n; i++) {
		if (!horizon[i] && !right_diagonal[r + i] && !left_diagonal[n + (r - i) + 1]) {
			horizon[i] = right_diagonal[r + i] = left_diagonal[n + (r - i) + 1] = 1;
			sum += solve(r + 1, n);
			horizon[i] = right_diagonal[r + i] = left_diagonal[n + (r - i) + 1] = 0;
		}
	}

	return sum;
}

int main()
{
	int n, res;
	scanf("%d", &n);
	res = solve(1, n);
	printf("%d\n", res);
}