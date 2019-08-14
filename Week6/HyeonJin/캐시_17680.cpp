#include <string>
#include <vector>
#include <iostream>


using namespace std;

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	vector<string> v;
	for (int i = 0; i < cities.size(); i++)
	{
		for (int j = 0; j < cities[i].size(); j++)
			cities[i][j] = toupper(cities[i][j]);
	}

	int check_num[30] = { 0, };
	bool check = false;

	if (cacheSize == 0)
		answer = cities.size() * 5;
	else
	{
		v.push_back(cities[0]);
		answer += 5;
		check_num[0] = 1;
		for (int i = 1; i < cities.size(); i++)
		{
			check = false;
			for (int j = 0; j < v.size(); j++)
			{
				if (cities[i] == v.at(j))
				{
					for (int k = 0; k < cacheSize; k++)
					{
						if (check_num[k] != 0)
							check_num[k]++;
					}
					check_num[j] = 1;
					answer += 1;
					check = true;
					break;
				}
			}
			if (check == false)
			{
				if (v.size() < cacheSize)
				{
					for (int j = 0; j < v.size(); j++)
					{
						if (check_num[j] != 0)
							check_num[j]++;
					}
					v.push_back(cities[i]);
					check_num[i] = 1;
					answer += 5;
				}
				else
				{
					int max = 0;
					int max_index = 0;
					for (int j = 0; j < cacheSize; j++)
					{
						if (max < check_num[j])
							if (check_num[j] != 0) {
								max = check_num[j];
								max_index = j;
							}
					}
					v[max_index] = cities[i];
				/*	v.erase(deq.begin() + max_index );
					v.insert(deq.begin() + max_index, cities[i]);*/
					for (int j = 0; j < cacheSize; j++)
					{
						if (check_num[j] != 0)
							check_num[j]++;
					}
					check_num[max_index] = 1;
					answer += 5;
				}
			}
		}
	}
	return answer;
}
int main()
{
	int cacheSize;
	string str;
	vector<string> cities;
	cin >> cacheSize;
	for (int i = 0; i < 10; i++)
	{
		cin >> str;
		cities.push_back(str);
	}
	int answer = solution(cacheSize, cities);
	cout << answer;
	return 0;
}