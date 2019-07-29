#include <stdio.h>

__inline int max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int arr[100001];
	int n;
	unsigned int i;
	int sum = 0;
	int m = -1001;

	scanf("%d", &n);
	for (i = n; i; --i) {
		scanf("%d", &arr[i]);

		if (arr[i] > sum + arr[i]) {
			sum = arr[i];
		}
		else {
			sum += arr[i];
		}
		m = max(sum, m);
	}

	printf("%d", m);

	return 0;
}