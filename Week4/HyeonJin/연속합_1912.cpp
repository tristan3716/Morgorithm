#include <stdio.h>

int num[100001] = { -2000, };
int sum[100001] = { -3000, };
int max = -2000;

int main()
{
	int n;

	scanf("%d", &n);

	num[0] = 0;
	sum[0] = 0;
	
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &num[i]);
		
	}
	for (int i = 1; i <= n; i++)
	{
		if (sum[i - 1] < 0)
			sum[i] = num[i];
		else
			sum[i] = sum[i - 1] + num[i];
		
	}
	for (int i = 1; i <= n; i++)
	{
		if (sum[i] > max)
			max = sum[i];
	}
		printf("%d\n", max);
	return 0;
}