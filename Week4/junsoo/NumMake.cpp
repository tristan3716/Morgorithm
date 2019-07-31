#include<iostream>
#include<vector>
#include<numeric>
#include<string>
#include<algorithm>


bool desc(int a, int b)
{
	return a > b;
}

int main()
{
	std::string N;

	std::cin >> N;

	long long sum = 0;//¡÷¿«
	bool zero = false;

	for (int i = 0; i < N.size(); i++)
	{
		sum += (N[i] - '0');
		if (!(N[i] - '0'))
		{
			zero = true;
		}
	}

	if (sum % 3 || !zero)
		std::cout << -1 << "\n";

	else

	{

		std::sort(N.begin(), N.end(), desc);

		std::cout << N << "\n";

	}
	return 0;
}