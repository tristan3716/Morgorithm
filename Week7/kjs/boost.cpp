#include<iostream>
#include<vector>
#include<string>

int main()
{
	int check, quest;
	std::cin >> check >> quest;

	std::vector<std::pair<int, int>> checks(check);
	int idx = 0;
	while (idx < check)
	{
		std::cin >> checks[idx].first >> checks[idx].second;
		idx++;
	}

	idx = 0;
	std::vector<std::string> answer(quest);
	while (idx < quest)
	{
		int pt1, pt2,hp;
		std::cin >> pt1 >> pt2 >> hp;

		if ((checks[pt1 - 1].first == checks[pt2 - 1].first) || (checks[pt1 - 1].second == checks[pt2 - 1].second))
		{
			answer[idx] = "YES";
		}
		else
		{
			if (hp == 0)
			{
				for (int i = 0; i < check; i++)
				{
					if ((checks[pt1 - 1].first == checks[i].first))
					{
						if ((checks[pt2 - 1].second == checks[i].second))
						{
							answer[idx] = "YES";
							break;
						}
						else
						{
							answer[idx] = "NO";
						}
					}
					else if ((checks[pt1 - 1].second == checks[i].second))
					{
						if ((checks[pt2 - 1].first == checks[i].first))
						{
							answer[idx] = "YES";
							break;
						}
						else
						{
							answer[idx] = "NO";
						}
					}
				}
			}
			else
			{
				if ((std::abs(checks[pt1 - 1].first - checks[pt2 - 1].first) <= hp) ||
					(std::abs(checks[pt1 - 1].second - checks[pt2 - 1].second) <= hp))
				{
					answer[idx] = "YES";
				}
				else
				{
					answer[idx] = "NO";
				}
			}
		}
		idx++;
	}


	for (auto i = answer.begin(); i < answer.end(); i++)
		std::cout << *i << "\n";

	return 0;
}