/* ================================================================================================
 * Programmers
 *		42860 - 조이스틱
 *
 * time limit per test : ?? seconds
 * memory limit per test : ?? megabytes
 * solution function's arguments/return value
 *
 * 조이스틱으로 알파벳 이름을 완성하세요. 맨 처음엔 A로만 이루어져 있습니다.
 * 
 * 조이스틱을 각 방향으로 움직이면 아래와 같습니다.
 * ▲ - 다음 알파벳
 * ▼ - 이전 알파벳 (A에서 아래쪽으로 이동하면 Z로)
 * ◀ - 커서를 왼쪽으로 이동 (첫 번째 위치에서 왼쪽으로 이동하면 마지막 문자에 커서)
 * ▶ - 커서를 오른쪽으로 이동
 * 만들고자 하는 이름 name이 매개변수로 주어질 때, 
 * 이름에 대해 조이스틱 조작 횟수의 최솟값을 return 하도록 solution 함수를 만드세요.
 *
 * ------------------------------------------------------------------------------------------------
 * 
 * 알파벳을 맞출 때 위쪽 이동 횟수와 아래쪽 이동 횟수 중 더 작은 쪽을 택해서 이동
 * 같은 방법으로 자리도 왼쪽과 오른쪽 중 더 짧은 방향으로 이동하면 되지 않을까?
 *
 * 구현 방법
 *	A가 아닌 글자의 수 세기 : count
 *	for()
 *		현재 자리의 알파벳 설정 (A~Z) : count--
 *		if (모든 자리의 알파벳 설정이 끝났는지) : count == 0
 *		다음에 설정할 위치 탐색 (왼쪽과 오른쪽 중 짧은 곳)
 *		이동
 *
 * 테스트케이스는 모두 통과하였으나...
 * 만약 "FFFFFAAAAAAABA"라면?
 * 당장 최선의 위치로 이동하는 것이 최종적으론 최선의 선택이 아닐 수도 있다
 * 
 * ...?
 * 그리디인거 보고 고른건데...
 * 
 * 당장 생각난 해결 방법은 재귀로 모든 케이스에 대해 탐색하는 것.
 * 왼쪽으로 이동했을 때 이동횟수와 오른쪽으로 이동했을 때 이동횟수의 합 중 더 작은 쪽을 선택
 * 재귀 내부에서 방문한 자리에 대해 알파벳 설정 후 방문 표시하여 재방문을 방지
 * 그리디가 적용되는 부분은 알파벳 설정
 *
 * 근데, 실제로 이동할 필요가 있나?
 * 총 이동횟수 = 알파벳 설정 횟수의 합 + 이동 횟수의 합
 * 알파벳 설정 횟수는 순서에 상관없이 불변.
 * 즉, 이동 횟수만 최적화하면 됨
 * 
 * 이동할 필요가 없다면, 재귀호출할 필요도 없음.
 * 문제를 푸는데 필요한건 각 자리에서 왼쪽, 오른쪽 중 더 가까운 위치까지의 거리
 * 순차적으로 계산을 해서 더하자
 *
 * 안됨 ㅠ
 * 양쪽으로 동시에 출발해서
 * left로 가는 총 거리, right로 가는 총 거리를 구분하여
 * 둘 중 더 짧은 쪽으로 유턴하면? min(left, right)*2+max(left, right)
 *
 * length/2까지 동시에 순회 -> 둘 중 더 짧은 쪽으로 유턴
 * 우측만
 * 좌측만
 * 셋 중 가장 작은 값...
 * 
 * 이거 그리디 맞나?
 *
 * ------------------------------------------------------------------------------------------------
 * 
 * 진짜 진짜 유레카한 풀이과정 생각함
 * 그리디는 여전히 아닌데.. 맞나? 암튼.
 * 기존 문제점 -> 문제의 중앙을 기준으로 좌우측 이동거리를 측정했기에 긴쪽이 중앙선을 넘어가면 제대로 측정이 안됨
 * 두개의 vector를 이용해서 각 지점까지의 우측방향 이동거리, 좌측방향 이동거리를 저장
 * right 벡터에는 맨 앞에 0을 삽입(좌측으로만 움직이는 경우)
 *  left 벡터에는 맨 뒤에 0을 삽입(우측으로만 움직이는 경우)
 * 모든 케이스에 대해 (r은 우측으로 이동한 마지막 위치, l은 좌측으로 이동한 마지막 위치) 2*min(l, r) + max(l, r)을 수행
 * 가장 작은 값이 최적해
 * 
 *	e.g.
 *	ZAAZAAZA
 *	01234567 (각 지점까지의 우측방향 이동거리)
 *	87654321 (각 지점까지의 좌측방향 이동거리)
 *	vector r = {0} + {0, 3, 6}
 *	vector l =       {8, 5, 2} + {0}
 *	r = {0,0,3,6}
 *	l = {8,5,2,0}
 *	d = {8,5,7,6}
 * 
 * ------------------------------------------------------------------------------------------------ */


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(string name) {
	int vertical[26] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int v_move = 0;
	int length = name.length();
	vector<int> right;
	vector<int> left;
	right.push_back(0);
	for (auto i = 0; i < length; i++) {
		cout << vertical[name[i] - 'A'] << " ";
		v_move += vertical[name[i] - 'A'];
		if (name[i] != 'A') {
			right.push_back(i);
			left.push_back(length - i);
		}
	}
	left.push_back(0);

	for (auto i : right) {
		cout << i << " ";
	}
	
	int min = right[0] * 2 + left[0];
	int dis;
	for (auto i = 1; i < right.size(); i++) {
		dis = right[i] < left[i] ? right[i] * 2 + left[i] : right[i] + left[i] * 2;
		if (dis < min) {
			min = dis;
		}
	}

	return min + v_move;
}

