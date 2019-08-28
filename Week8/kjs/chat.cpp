#include<iostream>
#include<vector>
#include<string>

std::vector<std::string> solution(std::vector<std::string> record)
{
	std::vector<std::string> answer;
	std::vector<std::string> Stack;
	//¹®ÀÚ¿­ ÆÄ½Ì Á¸³ª ½ÈÀ½..
}

int main()
{
	std::vector<std::string> record = { "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" };
	std::vector<std::string> answer = solution(record);

	for (auto i = answer.begin(); i < answer.end(); i++)
		std::cout << *i << "\n";

	return 0;
}