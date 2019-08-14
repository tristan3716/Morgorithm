#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string findMin(map<string, int> cache) {
	map<string, int>::iterator i = cache.begin();
	string ans;
	int min = -1;
	for (; i != cache.end(); i++) {
		if (min == -1 && i->second > 0) {
			ans = i->first;
			min = i->second;
		}
		else if (min > i->second && i->second > 0) {
			ans = i->first;
			min = i->second;
		}
	}
	return ans;
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	unsigned int n = cities.size();
	map<string, int> cache;
	int cnt = 0;

	for (unsigned int i = 0; i < n; i++) {
		string str = cities[i];
		std::transform(str.begin(), str.end(), str.begin(), [](char c) { return (char)toupper(c); });

		if (cacheSize == 0) {
			answer += 5;
		}
		else if (cnt < cacheSize && cache[str] == 0) {
			cnt++;
			cache[str] = i+1;
			answer += 5;
		}
		else if (cache[str] == 0) { // miss
			cache[findMin(cache)] = 0;
			cache[str] = i + 1;
			answer += 5;
		}
		else { // hit
			cache[str] = i + 1;
			answer += 1;
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
	int right_ans_count = 0;
	vector<tuple<int, vector<string>, int>> testcase; // TODO

	/* 테스트케이스를 삽입하는 부분 */
	testcase.push_back({ 3,{"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" }, 50 }); // TODO
	testcase.push_back({ 3, {"Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul"}, 21 }); // TODO
	testcase.push_back({ 5, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"},52 }); // TODO
	testcase.push_back({ 0, {"Jeju", "Pangyo", "Seoul", "NewYork", "LA"}, 25 }); // TODO
	testcase.push_back({ 2, {"Jeju", "Pangyo", "NewYork", "newyork"}, 16 }); // TODO
	testcase.push_back({ 5, {"aa", "aa", "Aa", "aA"}, 8 }); // TODO
	testcase.push_back({ 0, {"aa", "aa", "Aa", "aA", "aA", "ab", "ac", "ad", "ae", "af", "aa", "ac"}, 60 }); // TODO

	for (unsigned int i = 0; i < testcase.size(); i++) {
		using namespace std::chrono;
		cout << "> Test No." << i + 1 << " ----------------------------------------" << endl;

		int tc_cacheSize;
		vector<string> tc_cities;
		int tc_ans; // TODO
		int result; // TODO
		tie(tc_cacheSize, tc_cities, tc_ans) = testcase[i]; // TODO


		promise<tuple<int, duration<double>>> p; // TODO
		auto f = p.get_future();

		thread thr([&p, tc_cacheSize, tc_cities]() {get_solution(&p, tc_cacheSize, tc_cities); }); // TODO
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
			cout << "  Input   : " << tc_cacheSize << ", ";
			print_arg(tc_cities);
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
