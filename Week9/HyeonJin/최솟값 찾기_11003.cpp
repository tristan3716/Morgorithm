#include <iostream>
#include <deque>

using namespace std;

int num[5000000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	deque<pair<int,int>> deq;
	cin >> N >> L;

	for (int i = 0; i < N; ++i) {
		cin >> num[i];
	}
	for (int i = 0; i < N; ++i) {
		if (!deq.empty() && deq.front().first <= i - L) {
			deq.pop_front();
		}
		while (!deq.empty() && deq.back().second > num[i]) {
			deq.pop_back();
		}
		deq.push_back(make_pair(i,num[i]));
		cout << deq.front().second << " ";
	}
	return 0;
}