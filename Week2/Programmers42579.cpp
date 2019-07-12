#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	vector<int> answer;
	return answer;
}

#include <iostream>
#include <thread>
#include <tuple>
#include <future>
#include <chrono>
#include <string>

void get_solution(vector<string> genres, vector<int> plays, std::promise<std::tuple<std::vector<int>, std::chrono::duration<double>>>* p)
{
	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	std::vector<int> result = solution(genres, plays);
	std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
	std::chrono::duration<double> time = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

	p->set_value({ result, time });
}

template <typename T>
void print_vector(T v) {
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
	std::vector<std::tuple<vector<string>, vector<int>, std::vector<int> >> testcase;

	/* 테스트케이스를 삽입하는 부분 */
	testcase.push_back({ {"classic", "pop", "classic", "classic", "pop" }, {500, 600, 150, 800, 2500 }, {4, 1, 3, 0} });


	for (unsigned int i = 0; i < testcase.size(); i++) {
		std::cout << "> Test No." << i + 1 << " ----------------------------------------" << std::endl;

		std::vector<std::string> tc_genres;
		std::vector<int> tc_plays;
		std::vector<int> tc_ans;
		std::tie(tc_genres, tc_plays, tc_ans) = testcase[i];


		std::promise<std::tuple<std::vector<int>, std::chrono::duration<double>>> p;
		auto f = p.get_future();

		std::thread thr(get_solution, tc_genres, tc_plays, &p);
		std::future_status status = f.wait_for(std::chrono::milliseconds(2100));

		if (status == std::future_status::timeout) {
			thr.detach();

			std::cout << "> Time Limit Exceed" << std::endl;
		}
		else if (status == std::future_status::ready) {
			thr.join();

			std::vector<int> answer = tc_ans;
			std::chrono::duration<double> ex_time;
			std::vector<int> result;
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
			print_vector(tc_genres);
			print_vector(tc_plays);
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