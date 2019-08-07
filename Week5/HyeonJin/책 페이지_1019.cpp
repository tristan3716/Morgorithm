#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char a[11] = { 0, };
	int N;
	int res[10] = { 0, };
	scanf("%s", a);
	N = atoi(a);
	int position = 10;
	int start = 1, finish = N;
	int length = (int)strlen(a);
	int length_count = 2;
	int flag = 0;
	int c1 = 1, c2 = length ;
	while (start<=finish)
	{
		if (start == finish)
		{
			res[start % 10]++;
			break;
		}
		position = 10;
	
			if ((start % 10) != 0)
			{
				res[start % 10]++;
				start++;
			}
			
			if ((finish  % 10) != 9)
			{
					res[finish % 10]++;
					for (int i = length_count; i <= length; i++)
					{
						res[(finish / position) % 10]++;
						position *= 10;
					}

					finish--;
					
			}
			if ((start % 10) == 0 && (finish % 10) == 9)
				break;
				
	}
	if (start < finish)
	{
		position = 10;
		while (length_count <= length)
		{
			if (length_count == length) {
				
				position = 10;
				while (c1 < c2) {
					for (int i = 0; i <= (finish / position) % 10; i++)
					{
						//if (length_count == length)
						//	if (flag == 0)
						//	{
						//		i = 1;
						//		//flag = 1;
						//	}

						res[i] += 10;
					}
					c1++;
				}
				for (int i = (start/position)%10; i <= (finish / position) % 10; i++)
				{
					if(i== (finish / position) % 10)
						res[i] += 
					res[i] += position;
					
				}
			}
			else
			{
				for (int i = 0; i < 10; i++)
				{
					res[i] += 10;
				}
				
			}
			position *= 10;
			for (int i = 0; i < 10; i++)
			{
				res[i]++;
			}

			length_count++;
			start *= 10;
		}
	}
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", res[i]);
	}
	return 0;
}
