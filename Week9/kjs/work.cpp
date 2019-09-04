#include<iostream>
#include<vector>
#include<string>

int main()
{
	std::vector<std::vector<int>> Map;
	int size;

	std::cin >> size;

	int idx = 0;

	while (idx < size)
	{
		std::vector<int> info(size);
		for (int i = 0; i < size; i++)
		{
			int cost;
			std::cin >> cost;
			info[i] = cost;
		}
		Map[idx] = info;
		idx++;
	}

	std::string Case;
	std::cin >> Case;

	int min;
	std::cin >> min;

	
}