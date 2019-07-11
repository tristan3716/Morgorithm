//덧셈 수 최소화
//c++이 더 강력! 
#include <iostream>
#include <string>

std::string addNumber(std::string a, int a_size, std::string b, int b_size)
{
	//자리수 맞춤 
	while (a_size < b_size) {
		a.insert(a.begin(), '0');
		a_size++;
	}

	while (a_size > b_size) {
		b.insert(b.begin(), '0');
		b_size++;
	}

	std::string res = "";
	int carry = 0;
	for (int i = b_size - 1; i >= 0; --i) {
		int sum = (a[i] - '0') + (b[i] - '0') + carry;
		carry = sum / 10;
		res = char(sum % 10 + 48) + res;
	}

	if (carry > 0)
		res = '1' + res;

	return res;
}

int main()
{
	int n;
	std::string s;

	std::cin >> n >> s;

	int min_diff = -1;
	int min_pos;

	int s1_len;
	int s2_len;

	for (int i = 0; i < n - 1; i++) {
		if (s[i + 1] == '0') {
			continue;
		}
		s1_len = i + 1;
		s2_len = n - i - 1;

		int diff = s1_len - s2_len;
		diff = diff >= 0 ? diff : -diff;

		// 최소로 만드는 자리 찾음
		//중간지점이 0일경우 나눌수 없으므로 필요한 과정!!(내가 틀린 부분) 
		if (min_diff == -1) {
			min_diff = diff;
			min_pos = s1_len;
		}
		else {
			if (min_diff > diff) {
				min_diff = diff;
				min_pos = s1_len;
			}
			else if (min_diff == diff) {
				if (addNumber(s.substr(0, min_pos), min_pos, &s[min_pos], n - min_pos) >
					addNumber(s.substr(0, s1_len), s1_len, &s[s1_len], s2_len)) {
					min_pos = s1_len;
				}
			}
		}
	}

	std::string min1 = s.substr(0, min_pos);
	std::string min2 = &s[min_pos];

	std::cout << addNumber(min1, min_pos, min2, n - min_pos) << std::endl;

	return 0;
}
