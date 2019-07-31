#include <stdio.h>

__inline int max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int tmp;
	int n;
	unsigned int i;
	int sum = 0;
	int m = -1001;

	scanf("%d", &n);
	for (i = n; i; --i) {
		scanf("%d", &tmp);

		if (tmp > sum + tmp) {
			sum = tmp;
		}
		else {
			sum += tmp;
		}
		m = max(sum, m);
	}

	printf("%d", m);

	return 0;
}