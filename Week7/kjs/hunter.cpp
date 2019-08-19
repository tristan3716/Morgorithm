#include<iostream>
#include<algorithm>
#include<vector>

int main()
{
	int test;
	std::cin >> test;
	std::vector<std::pair<int, int>> Case(test);
	
	int idx = 0;
	while (idx < test)
	{
		int a, b;
		std::cin >> a >> b;
		Case[idx] = { a,b };
		idx++;
	}

	std::vector<int> result(test);

	idx = 0;
	while (idx < test)
	{
		unsigned int res_a=0, res_b=0;
		if (Case[idx].first != 0)
		{
			if (Case[idx].first == 1)
			{
				res_a = 5000000;
			}
			else if (Case[idx].first <= 3)
			{
				res_a = 3000000;
			}
			else if (Case[idx].first <= 6)
			{
				res_a = 2000000;
			}
			else if (Case[idx].first <= 10)
			{
				res_a = 500000;
			}
			else if (Case[idx].first <= 15)
			{
				res_a = 300000;
			}
			else if (Case[idx].first <= 21)
			{
				res_a = 100000;
			}
		}
		if (Case[idx].second != 0)
		{
			if (Case[idx].second == 1)
			{
				res_b = 5120000;
			}
			else if (Case[idx].second <= 3)
			{
				res_b = 2560000;
			}
			else if (Case[idx].second <= 7)
			{
				res_b = 1280000;
			}
			else if (Case[idx].second <= 15)
			{
				res_b = 640000;
			}
			else if (Case[idx].second <= 31)
			{
				res_b = 320000;
			}
		}
		result[idx] = res_a + res_b;
		idx++;
	}

	for (auto i = result.begin(); i < result.end(); i++)
		std::cout << *i << "\n";

	return 0;
}