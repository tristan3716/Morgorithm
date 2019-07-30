/* ================================================================================================
 * Codeforces - Codeforces Round #567 (Div. 2)
 *		1181B - Split a Number
 *
 * time limit per test : 2 seconds
 * memory limit per test : 512 megabytes
 * standard input/standard output
 *
 * Dima worked all day and wrote down on a long paper strip his favorite number n consisting of l digits.
 * Unfortunately, the strip turned out to be so long that it didn't fit in the Dima's bookshelf.
 *
 * To solve the issue, Dima decided to split the strip into two non-empty parts so that each of them
 * contains a positive integer without leading zeros. After that he will compute the sum of the two integers
 * and write it down on a new strip.
 *
 * Dima wants the resulting integer to be as small as possible, because it increases the chances that
 * the sum will fit it in the bookshelf. Help Dima decide what is the minimum sum he can obtain.
 * ------------------------------------------------------------------------------------------------ */

#include <iostream>
#include <string>

std::string addNumber(std::string a, int a_size, std::string b, int b_size)
{
	// padding A
	while (a_size < b_size) {
		a.insert(a.begin(), '0');
		a_size++;
	}

	// padding B
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

		// Init minimum difference
		if (min_diff == -1) {
			min_diff = diff;
			min_pos = s1_len;
		}
		else {
			// If the current difference is less than the previous one
			if (min_diff > diff) {
				min_diff = diff;
				min_pos = s1_len;
			}
			// If the difference is the same as before, add two and compare
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
