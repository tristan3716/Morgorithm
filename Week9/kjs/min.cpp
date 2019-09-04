#include<iostream>
#include<vector>

int main()
{
	int len, L;

	std::cin >> len >> L;

	std::vector<int> input(len);
	std::vector<int> answer(len);
	for (int i = 0; i < len; i++)
	{
		int val;
		std::cin >> val;
		input[i] = val;
	}

	int cnt = 0;
	for (int i = 0; i < len; i++)
	{
		if (cnt < L)
		{
			int idx = 0;
			for (int j = 0; j < L; j++)
			{
				if (input[idx] > input[j])
				{
					idx = j;
				}
			}
			answer[i] = input[idx];
			cnt++;
		}
		else
		{
			int idx = i-L+1;
			for (int j = i-L+1; j < i+1; j++)
			{
				if (input[idx] >= input[j])
				{
					idx = j;
				}
			}
			answer[i] = input[idx];
		}
	}

	for (int i = 0; i < len; i++)
		std::cout << answer[i] << " ";

	return 0;
}