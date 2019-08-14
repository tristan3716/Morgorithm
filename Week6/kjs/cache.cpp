#include<iostream>
#include<vector>
#include<string>
#include<map>

typedef struct CacheNode
{
	std::string city;
	int cnt = 10;
}Node;

int solution(int size, std::vector<std::string> cities)
{
	int answer = 0;
	std::vector<Node> cache(size);
	int idx = 0;
	while (idx < cities.size())
	{
		if (idx < size)
		{
			cache[idx].city = cities[idx];
			answer = answer + 5;
			idx++;
		}
		else
		{
			int check = -1;
			for (int i = 0; i < size; i++)
			{
				if (strcmp(cache[i].city.c_str(), cities[idx].c_str()) == 0)
				{
					check = 1;
					answer++;
					cache[i].cnt = 10;
					idx++;
					break;
				}
				else
				{
					cache[i].cnt--;
				}
			}
			if (check == -1)
			{
				answer = answer + 5;
				int min = 0;
				for (int i = 0; i < cache.size(); i++)
				{
					if (cache[min].cnt > cache[i].cnt)
					{
						min = i;
					}
				}
				cache[min].city = cities[idx];
				cache[min].cnt = 10;
				idx++;
			}
		}
	}

	return answer;
}

int main()
{
	std::vector<std::string> cities;
	cities.push_back("Jeju");
	cities.push_back("Pangyo");
	cities.push_back("Seoul");
	cities.push_back("NewYork");
	cities.push_back("LA");
	cities.push_back("Jeju");
	cities.push_back("Pangyo");
	cities.push_back("Seoul");
	cities.push_back("NewYork");
	cities.push_back("LA");

	int answer = solution(3, cities);
	std::cout << answer;
	return 0;
}