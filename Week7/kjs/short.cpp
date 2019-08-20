#include<iostream>
#include<vector>
#include<string>

int main()
{
	char* str=(char*)malloc(sizeof(char)*(pow(10.0,6.0)));
	std::cin >> str;
	std::vector<std::string> input;

	char* tmp = strtok(str, "&&");
	while (tmp != NULL)
	{
		input.push_back(tmp);
		tmp = strtok(NULL, "&&");
	}

	std::cout << strncmp(input[0].c_str(), input[1].c_str(), input[0].find("==") - 1);

	return 0;
}