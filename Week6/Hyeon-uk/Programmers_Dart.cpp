#include <string>
#include <stack>

using namespace std;

int solution(string dartResult) {
	int answer = 0;
	stack<string> s;
	for (unsigned int i = 0; i < dartResult.length();) {
		int num = -1;
		string res;
		while (dartResult[i] >= '0' && dartResult[i] <= '9') {
			res += dartResult[i];
			i++;
		}

		num = atoi(res.c_str());
		int temp = num;
		switch (dartResult[i]){
		case 'T':
			num *= temp; // Cubic
		case 'D':
			num *= temp; // Square
		}
		s.push(to_string(num));
		i++;

		if (dartResult[i] == '*' || dartResult[i] == '#') {
			res = dartResult[i];
			s.push(res);
			i++;
		}
	}
	while (!s.empty()) {
		string v = s.top(); s.pop();
		if (v == "*") {
			string t1 = s.top(); s.pop();
			if (!s.empty()) {
				string t2 = s.top(); s.pop();
				if (t2 == "*" || t2 == "#") {
					string t3 = s.top(); s.pop();
					s.push(to_string(atoi(t3.c_str()) * 2));
					s.push(t2);
				}
				else {
					s.push(to_string(atoi(t2.c_str()) * 2));
				}
			}
			s.push(to_string(atoi(t1.c_str()) * 2));
		}
		else if (v == "#") {
			string t1 = s.top(); s.pop();
			s.push(to_string(-atoi(t1.c_str())));
		}
		else {
			answer += atoi(v.c_str());
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

#define ARGC 1 // TODO
	typedef tuple<string, int> TC_Type; // TODO

	vector<TC_Type> testcase;

	/* 테스트케이스를 삽입하는 부분 */
	//testcase.push_back({ "1S2D*3T", 37 }); // TODO
	//testcase.push_back({ "12S2D*3T", 59 }); // TODO
	testcase.push_back({ "1S*2T*3S", 23 }); // TODO
	testcase.push_back({ "1D#2S*3S", 5 }); // TODO

	/* ------------------------------------------------------------ */

	int right_ans_count = 0;
	for (unsigned int i = 0; i < testcase.size(); i++) {
		using namespace std::chrono;
		cout << "> Test No." << i + 1 << " ----------------------------------------" << endl;
		TC_Type tc = testcase[i];

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