#include <stdio.h>

int data[13] = {0};
int length = 0;
int temp[13] = { 0 };

void combination(int start, int target)
{
	if (target == 6)
	{
		for (int i = 0; i < 6; i++)
		{
			printf("%d ", temp[i]);
		}
		printf("\n");
		return;
	}
	for (int i = start; i < length; i++)
	{
		temp[target] = data[i];
		combination(i + 1, target + 1);
	}
}
int main()
{
	int k;

	while (1)
	{
		scanf("%d", &k);
		if (k == 0)
			break;
		for (int i = 0; i < k; i++)
		{
			scanf("%d", &data[i]);
		}
		length = k;

		combination(0,0);
		printf("\n");
	}
	return 0;
}