#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	int n, m;

	std::cin >> n >> m;
	std::vector<std::vector<int>> v(n + 1, std::vector<int>(m + 1, 0));//c에선 불가능한 방법->연산 런타임 에러 원인 

	int c;
	int max = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &c);

			if (c) {
				v[i][j] = 1 + std::min({ v[i - 1][j - 1], v[i][j - 1], v[i - 1][j] });
				max = std::max(max, v[i][j]);
			}
		}
	}

	std::cout << max * max;

	return 0;
}
