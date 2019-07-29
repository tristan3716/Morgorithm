#include<iostream>
#include<vector>
#include<string>

int main()
{
	int len;
	std::cin >> len;
	char* str = (char*)malloc(sizeof(char) * (len * len));
	std::vector<int> v;
	int result = 0;
	std::cin.ignore();
	std::cin.getline(str, len * len);

	char* input = strtok(str, " ");
	while(input!=NULL)
	{
		v.push_back(atoi(input));
		input = strtok(NULL, " ");
	}
	int idx = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[idx] < v[i])
		{
			idx = i;
		}
	}
	if (v[idx - 1] > 0)
	{
		result = v[idx] + v[idx - 1];
	}
	else if (v[idx + 1] > 0)
	{
		result = v[idx] + v[idx + 1];
	}
	else
	{
		result = v[idx];
	}
	std::cout << result;
	return 0;
}