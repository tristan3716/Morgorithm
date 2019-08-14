#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

void parse(vector<string> source, vector<int> &start, vector<int> &end, vector<int> &t) {

	for (size_t i = 0; i < source.size(); i++) {
		string hh = source[i].substr(11, 2);
		string mm = source[i].substr(14, 2);
		string ss = source[i].substr(17, 2);
		string sss = source[i].substr(20, 3);
		string ds = source[i].substr(24, 1);
		string dms = &source[i][26];
		int temp = atoi(hh.c_str()) * 3600 * 1000
			+ atoi(mm.c_str()) * 60 * 1000
			+ atoi(ss.c_str()) * 1000
			+ atoi(sss.c_str());
		int d = atoi(ds.c_str()) * 1000 + atoi(dms.c_str());

		end.push_back(temp);
		start.push_back(temp - d + 1);
		t.push_back(temp);
		t.push_back(temp - d + 1);
	}
	sort(start.begin(), start.end());
	sort(end.begin(), end.end());
	sort(t.begin(), t.end());
	t.erase(unique(t.begin(), t.end()), t.end());
}

int solution(vector<string> lines) {
	int max = 0;
	int answer = 0;
	vector<int> t, start, end;
	parse(lines, start, end, t);
	size_t  i = 0, is = 0, ie = 0;
	for (; i < t.size(); i++) {
		while (t[i] >= start[is] && is < start.size()) {
			answer++;
			is++;
		}
		while (t[i] >= end[ie] + 1000 && ie < end.size()) {
			answer--;
			ie++;
		}
		if (max < answer) {
			max = answer;
		}
	}
	return max;
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

void print_arg(int v)
{
	std::cout << v;
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
	/* ============================================================ */

#define ARGC 1
	typedef tuple<vector<string>, int> TC_Type;

	vector<TC_Type> testcase;

	/* �׽�Ʈ���̽��� �����ϴ� �κ� */
	testcase.push_back({ {"2016-09-15 01:00:04.002 2.0s", "2016-09-15 01:00:07.000 2s"}, 2 });
	testcase.push_back({ {"2016-09-15 20:59:57.421 0.351s", "2016-09-15 20:59:58.233 1.181s", "2016-09-15 20:59:58.299 0.8s", "2016-09-15 20:59:58.688 1.041s", "2016-09-15 20:59:59.591 1.412s", "2016-09-15 21:00:00.464 1.466s", "2016-09-15 21:00:00.741 1.581s", "2016-09-15 21:00:00.748 2.31s", "2016-09-15 21:00:00.966 0.381s", "2016-09-15 21:00:02.066 2.62s"}, 7 });

	/* ------------------------------------------------------------ */

	TC_Type tc;
	int right_ans_count = 0;
	for (unsigned int i = 0; i < testcase.size(); i++) {
		using namespace std::chrono;
		cout << "> Test No." << i + 1 << " ----------------------------------------" << endl;
		tc = testcase[i];

#if ARGC == 1
		auto arg1 = get<0>(tc);
#elif ARGC == 2
		auto arg2 = get<1>(tc);
#elif ARGC == 3
		auto arg3 = get<2>(tc);
#endif

		auto tc_ans = get<tuple_size<decltype(tc)>::value - 1>(testcase[i]);
		auto result = tc_ans;

#if ARGC == 1
		tie(arg1, tc_ans) = testcase[i];
#elif ARGC == 2
		tie(arg1, arg2, tc_ans) = testcase[i];
#elif ARGC == 3
		tie(arg1, arg2, arg3, tc_ans) = testcase[i];
#endif

		promise<tuple<decltype(tc_ans), duration<double>>> p;
		auto f = p.get_future();

#if ARGC == 1
		thread thr([&p, arg1]() {get_solution(&p, arg1); });
#elif ARGC == 2
		thread thr([&p, arg1, arg2]() {get_solution(&p, arg1, arg2); });
#elif ARGC == 3
		thread thr([&p, arg1, arg2, arg3]() {get_solution(&p, arg1, arg2, arg3); });
#endif

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
			cout << "  Input   : ";
			print_arg(arg1);
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