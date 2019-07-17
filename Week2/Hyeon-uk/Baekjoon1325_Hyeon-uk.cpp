/* ================================================================================================
 * Baekjoon Online Judge
 *		1325 - 효율적인 해킹
 *
 * time limit per test : 5 seconds
 * memory limit per test : 256 megabytes
 * standard input/standard output
 *
 * 해커 김지민은 잘 알려진 어느 회사를 해킹하려고 한다. 이 회사는 N개의 컴퓨터로 이루어져 있다. 
 * 김지민은 귀찮기 때문에, 한 번의 해킹으로 여러 개의 컴퓨터를 해킹 할 수 있는 컴퓨터를 해킹하려고 한다.
 * 
 * 이 회사의 컴퓨터는 신뢰하는 관계와, 신뢰하지 않는 관계로 이루어져 있는데, 
 * A가 B를 신뢰하는 경우에는 B를 해킹하면, A도 해킹할 수 있다는 소리다.
 * 
 * 이 회사의 컴퓨터의 신뢰하는 관계가 주어졌을 때, 
 * 한 번에 가장 많은 컴퓨터를 해킹할 수 있는 컴퓨터의 번호를 출력하는 프로그램을 작성하시오.
 * 2019.07.10 11:08 ~ 07.11 12:12
 *
 * ------------------------------------------------------------------------------------------------
 * 
 * 서고리즘으로 풀어봐서 금방 푼 문제
 * 인접리스트로 방문가능한 모든 노드 -> 한 번에 해킹할 수 있는 컴퓨터
 * 모든 컴퓨터에서 출발하는 해킹을 수행해보고
 * 그 중 가장 높은 값!
 *
 * ------------------------------------------------------------------------------------------------ */

#include <iostream>
#include <vector>
#include <algorithm>

int hack(std::vector<std::vector<int>> &adj, std::vector<bool> &visit, int id) {
	int sum = 0;
	visit[id] = true;
	for (unsigned int i = 1; i < adj[id].size(); i++) {
		if (visit[adj[id][i]] == false)
			sum += hack(adj, visit, adj[id][i]);
	}
	return 1 + sum;
}

int main() {
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> adj(n + 1, std::vector<int>(1, 0));
	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		adj[b].push_back(a);
	}
	int max = -1;
	std::vector<int> id;
	for (int cur_id = 1; cur_id <= n; cur_id++) { // O(n)
		std::vector<bool> visit(n + 1, false);
		int temp = hack(adj, visit, cur_id);
		if (max < temp) {
			id.clear();
			id.push_back(cur_id);
			max = temp;
		}
		else if (max == temp) {
			id.push_back(cur_id);
		}
	}

	for (unsigned int i = 0; i < id.size(); i++) {
		std::cout << id[i] << " ";
	}

	return 0;
}