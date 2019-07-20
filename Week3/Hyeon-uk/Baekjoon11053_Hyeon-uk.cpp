/* ================================================================================================
 * Baekjoon Online Judge
 *		11053 - 가장 긴 증가하는 부분 수열
 * 수열 A가 주어졌을 때, 가장 긴 증가하는 부분 수열을 구하는 프로그램을 작성하시오.
 * 예를 들어, 수열 A = {10, 20, 10, 30, 20, 50} 인 경우에 
 * 가장 긴 증가하는 부분 수열은 A = {10, 20, 30, 50} 이고, 길이는 4이다.
 * ------------------------------------------------------------------------------------------------
 * 4561234
 1
 2
 3
 4

 * ------------------------------------------------------------------------------------------------ */

#include <stdio.h>
#include <malloc.h>

int main(void)
{
	int n;
	int *arr;
	int *dp;
	scanf("%d", &n);
	arr = (int *)malloc(sizeof(int) * n);
	dp = (int *)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			printf("Compare arr[%d] : %d and arr[%d] : %d\n", j, arr[j], i, arr[i]);
			if (arr[j] < arr[i] && dp[i] <= dp[j]) {
				printf("dp[%d] is update (%d)\n", i, j);
				dp[i] = dp[j] + 1;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d", dp[i]);
	}

	return 0;
}