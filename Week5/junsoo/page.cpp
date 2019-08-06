#include<iostream>

int main()
{
	int* arr = (int*)calloc(10, sizeof(int));
	int page;
	std::cin >> page;
	if (page == 0)
	{
		for (int i = 0; i < 10; i++)
			std::cout << arr[i] << " ";
	}
	else
	{
		arr[1]++;
	}
	return 0;
}