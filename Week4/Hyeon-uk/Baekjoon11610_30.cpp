/* ================================================================================================
 * Baekjoon Online Judge
 *		11610 - 30
 *
 * 어느 날, 미르코는 우연히 길거리에서 양수 N을 보았다.
 * 미르코는 30이란 수를 존경하기 때문에, 
 * 그는 길거리에서 찾은 수에 포함된 숫자들을 섞어 30의 배수가 되는 가장 큰 수를 만들고 싶어한다.
 * 미르코를 도와 그가 만들고 싶어하는 수를 계산하는 프로그램을 작성하라.
 * ------------------------------------------------------------------------------------------------
 * 재배열해서, 30의 배수 만들기
 * N에 반드시 0이 포함되어 있어야함
 * 모든 N_i의 합이 3의 배수
 * ?
 * 끝
 * 아 길이가 10만이네... 컨테이너로 고고
 * ------------------------------------------------------------------------------------------------ */

#include <iostream>
#include <string>
#include <algorithm>

int main() {
	using namespace std;
	string s;
	string s2;
	int t;
	int sum = 0;
	int hasZero = 0;
	std::cin >> s;
	s2 = s;
	while (!s.empty()) {
		t = static_cast<int>(s.back()) - '0';
		if (!t)
			hasZero = 1;
		sum += t;
		s.pop_back();
	}
	if (hasZero == 1) {
		if (sum % 3 == 0) {
			std::sort(s2.begin(), s2.end(), std::greater<int>());
			for (auto i : s2) {
				std::cout << i;
			}
			return 0;
		}
	}
	std::cout << -1;
	return 0;
}