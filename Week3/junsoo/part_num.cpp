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
	for (auto i = v.begin(); i < v.end(); i++)
	{
		if (part.size() == 0)//부분수열0일때
		{
			part.push_back(*i);
		}
		else//그외
		{
			if (*i > part[part.size()-1])//부분수열 끝과 비교, 크면 삽입
			{
				part.push_back(*i);
			}
		}
	}

	std::cout << part.size();//사이즈 출력

	return 0;
}