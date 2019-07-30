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
	std::vector<std::vector<int>> map(n, std::vector<int>(m));

	for (auto j = puddles.begin(); j < puddles.end(); j++)
	{
		for (int z=0;z<(*j).size()/2; z=z+2)
		{
			map[(*j).at(z) - 1][(*j).at(z + 1) - 1]=1;
		}
	}

	int check = 0;
	int i = 0;
	int j = 0;

	do
	{
		
	} while (check == 0);
	return answer;
}