#include <iostream>
#include <algorithm>
#include <vector>

int main(void) {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> arr;
	arr.resize(n);
	for (auto i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}

	double result = 987654321;
	for (int i = 0; i < n - k + 1; ++i) {
		for (int j = k; j < n - i + 1; ++j) {
			int sum = 0;
			for (int l = i; l < i + j; ++l) {
				sum += arr[l];
			}
			double average = sum / (double)j;
			double sum2 = 0;
			for (int l = i; l < i + j; ++l) {
				sum2 += (arr[l] - average)*(arr[l] - average);
			}
			result = std::min(result, sqrt(sum2 / (double)j));
		}
	}
	std::cout.precision(11); 
	std::cout << result;
	return 0;
}