#include <iostream>
#include <thread>
#include <tuple>
#include <future>
#include <chrono>
#include <string>

void get_solution(std::string name, std::promise<std::tuple<int, std::chrono::duration<double>>>* p)
{
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	int result = solution(name);
	std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
	std::chrono::duration<double> time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	p->set_value({ result, time });
}

int main()
{
	int right_ans_count = 0;
	std::vector<std::tuple<std::string, int>> testcase;

	/* 테스트케이스를 삽입하는 부분 */
	testcase.push_back({ "JEROEN", 56 });
	testcase.push_back({ "BAC", 23 });
	testcase.push_back({ "ABAAAAAAAAABB", 7 });
	testcase.push_back({ "AZAAAZ", 5 });
	testcase.push_back({ "ABABAAAAAAAAAAAABA", 10 });
	testcase.push_back({ "CANAAAAANAN", 48 });
	testcase.push_back({ "BBABAAAAAAAAAAAABA", 11 });
	testcase.push_back({ "BAAAAABA", 4 });
	testcase.push_back({ "AAA", 0 });
	testcase.push_back({ "", 0 });
	testcase.push_back({ "AAAAAAAAAAAAAAAAAAAA", 0 });
	testcase.push_back({ "ZZZZZZZZZZZZZZZZZZZZ", 39 });
	testcase.push_back({ "Z", 1 });
	testcase.push_back({ "AZAAAAAAAAZAZA", 9 });
	testcase.push_back({ "ZZAAAAAAAAZAZA", 10 });
	testcase.push_back({ "ZZAAAAAAAAZAZZ", 11 });
	testcase.push_back({ "AZZZAAAAAAAZZZ", 15 });
	testcase.push_back({ "ZZZZAAAAAAAZZZ", 16 });
	testcase.push_back({ "AAAAZAAZAAA", 9 });
	testcase.push_back({ "AAAZAAZA", 7 });
	testcase.push_back({ "AZAAAZ", 5 });
	testcase.push_back({ "ABAAABBBBBBB", 17 });

	for (unsigned int i = 0; i < testcase.size(); i++) {
		std::cout << "> Test No." << i + 1 << " ----------------------------------------" << std::endl;

		std::string tc_name;
		int tc_ans;
		std::tie(tc_name, tc_ans) = testcase[i];


		std::promise<std::tuple<int, std::chrono::duration<double>>> p;
		auto f = p.get_future();

		std::thread thr(get_solution, tc_name, &p);
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
				right_ans_count++;
			}

			std::cout << "  Ex_time : " << fixed << ex_time.count() << " seconds" << std::endl;

			std::cout << "  Input   : " << tc_name << std::endl;

			std::cout << "  Output  : " << result << std::endl;
			std::cout << "  Answer  : " << answer << std::endl;
		}

		std::cout << std::endl;
	}

	std::cout << "> Correct " << right_ans_count << " of " << testcase.size() << std::endl;

	return 0;
}