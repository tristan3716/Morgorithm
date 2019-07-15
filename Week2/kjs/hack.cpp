#include<iostream>
#include<vector>
#include<algorithm>

int get_max(int* arr,int len);

int main()
{
	int nodes, len;
	std::cin >> nodes >> len;
	std::vector<std::vector<int>>v(nodes,std::vector<int>());//노드수와 각 노드의 신뢰id저장 벡터
	while (len > 0)
	{
		//input
		int idx, trust;
		std::cin >> idx >> trust;
		v.at(idx - 1).push_back(trust);
		len--;
	}
	int* trust_count = (int*)calloc(nodes, sizeof(int));
	int cnt = 0;
	
	for (auto i = v.begin(); i < v.end(); i++)
	{
		for (cnt = 0; cnt < nodes; cnt++)
		{
			if (std::find((*i).begin(), (*i).end(), cnt + 1) != (*i).end())//id당 신뢰받는 수
			{
				trust_count[cnt]++;
			}
		}
	}

	int max_idx = get_max(trust_count, nodes);//제일 많이 신뢰받는 index찾음

	for (auto i = v.at(max_idx).begin(); i < v.at(max_idx).end(); i++)//해당 id가 신뢰하는 id출력
		std::cout << *i << " ";

	return 0;
}

int get_max(int* arr,int len)
{
	int res = 0;
	for (int i = 0; i < len; i++)
	{
		if (arr[i] > arr[res])
		{
			res = i;
		}
	}

	return res;
}