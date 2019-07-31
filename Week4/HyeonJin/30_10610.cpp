#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100001

void merge(int list[], int left, int mid, int right);
void merge_sort(int list[], int left, int right);

char data[100001] = { 0, };
int length = 0;
int temp[100001] = { 0, };
int sum = 0;
int sorted[MAX_SIZE];

int main()
{
	scanf("%s", data);
	length = (int)strlen(data);
	for (int i = 0; i < length; i++)
	{
		sum += (data[i] - 48);
		temp[i] = data[i] - 48;
	}
	for (int i = 0; i < length; i++)
	{
		if ((data[i] - 48) == 0)
			break;
		if (i == length - 1)
		{
			printf("-1");
			return 0;
		}	
	}
	if ((sum % 3) != 0)
	{
		printf("-1");
		return 0;
	}
	merge_sort(temp, 0,length-1);

	for (int i = length - 1; i >= 0; i--)
	{
		printf("%d", temp[i]);
	}
	printf("\n");	
	return 0;
}

void merge(int list[], int left, int mid, int right)
{
	int i, j, k, l;
	i = left, j = mid + 1, k = left;

	while (i <= mid && j <= right) {
		if (list[i] <= list[j])
			sorted[k++] = list[i++];
		else
			sorted[k++] = list[j++];
	}
	if (i > mid)
		for (l = j; l <= right; l++)
			sorted[k++] = list[l];
	else
		for (l = i; l <= mid; l++)
			sorted[k++] = list[l];

	for (l = left; l <= right; l++)
		list[l] = sorted[l];
}
void merge_sort(int list[], int left, int right)
{
	int mid;
	if (left < right)
	{
		mid = (left + right) / 2;
		merge_sort(list, left, mid);
		merge_sort(list, mid + 1, right);
		merge(list, left, mid, right);
	}
}