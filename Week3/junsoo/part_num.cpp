#pragma warning(disable:4996)

#include<iostream>
#include<vector>
#include<string>

int main()
{
	int len;
	std::cin >> len;
	std::vector<int> v;
	std::vector<int> part;

	char* str = (char*)malloc(sizeof(char) * (len * len));
	std::cin.ignore();
	std::cin.getline(str, len*len);//입력받음
	
	str = strtok(str, " ");//공백기준으로 잘라서
	while (str != NULL)
	{
		v.push_back(atoi(str));//숫자 입력
		str = strtok(NULL, " ");
	}
	int idx = 0;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[idx] > v[i])
		{
			idx = i;
		}
	}
	if (idx < v.size() / 2)
	{
		part.push_back(v[idx]);
		for (int i = idx; i < v.size(); i++)
		{
			if (v[i] > part[part.size() - 1])//부분수열 끝과 비교, 크면 삽입
			{
				part.push_back(v[i]);
			}
		}
	}
	else
	{
		part.push_back(v[0]); 
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i] > part[part.size() - 1])//부분수열 끝과 비교, 크면 삽입
			{
				part.push_back(v[i]);
			}
		}
	}

	std::cout << part.size();//사이즈 출력

	return 0;
}