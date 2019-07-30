/* ================================================================================================
 * Baekjoon Online Judge
 *		1596 - 영식함수
 *
 * time limit per test : 2 seconds
 * memory limit per test : 128 megabytes
 * standard input/standard output
 *
 * 적어도 두 자리 이상의 어떤 자연수 N이 있을 때, 영식함수 F는 다음과 같이 정의할 수 있다. 
 * F(N) = 서로 인접한 자리수의 숫자의 차이를 큰 자리수부터 차례대로 쓴 수.
 *
 * 예를 들어, F(5913) = 482, F(1198) = 081 = 81, F(666) = 00 = 0 이다.
 *
 * 영식이는 영식함수를 이용해서 수열을 하나 만들 수 있는데,
 * N, F(N), F(F(N)), .... 와 같이 한자리 숫자가 나타날 때 까지 수열을 만들 수 있다.
 * 마지막 한자리 숫자를 숫자 N의 지문이라고 부른다.
 * 예를 들어, N=5913일 때 얻을 수 있는 수열은 5913, 482, 46, 2 이다. 5913의 지문은 2이다.
 *
 * 어떤 숫자를 영식함수에 넣고 돌렸을 때, 지문이 7이 나오는 수를 행운의 수라고 한다.
 * A보다 크거나 같고, B보다 작거나 같은 행운의 수의 개수를 구하는 프로그램을 작성하시오.
 * ------------------------------------------------------------------------------------------------ */

#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

void find(std::vector<int>& v, const int target_number[],
	int digit_level, const int & max_digit, int first_digit, int multiplier, int number, int &a, int &b)
	// current digit			max digit		current first		x10			current number
{
	if (digit_level == max_digit) {
		// If the first digit is not zero (e.g. 0992)
		if (first_digit) {
			v.push_back(number);
		}
	}
	else {
		int next_multiplier = multiplier * 10;
		int next_first_digit = first_digit + target_number[digit_level];

		if (next_first_digit < 10) {
			find(v, target_number, digit_level + 1, max_digit,
				next_first_digit, next_multiplier, number + next_multiplier * next_first_digit, a, b);
		}
		next_first_digit = first_digit - target_number[digit_level];
		if (next_first_digit >= 0) {
			find(v, target_number, digit_level + 1, max_digit,
				next_first_digit, next_multiplier, number + next_multiplier * next_first_digit, a, b);
		}
	}
}

void makeFindSet(std::vector<int>& v, std::vector<int> copy, const int & i, int &a, int &b)
{
	// About all found element
	for (std::vector<int>::iterator v_iter = copy.begin(); v_iter != copy.end(); ++v_iter) {
		int target_number_array[9];
		int target_number = *v_iter;

		// Pad the target number with zeros according to the number of digits
		for (int j = 0; j < i; ++j) {
			target_number_array[j] = target_number % 10;
			target_number /= 10;
		}

		// Add j to each digit
		for (int j = 0; j < 10; ++j) {
			find(v, target_number_array, 0, i - 1, j, 1, j, a, b);
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
}

int main()
{
	int a;
	int b;
	const int max_num = 1000000000;

	std::cin >> a >> b;

	// Because it is logic that inspects all possible combinations at the maximum number of digits
	// And max_num(1,000,000,000) is not Lucky Number
	if (b == max_num)
		--b;

	// Get the number of digits of b
	int b_length = static_cast<int>(log10(b)) + 1;
	std::vector<int> v;

	v.push_back(7);
	for (int i = 2; i <= b_length; ++i) {
		makeFindSet(v, v, i, a, b);
	}

	int count = 0;
	// count = v.size().if(a <= X <= b);
	for (std::vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
		if (*i >= a && *i <= b)
			count++;
	}
	std::cout << count;

	return 0;
}