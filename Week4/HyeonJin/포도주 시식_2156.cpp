#include <stdio.h>

int grape[10001] = { -1, };
int grape_sum[10001] = { -1, };
int max = 0;

int main()
{
	int n;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &grape[i]);
	}
	grape_sum[0] = grape[0];
	grape_sum[1] = grape[0] + grape[1];

	for (int i = 2; i < n; i++)
	{
	
		int tmp1 = grape_sum[i - 3] + grape[i - 1] + grape[i];
		int tmp2 = grape_sum[i - 2] + grape[i];
		int tmp3 = grape_sum[i - 4] + grape[i - 1] + grape[i];
		if (tmp1 < tmp2)
		{
			if(tmp2 < tmp3)
				grape_sum[i] = tmp3;
			else
				grape_sum[i] = tmp2;
		}
		else
		{
			if (tmp3 > tmp1)
				grape_sum[i] = tmp3;
			else
				grape_sum[i] = tmp1;
		}
		
	}
	
	for (int i = 0; i < n; i++)
	{
		if (max < grape_sum[i])
			max = grape_sum[i];
	}
	printf("%d\n", max);
	return 0;
}