/* ================================================================================================
 * Programmers
 *		42898 - 등굣길
 *
 * time limit per test : ?? seconds
 * memory limit per test : ?? megabytes
 * solution function's arguments/return value
 *
 * 집에서 학교까지 가는 길은 m x n 크기의 격자모양으로 나타낼 수 있습니다.
 * 가장 왼쪽 위, 즉 집이 있는 곳의 좌표는 (1, 1)로 나타내고
 * 가장 오른쪽 아래, 즉 학교가 있는 곳의 좌표는 (m, n)으로 나타냅니다.
 * 격자의 크기 m, n과 물이 잠긴 지역의 좌표를 담은 2차원 배열 puddles이 매개변수로 주어질 때,
 * 학교에서 집까지 갈 수 있는 최단경로의 개수를
 * 1,000,000,007로 나눈 나머지를 return 하도록 solution 함수를 작성해주세요.
 *
 * ------------------------------------------------------------------------------------------------
 * 
 * 1 <= M, N <= 100 -> O((NM)^2) is possible
 * m x n 격자에서 이동할 수 있는 경우의 수 : (m+n)!/m!n!
 * P를 거치지 않고 갈 수 있는 경우의 수?
 * P의 주위 4칸을 거쳐야함 -> P의 위와 오른쪽, P의 왼쪽과 아래
 *
 * Using DP
 * puddle이 없을 때, map[0][0]부터 map[i][j]까지 도달할 수 있는 경로의 수
 *     -> map[i-1][j], map[i][j-1] 까지 도달할 수 있는 경로의 수
 * map[i][j]까지 도달할 수 있는 경로의 수에 메모이제이션 적용
 *     -> map[i][j] = map[i][j-1] + map[i-1][j];
 *
 * puddle에 의해 막힌 곳을 경유하는 경로 = 0 으로 설정하면 (puddle에 도달하는 경로의 개수가 0)
 * puddle을 경유하는 경로가 삭제됨
 *
 * ------------------------------------------------------------------------------------------------ */

#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
	vector<vector<int>> map(m + 1, vector<int>(n + 1, 0));
	for (unsigned int i = 0; i < puddles.size(); i++) {
		map[puddles[i][0]][puddles[i][1]] = -1;
	}
	map[0][1] = 1;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			if (map[i][j] != -1)
				map[i][j] = (map[i - 1][j] + map[i][j - 1]) % 1000000007;
			else
				map[i][j] = 0;
		}
	}
	return map[m][n];
}

#include <iostream>
#include <thread>
#include <tuple>
#include <future>
#include <chrono>

void get_solution(int m, int n, vector<vector<int>> puddles, std::promise<std::tuple<int, std::chrono::duration<double>>>* p)
{
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	int result = solution(m, n, puddles);
	std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
	std::chrono::duration<double> time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	
	p->set_value({ result, time });
}

int main()
{
	/* 테스트케이스를 삽입하는 부분 */
	std::vector<std::tuple<int, int, std::vector<std::vector<int>>, int>> testcase;

	testcase.push_back({ 4, 3, { {2, 2} }, 4 });
	testcase.push_back({ 6, 5, {  }, 30 });
	testcase.push_back({ 1, 1, {  }, 1 });

	for (unsigned int i = 0; i < testcase.size(); i++) {
		std::cout << "> Test No." << i + 1 << std::endl;

		int tc_m;
		int tc_n;
		std::vector<std::vector<int>> tc_puddles;
		int tc_ans;
		std::tie(tc_m, tc_n, tc_puddles, tc_ans) = testcase[i];


		std::promise<std::tuple<int, std::chrono::duration<double>>> p;
		auto f = p.get_future();

		std::thread thr(get_solution, tc_m, tc_n, tc_puddles, &p);
		std::future_status status = f.wait_for(std::chrono::milliseconds(2100));

		if (status == std::future_status::timeout) {
			thr.detach();

			std::cout << "> Time Limit Exceed" << std::endl;
		}
		else if (status == std::future_status::ready) {
			thr.join();

			int answer = tc_ans;
			std::chrono::duration<double> ex_time;
			int result;
			std::tie(result, ex_time) = f.get();

			if (result != answer) {
				std::cout << "  Check   : Wrong Answer" << std::endl;
			}
			else {
				std::cout << "  Check   : Right Answer" << std::endl;
			}

			std::cout << "  Ex_time : " << fixed << ex_time.count() << " seconds" << std::endl;

			std::cout << "  Input   : " << tc_m << ", " << tc_n << ", ";
			std::cout << "[";
			for (unsigned int i = 0; i < tc_puddles.size(); i++) {
				std::cout << "[" << tc_puddles[i][0] << ", " << tc_puddles[i][1] << "]";
				if (i != tc_puddles.size() - 1)
					std::cout << ", ";
			}
			std::cout << "]" << std::endl;

			std::cout << "  Output  : " << result << std::endl;
			std::cout << "  Answer  : " << answer << std::endl;
		}

		std::cout << std::endl;
	}

	return 0;
}
