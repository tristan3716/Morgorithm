#include<iostream>
#include<vector>

int solution(std::vector<int> food_times, long long k)
{
	int answer = 0;

	while (k > 0)
	{
		for (int i = 0; i < food_times.size(); i++)
		{
			if (k == 0)
			{
				break;
			}

			if (food_times[i] > 0)
			{
				food_times[i]--;
				k--;
			}
			else
			{
				continue;
			}

		}
	}

		for (int i = 0; i < food_times.size(); i++)
		{
			if (food_times[i] != 0)
			{
				answer = i + 1;
				break;
			}
			else
			{
				continue;
			}
		}
		if (answer == 0)
			answer = -1;

		return answer;
}

int main()
{
	std::vector <int> food_times = { 3,1,2 };
	long long k = 5;

	int answer = solution(food_times, k);

	std::cout << answer;

	return 0;
}