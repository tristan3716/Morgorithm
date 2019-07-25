#include<iostream>
#include<string>

int main()
{
	std::string input;
	std::cin >> input;

	int major = 0, minor = 0;
	char* str = new char[input.length() + 1];
	strcpy(str, input.c_str());

	str = strtok(str, "|");

	while (str != NULL)
	{
		if (str[0] == 'C' || str[0] == 'G'||str[0]=='F')
		{
			major++;
		}
		else
		{
			minor++;
		}
		str = strtok(NULL, "|");
	}
	if (major > minor)
		std::cout << "C-major";
	else if (major == minor)
	{
		if (input[input.size()-1] == 'C' || input[input.size() - 1] == 'G' || input[input.size() - 1] == 'F')
			std::cout << "C-major";
		else
			std::cout << "A-minor";
	}
	else
		std::cout << "A-minor";

	return 0;
}