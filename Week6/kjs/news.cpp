#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>

int solution(std::string str1, std::string str2)
{
	int answer = 0;
	std::set<std::string> arr1;
	std::set<std::string> arr2;

	for (int i = 0; i < str1.size() - 1; i++)
	{
		std::string str;
		str.push_back(str1[i]);
		str.push_back(str1[i + 1]);
		arr1.insert(str);
	}
	for (int i = 0; i < str2.size() - 1; i++)
	{
		std::string str;
		str.push_back(str2[i]);
		str.push_back(str2[i + 1]);
		arr2.insert(str);
	}


}

int main()
{

}