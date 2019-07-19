#include<iostream>
#include<vector>
#include<map>
#include<string>

int main()
{
	int x, y;
	std::map<int, std::string> Map;//지도
	int idx = 0;
	std::cin >> x >> y;//지도크기
	int len;
	std::cin >> len;//입력값 길이

	int** v = (int**)calloc(len, sizeof(int*));

	for (int i = 0; i < len; i++)
		v[i] = (int*)calloc(3, sizeof(int));//정보 저장 배열

	while (idx<x)
	{
		std::cin.ignore();
		std::string arr;
		std::cin >> arr;
		Map[idx] = arr;//지도정보입력
		idx++;
	}
	idx = 0;
	while (idx<len)
	{
		int x_top, y_top, x_bot, y_bot;
		std::cin >> x_top >> y_top >> x_bot >> y_bot;//탐색구역 입력
		int ice=0, jungle=0, ocecn=0;
		for (int i = x_top - 1; i < x_bot; i++)
		{
			for (int j = y_top - 1; j < y_bot; j++)
			{//지역별 갯수
				if (Map[i][j] == 'J')
				{
					jungle++;
				}
				else if (Map[i][j] == 'O')
				{
					ocecn++;
				}
				else
				{
					ice++;
				}
			}
		}
		//항목별 입력
		v[idx][0] = jungle;
		v[idx][1] = ocecn;
		v[idx][2] = ice;
		idx++;
	}

	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			std::cout << v[i][j] << " ";//출력
		}
		std::cout << "\n";
	}

	return 0;
}