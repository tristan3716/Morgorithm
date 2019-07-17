/* ================================================================================================
 * Baekjoon Online Judge
 *		1915 - 가장 큰 정사각형
 *
 * time limit per test : 2 seconds
 * memory limit per test : 128 megabytes
 * standard input/standard output
 *
 * n×m의 0, 1로 된 배열이 있다. 이 배열에서 1로 된 가장 큰 정사각형의 크기를 구하는 프로그램을 작성하시오.
 * 
 *		0	1	0	0
 *		0	1	1	1
 *		1	1	1	0
 *		0	0	1	0
 * 위와 같은 예제에서는 가운데의 2×2 배열이 가장 큰 정사각형이다.
 * ------------------------------------------------------------------------------------------------ */

#include <vector>
#include <iostream>
#include <algorithm>

int main()
{
	int n, m;

	std::cin >> n >> m;
	std::vector<std::vector<int>> v(n + 1, std::vector<int>(m + 1, 0));

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