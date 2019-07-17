#include<iostream>
#include<vector>
#include<string>

std::vector<int> solution(std::vector<std::string> genres, std::vector<int> plays);

int main()
{
	std::vector<std::string> genres;
	std::string str;
	std::vector<int> plays;
	std::cout << "genre: " << " ";
	do
	{
		std::cin >> str;
		if (str != "\n"&&str!=" ")
		{
			genres.push_back(str);
		}
	} while (str != "\n");
	std::cout << "plays: " << " ";
	do
	{
		std::cin >> str;
		if (str != "\n")
		{
			plays.push_back(atoi(str.c_str()));
		}
	} while (str != "\n");

	std::vector<int> answer = solution(genres, plays);

	for (auto i = answer.begin(); i < answer.end(); i++)
		std::cout << *i << ",";

	return 0;
}

std::vector<int> solution(std::vector<std::string> genres, std::vector<int> plays)
{
	std::vector<int> answer;
	std::vector<int> play_cpy(plays);

	int max = 0;
	
	while (play_cpy.size() > 0)
	{
		for (int j = 0; j < play_cpy.size(); j++)
		{
			if (play_cpy[max] < play_cpy[j])
			{
				max = j;
			}
		}
		answer.push_back(max);
		play_cpy.erase(play_cpy.begin() + max);
		max = 0;
	}

		for (int i = 0; i < answer.size(); i++)
		{
			int count = 0;
			for (int j = i+1; j < answer.size(); j++)
			{
				if (genres.at(answer.at(i)) == genres.at(answer.at(j)))
				{
					if (count < 1)
					{
						count++;
					}
					else
					{
						if (plays.at(answer.at(i)) > plays.at(answer.at(j)))
						{
							answer.erase(std::find(answer.begin(), answer.end(), j));
						}
						else
						{
							answer.erase(std::find(answer.begin(), answer.end(), i));
						}
					}
				}
			}
		}

		return answer;
}