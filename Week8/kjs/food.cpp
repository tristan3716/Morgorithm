#include<iostream>
#include<vector>

int solution(std::vector<int> food_times, long long k)
{
	int answer = 0;

	//에러 전까지 음식 진행
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
	//에러 났을때 제일 먼저 먹는것 찾음
		for (int i = 0; i < food_times.size(); i++)
		{
			if (food_times[i] != 0)
			{
				answer = i + 1;//찾고
				break;//반복문 종료
			}
			else
			{
				continue;
			}
		}
		if (answer == 0)
			answer = -1;//없을경우

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