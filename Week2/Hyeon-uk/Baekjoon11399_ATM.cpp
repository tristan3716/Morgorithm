/* ================================================================================================
 * Baekjoon Online Judge
 *		11399 - ATM
 *
 * time limit per test : 1 seconds
 * memory limit per test : 256 megabytes
 * standard input/standard output
 *
 * 줄을 서 있는 사람의 수 N과 각 사람이 돈을 인출하는데 걸리는 시간 Pi가 주어졌을 때, 
 * 각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값을 구하는 프로그램을 작성하시오.
 * 
 * ------------------------------------------------------------------------------------------------
 * 
 * 모든 사람의 대기 시간의 합이 최소가 되기위한 조건? 작업 소요시간이 가장 짧은 사람을 가장 먼저 처리한다
 * 작업 소요 시간 P를 정렬
 * 
 * 작업시간의 합을 계산
 *
 * ------------------------------------------------------------------------------------------------ */

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;

	int sum = 0;
	std::vector<int> p;
	p.reserve(n);

	for (int i = 0; i < n; i++) {
		int temp;
		std::cin >> temp;

		p.push_back(temp);
	}

	std::sort(p.begin(), p.end());

	sum += p[0];
	for (int i = 1; i < n; i++) {
		p[i] = p[i] + p[i - 1];
		sum += p[i];
	}

	std::cout << sum;

	return 0;
}