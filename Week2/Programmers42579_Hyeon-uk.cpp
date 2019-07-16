/* ================================================================================================
 * Programmers
 *		42579 - 베스트앨범
 *
 * time limit per test : ?? seconds
 * memory limit per test : ?? megabytes
 * solution function's arguments/return value
 *
 * 스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시하려 합니다. 
 * 노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.
 * 
 *		1. 속한 노래가 많이 재생된 장르를 먼저 수록합니다.
 *		2. 장르 내에서 많이 재생된 노래를 먼저 수록합니다.
 *		3. 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.
 *
 * 노래의 장르를 나타내는 문자열 배열 genres와 노래별 재생 횟수를 나타내는 정수 배열 plays가 주어질 때, 
 * 베스트 앨범에 들어갈 노래의 고유 번호를 순서대로 return 하도록 solution 함수를 완성하세요.
 *
 * ------------------------------------------------------------------------------------------------
 *
 * map 컨테이너 사용
 * 장르에 따른 전체 재생횟수를 저장하는 map1
 * 각 노래별 인덱스 및 재생횟수를 저장하는 map2
 * 이때 map2는 key는 장르, value는 다른 컨테이너를 이용하여 해당 장르에 속한 곡들을 모두 저장
 * 
 * 입력값 모두를 map1, map2에 적재
 * 이때 map2는 정렬된 상태로 삽입할 수 있는 우선순위큐 사용
 * map1은 삽입이 끝난 후 정렬
 * 
 * map1을 순회하며 map2에 있는 요소를 1~2개씩 꺼내옴
 *
 * Hash인 이유?
 * map2의 구조
 *
 * Genres1 : song1 -> song2 -> song3 -> song4
 * Genres2 : song4 -> song5
 * Genres3 : song6 -> song7 -> song8
 * Genres4 : song9
 *
 * 때문 아닐까?
 *
 * ------------------------------------------------------------------------------------------------ */

#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

template<template <typename> class P = std::less >
struct compare_pair_second {
	template<class T1, class T2> bool operator()(const std::pair<T1, T2>&left, const std::pair<T1, T2>&right) {
		return P<T2>()(left.second, right.second);
	}
};


vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;

	map<string, int> total;
	map<string, priority_queue<pair<int, int>, vector<pair<int, int>>, compare_pair_second<>>> songs;

	for (unsigned int i = 0; i < genres.size(); i++) {
		total[genres[i]] += plays[i];
		songs[genres[i]].push(pair<int, int>(i, plays[i]));
	}

	vector<pair<string, int>> v_total(total.begin(), total.end());
	sort(v_total.begin(), v_total.end(), compare_pair_second<std::greater>());

	for (vector<pair<string, int>>::iterator i = v_total.begin(); i != v_total.end(); i++) {
		unsigned int sz = songs[i->first].size();
		for (unsigned int j = 0; j < sz && j < 2; j++) {
			answer.push_back(songs[i->first].top().first);
			songs[i->first].pop();
		}
	}

	return answer;
}

#include <iostream>
#include <thread>
#include <tuple>
#include <future>
#include <chrono>
#include <string>

template <class P, class... Args>
void get_solution(P *p, Args... args)
{
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	auto result = solution(args...);
	std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
	std::chrono::duration<double> time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	p->set_value({ result, time });
}

template <typename Tv>
void print_vector(Tv v) {
	std::cout << "{";
	int i = 0;
	for (auto x : v) {
		std::cout << x;
		if (v.size() != ++i)
			std::cout << " ";
	}
	std::cout << "}";
}

int main()
{
	int right_ans_count = 0;
	std::vector<std::tuple<vector<string>, vector<int>, std::vector<int>>> testcase;

	/* 테스트케이스를 삽입하는 부분 */
	testcase.push_back({ {"classic", "pop", "classic", "classic", "pop" }, {500, 600, 150, 800, 2500 }, {4, 1, 3, 0} });
	testcase.push_back({ {"t1", "t2", "t1", "t1", "t2", "t1", "t3", "t4" }, {50, 600, 150, 800, 2500, 6000, 400, 20000 }, {7, 5, 3, 4, 1, 6} });


	for (unsigned int i = 0; i < testcase.size(); i++) {
		std::cout << "> Test No." << i + 1 << " ----------------------------------------" << std::endl;
		std::vector<std::string> tc_arg1;
		std::vector<int> tc_arg2;
		std::vector<int> answer;
		std::vector<int> result;
		std::tie(tc_arg1, tc_arg2, answer) = testcase[i];


		std::promise<std::tuple<std::vector<int>, std::chrono::duration<double>>> p;
		auto f = p.get_future();
		//std::thread thr(get_solution, &p, tc_genres, tc_plays);
		std::thread thr([&p, tc_arg1, tc_arg2]() {get_solution(&p, tc_arg1, tc_arg2); });
		std::future_status status = f.wait_for(std::chrono::milliseconds(2100));

		if (status == std::future_status::timeout) {
			thr.detach();

			std::cout << "> Time Limit Exceed" << std::endl;
		}
		else if (status == std::future_status::ready) {
			thr.join();

			std::chrono::duration<double> ex_time;

			std::tie(result, ex_time) = f.get();

			if (result != answer) {
				std::cout << "  Check   : Wrong Answer" << std::endl;
			}
			else {
				std::cout << "  Check   : Right Answer" << std::endl;
				right_ans_count++;
			}

			std::cout << "  Ex_time : " << fixed << ex_time.count() << " seconds" << std::endl;

			std::cout << "  Input   : ";
			print_vector(tc_arg1);
			print_vector(tc_arg2);
			std::cout << std::endl;

			std::cout << "  Output  : ";
			print_vector(result);
			std::cout << std::endl;

			std::cout << "  Answer  : ";
			print_vector(answer);
			std::cout << std::endl;
		}

		std::cout << std::endl;
	}

	std::cout << "> Correct " << right_ans_count << " of " << testcase.size() << std::endl;

	return 0;
}