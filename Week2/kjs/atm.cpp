#include<iostream>
#include<vector>
#include<algorithm>

int get_sum(std::vector<int> v, int len);

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> v(n);

	for (auto i = v.begin(); i < v.end(); i++)
		std::cin >> *i;

	sort(v.begin(), v.end());
	int *arr = (int*)calloc(v.size(), sizeof(int));
	int res = 0;

	for (int i=0;i<v.size();i++)
	{
		if (i == 0)
		{
			arr[i] = v[i];
		}
		else
		{
			arr[i] = get_sum(v, i);
		}
	}
	for (int i = 0; i < n; i++)
		res = res + arr[i];

	std::cout << res;

	return 0;
}

int get_sum(std::vector<int> v, int len)
{
	int count = 0;
	int res = 0;
	for (; count < len+1; count++)
	{
		res = res + v[count];
	}

	return res;
}