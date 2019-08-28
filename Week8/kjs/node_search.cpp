#include<iostream>
#include<vector>
#include<algorithm>

typedef struct NodeType
{
	int idx;
	int x;
	int y;
}Node;//인덱스 저장위한 노드

bool cmp1(const Node n1, const Node n2)
{
	return (n1.y < n2.y);//전위연산 위해 y좌표비교
}

std::vector<std::vector<int>> solution(std::vector<std::vector<int>> nodeinfo)
{
	std::vector<std::vector<int>> answer;
	std::vector<Node> preorder(nodeinfo.size());
	std::vector<Node> not_pre(nodeinfo.size());

	//입력
	for (int i = 0; i < nodeinfo.size(); i++)
	{
		preorder[i].idx = i+1;
		preorder[i].x = nodeinfo[i][0];
		preorder[i].y = nodeinfo[i][1];

		not_pre[i].idx = i + 1;
		not_pre[i].x = nodeinfo[i][0];
		not_pre[i].y = nodeinfo[i][1];
	}
	
	std::sort(preorder.begin(), preorder.end(), cmp1);//정렬

	/*
	정렬 이후 전위연산탐색에서 막혔음...
	y가 큰값 순서로 탐색하는건 좋지만 후위노드로의 진행이 문제...
	*/
}

int main()
{
	std::vector<std::vector<int>> nodeinfo(9);
	for (int i = 0; i < 9; i++)
	{
		int x, y;
		std::cin >> x >> y;
		nodeinfo[i].push_back(x);
		nodeinfo[i].push_back(y);
	}

	std::vector<std::vector<int>> answer = solution(nodeinfo);

	for (auto i = answer.begin(); i < answer.end(); i++)
	{
		for (auto j = (*i).begin(); j < (*i).end(); j++)
		{
			std::cout << *j << " ";
		}
		std::cout << "\n";
	}

	return 0;
}