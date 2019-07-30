//조합을 통한 계산이 더 효율적!! 
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>
//조합찾는 함수 
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
		//자리수 변경 
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
	int b_length = static_cast<int>(log10(b)) + 1;//길이 측정->내 방법보다 효율성좋음 
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
