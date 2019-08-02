#include<iostream>

int main()
{
	int size;
	int res = 0;
	std::cin >> size;
	int* left = (int*)calloc(size, sizeof(int));
	int* right = (int*)calloc(size, sizeof(int));

	for (int i = 0; i < size; i++)
		std::cin >> left[i];
	for (int i = 0; i < size; i++)
		std::cin >> right[i];

	int idx_l = 0, idx_r = 0;
	
	while (idx_l < size && idx_r < size)
	{
		if (left[idx_l] > right[idx_r])
		{
			res = res + right[idx_r];
			idx_r++;
		}
		else
		{
			if (left[idx_l+1] > right[idx_r])
			{
				idx_l++;
			}
			else
			{
				int pos = 0;
				bool both_drow = false;
				for (int i = idx_l; i < size; i++)
				{
					if (left[i] > right[idx_r])
					{
						pos = i;
						break;
					}
					else if (left[i] == right[idx_r])
					{
						both_drow = true;
						break;
					}
				}
				if (both_drow)
				{
					idx_l++;
					idx_r++;
				}
				else
				{
					idx_l = pos;
				}
			}
		}
	}

	std::cout << res;
	return 0;
}