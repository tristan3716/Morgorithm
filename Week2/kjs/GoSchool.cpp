#include<iostream>
#include<vector>
#include<string>

int solution(int m, int n, std::vector<std::vector<int>> puddles);

int main()
{
	std::vector<std::vector<int>> v;
	std::vector<int> n;
	n.push_back(2);
	n.push_back(2);
	v.push_back(n);
	int answer = solution(4, 3, v);

	std::cout << answer;

	return 0;
}

int solution(int m, int n, std::vector<std::vector<int>> puddles)
{
	int answer = 0;
	int** Map = (int**)calloc(n, sizeof(int*));

	for (int i = 0; i < n; i++)
		Map[i] = (int*)calloc(m, sizeof(int));

	Map[0][0] = -1;

	for (auto i = puddles.begin(); i < puddles.end(); i++)
	{
		Map[(*i)[0]-1][(*i)[1]-1] = -1;
	}
	for (int i = 0; i < n; i++)
	{
		if (i == 0)
		{
			for (int j = 1; j < m; j++)
			{
				if (Map[i][j] != -1)
				{
					Map[i][j] = 1;
				}
			}
		}
		else
		{
			if (Map[i][0] != -1)
			{
				Map[i][0] = 1;
			}
		}
	}
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < m; j++)
		{
			if (Map[i][j] == 0)
			{
				if (Map[i - 1][j] != -1 && Map[i][j - 1] != -1)
				{
					Map[i][j] = Map[i - 1][j] + Map[i][j - 1];
				}
				else
				{
					Map[i][j] = 1;
				}
			}
		}
	}

	answer = Map[n - 1][m - 1];
	return answer;
}