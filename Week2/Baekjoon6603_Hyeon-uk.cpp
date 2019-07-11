/* ================================================================================================
 * Baekjoon Online Judge
 *		6603 - 로또
 *
 * time limit per test : 1 seconds
 * memory limit per test : 128 megabytes
 * standard input/standard output
 *
 * 독일 로또는 {1, 2, ..., 49}에서 수 6개를 고른다.
 * 로또 번호를 선택하는데 사용되는 가장 유명한 전략은 
 * 49가지 수 중 k(k>6)개의 수를 골라 집합 S를 만든 다음 그 수만 가지고 번호를 선택하는 것이다.
 * 예를 들어, k=8, S={1,2,3,5,8,13,21,34}인 경우 이 집합 S에서 수를 고를 수 있는 경우의 수는 총 28가지이다. 
 * ([1,2,3,5,8,13], [1,2,3,5,8,21], [1,2,3,5,8,34], [1,2,3,5,13,21], ..., [3,5,8,13,21,34])
 * 
 * 집합 S와 k가 주어졌을 때, 수를 고르는 모든 방법을 구하는 프로그램을 작성하시오.
 * 2019.07.11 00:17 ~ 00:22, 04:10 ~ 04:30
 * ------------------------------------------------------------------------------------------------ */

#include <iostream>
#include <vector>

void makeSet(std::vector<int> set, std::vector<bool> visit, int k, std::vector<int> res, int q) {
	//std::cout << "i : " << q << std::endl;
	if (k == 0) {
		for (int i = 0; i < 6; i++) {
			std::cout << res[i] << " ";
		}
		std::cout << std::endl;
	}
	else {
		for (int i = q; i < set.size(); i++) {
			if (visit[i] == true)
				continue;
			std::vector<int> res_copy = res;
			//std::cout << "add " << set[i] << std::endl;
			res_copy.push_back(set[i]);
			visit[i] = true;
			makeSet(set, visit, k - 1, res_copy, i+1);
		}
	}
	
}

int main() {
	int k;
	while (true) {
		std::vector<int> set;
		std::vector<int> res;
		std::cin >> k;
		if (k == 0)
			break;
		else {
			for (int i = 0; i < k; i++) {
				int t;
				std::cin >> t;
				set.push_back(t);
			}
		}
		std::vector<bool> visit(k, false);
		makeSet(set, visit, 6, res, 0);

		std::cout << std::endl;
	}

	return 0;
}
/*

7 1 2 3 4 5 6 7
0

*/