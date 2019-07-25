#include<iostream>
#include<vector>
#include<numeric>
#include<string>
#include<algorithm>


bool desc(int a, int b)
{
	return a > b;
}

int main()
{
	std::vector<int> v;
	char* str=(char*)calloc(6,sizeof(char));
	scanf("%s", str);
	int i = 0;
	while (str[i] != '\0')
	{
		v.push_back(int(str[i]) - '0');
		i++;
	}

	if (std::find(v.begin(), v.end(), 0) == v.end())
	{
		std::cout << -1;
		return 0;
	}
	else
	{
		if (std::accumulate(v.begin(), v.end(), 0) % 3 == 0)
		{
			std::sort(v.begin(), v.end(), desc);
			for (auto i = v.begin(); i < v.end(); i++)
				std::cout << *i;
		}
		else
		{
			std::cout << -1;
		}
	}
	return 0;
}