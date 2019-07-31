#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>

int main()
{
	int n;
	std::cin >> n;
	std::vector<int> v(n, 0);
	std::vector<int> d(n, 0);
	int res = -1000;

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &v[i]);
	}

	d[0] = v[0];
	for (int i = 1; i < n; i++) {
		d[i] = std::max(d[i - 1] + v[i], v[i]);
		res = std::max(res, d[i]);
	}
	res = std::max(res, d[0]);

	std::cout << res;
	return 0;
}