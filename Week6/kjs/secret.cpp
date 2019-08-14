#include<iostream>
#include<vector>
#include<string>
#include<cmath>

std::vector<std::string> solution(int n, std::vector<int> arr1, std::vector<int> arr2)
{
	std::vector<std::string> answer;
	int idx = 0;
	while (idx < n)
	{
		int num = arr1[idx] | arr2[idx];
		std::string str(n,' ');
		int i = n - 1;
		while (num >= 1)
		{
			if (num % 2 == 1)
			{
				str[i] = '#';
			}
			else
			{
				str[i] = ' ';
			}
			num = std::round(num / 2);
			i--;
		}
		answer.push_back(str);
		idx++;
	}

	return answer;
}

int main()
{
	std::vector<int> arr1;
	std::vector<int> arr2;
	std::vector<std::string> answer;

	arr1.push_back(9);
	arr1.push_back(20);
	arr1.push_back(28);
	arr1.push_back(18);
	arr1.push_back(11);

	arr2.push_back(30);
	arr2.push_back(1);
	arr2.push_back(21);
	arr2.push_back(17);
	arr2.push_back(28);

	answer = solution(5, arr1, arr2);

	for (auto i = answer.begin(); i < answer.end(); i++)
		std::cout << *i << "\n";

	return 0;
}