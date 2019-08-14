#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer(n);
	vector<int> sum(n);
	for (auto i = 0; i < n; i++) {
		sum[i] = arr1[i] | arr2[i];
	}
	for (auto i = 0; i < n; i++) {
		auto cur = 0b01 << (n - 1);
		for (auto j = 0; j < n; j++, cur >>= 1) {
			if (sum[i] & cur)
				answer[i] += "#";
			else
				answer[i] += " ";
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
	using namespace std::chrono;

	system_clock::time_point start = system_clock::now();
	auto result = solution(args...);
	system_clock::time_point end = system_clock::now();
	duration<double> time = duration_cast<microseconds>(end - start);

	p->set_value({ result, time });
}

template <typename Tv>
void print_arg(Tv v) 
{
	std::cout << "{";
	unsigned int i = 0;
	for (auto x : v) {
		std::cout << x;
		if (v.size() != ++i)
			std::cout << ", ";
	}
	std::cout << "}";
}

int main()
{
	using namespace std;
	int right_ans_count = 0;
	vector<tuple<int, vector<int>, vector<int>, vector<string>>> testcase; // TODO

	/* 테스트케이스를 삽입하는 부분 */
	testcase.push_back({ 5, {9, 20, 28, 18, 11}, {30, 1, 21, 17, 28}, {"#####", "# # #", "### #", "#  ##", "#####"}}); // TODO
	testcase.push_back({ 6, {46, 33, 33, 22, 31, 50}, {27, 56, 19, 14, 14, 10}, {"######", "###  #", "##  ##", " #### ", " #####", "### # "} }); // TODO

	for (unsigned int i = 0; i < testcase.size(); i++) {
		using namespace std::chrono;
		cout << "> Test No." << i + 1 << " ----------------------------------------" << endl;

		int tc_N;
		vector<int> tc_arr1;
		vector<int> tc_arr2;
		vector<string> tc_ans; // TODO
		vector<string> result; // TODO
		tie(tc_N, tc_arr1, tc_arr2, tc_ans) = testcase[i]; // TODO

		
		promise<tuple<vector<string>, duration<double>>> p; // TODO
		auto f = p.get_future();

		thread thr([&p, tc_N, tc_arr1, tc_arr2]() {get_solution(&p, tc_N, tc_arr1, tc_arr2); }); // TODO
		future_status status = f.wait_for(milliseconds(2100));

		if (status == future_status::timeout) {
			thr.detach();

			cout << "> Time Limit Exceed" << endl;
		}
		else if (status == future_status::ready) {
			thr.join();

			duration<double> ex_time;
			tie(result, ex_time) = f.get();

			if (result != tc_ans) {
				cout << "  Check   : Wrong Answer" << endl;
			}
			else {
				cout << "  Check   : Right Answer" << endl;
				right_ans_count++;
			}

			cout << "  Ex_time : " << fixed << ex_time.count() << " seconds" << endl;

			// TODO
			cout << "  Input   : " << tc_N << ", ";
			print_arg(tc_arr1);
			cout << ", ";
			print_arg(tc_arr2);
			cout << endl;

			cout << "  Output  : ";
			print_arg(result);
			cout << endl;

			cout << "  Answer  : ";
			print_arg(tc_ans);
			cout << endl;
		}

		cout << endl;
	}

	cout << "> Correct " << right_ans_count << " of " << testcase.size() << endl;

	return 0;
}