#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<numeric>

int main()
{
	int x, y;
	std::map<int, std::string> Map;//지도
	int idx = 0;
	std::cin >> x >> y;//지도크기
	int len;
	std::cin >> len;//입력값 길이
	std::vector<std::vector<int>> cntJungle(x, std::vector<int>(y));
	std::vector<std::vector<int>> cntOcecn(x, std::vector<int>(y));
	std::vector<std::vector<int>> cntIce(x, std::vector<int>(y));
	int** res = (int**)calloc(len, sizeof(int*));
	for (int i = 0; i < len; i++)
		res[i] = (int*)calloc(3, sizeof(int));

	while (idx<x)
	{
		std::cin.ignore();
		std::string arr;
		std::cin >> arr;
		Map[idx] = arr;//지도정보입력
			for (int j = 0; j < y; j++)
			{
				if (Map[idx][j] == 'J')
				{
					cntJungle[idx][j] = 1;
				}
				else if (Map[idx][j] == 'O')
				{
					cntOcecn[idx][j] = 1;
				}
				else
				{
					cntIce[idx][j] = 1;
				}
			}
		idx++;
	}
	idx = 0;

	while (idx < len)
	{
		int x_top, x_bot, y_top, y_bot;
		std::cin >> x_top >> y_top >> x_bot >> y_bot;
		int* sumTmp = (int*)calloc(y, sizeof(int));
		std::partial_sum(cntJungle[x_top - 1].begin(), cntJungle[x_top - 1].end(), sumTmp);
		res[idx][0] = sumTmp[y_bot - 1] - sumTmp[y_top - 2];
		std::partial_sum(cntJungle[x_bot - 1].begin(), cntJungle[x_bot - 1].end(), sumTmp);
		res[idx][0] = res[idx][0]+sumTmp[y_bot - 1] - sumTmp[y_top - 2];

		std::partial_sum(cntOcecn[x_top - 1].begin(), cntOcecn[x_top - 1].end(), sumTmp);
		res[idx][1] = sumTmp[y_bot - 1] - sumTmp[y_top - 2];
		std::partial_sum(cntOcecn[x_bot - 1].begin(), cntOcecn[x_bot - 1].end(), sumTmp);
		res[idx][1] = res[idx][1]+sumTmp[y_bot - 1] - sumTmp[y_top - 2];

		std::partial_sum(cntIce[x_top - 1].begin(), cntIce[x_top - 1].end(), sumTmp);
		res[idx][2] = sumTmp[y_bot - 1] - sumTmp[y_top - 2];
		std::partial_sum(cntIce[x_bot - 1].begin(), cntIce[x_bot - 1].end(), sumTmp);
		res[idx][2] = res[idx][2]+sumTmp[y_bot - 1] - sumTmp[y_top - 2];

		idx++;
	}
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << res[i][j] << " ";
		}
		std::cout << "\n";
	}
	return 0;
}