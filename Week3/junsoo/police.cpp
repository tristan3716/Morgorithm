#include<iostream>
#include<vector>

int main()
{
	int size, len, move = 0;
	int idx = 0;
	int* move1 = (int*)calloc(2, sizeof(int));
	int* move2 = (int*)calloc(2, sizeof(int));
	
	std::cin >> size >> len;
	std::vector<std::vector<int>> v(len, std::vector<int>());
	int** arr = (int**)calloc(size, sizeof(int*));
	


	for (int i = 0; i < size; i++)
		arr[i] = (int*)calloc(size, sizeof(int));

	while (idx<len)
	{
		int x, y;
		std::cin >> x >> y;
		v[idx].push_back(x-1);
		v[idx].push_back(y-1);
		if (y <= size / 2)
		{
			arr[x - 1][y - 1] = 1;
			if (move1[0] == 0 && move1[1] == 0)
			{
				move1[0] = x - 1;
				move1[1] = y - 1;
			}
			else
			{
				move1[0] = move1[0] + (move1[0] - (x - 1));
				move1[1] = move1[1] + (move1[0] - (y - 1));
			}
		}
		else
		{
			arr[x - 1][y - 1] = 2;
			if (move2[0] == 0 && move2[1] == 0)
			{
				move2[0] = 6-(x - 1);
				move2[1] = 6-(y - 1);
			}
			else
			{
				move2[0] = move2[0] + (move2[0] - (x - 1));
				move2[1] = move2[1] + (move2[0] - (y - 1));
			}
		}
		idx++;
	}

	move = move1[0] + move1[1] + move2[0] + move2[1];
	std::cout << move<<"\n";
	for (int i = 0; i < len; i++)
	{
		std::cout << arr[v[i][0]][v[i][1]] << "\n";
	}

	return 0;
}