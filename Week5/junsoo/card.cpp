#include <iostream>
#include <algorithm>
#include <cstring> 

const int MAX = 2000;
int N;
int leftCard[MAX], rightCard[MAX];
int cache[MAX][MAX];

int maxScore(int leftIdx, int rightIdx)
{
	//기저 사례: 두 더미의 카드 중 하나라도 남은 카드가 없다면
	if (leftIdx >= N || rightIdx >= N)
		return 0;

	int& result = cache[leftIdx][rightIdx];

	if (result != -1)
		return result;

	result = 0;

	//왼쪽 덱에 있는 카드가 오른쪽에 있는 카드보다 클 경우 고려사항 3가지
	if (leftCard[leftIdx] > rightCard[rightIdx])
		result += std::max(rightCard[rightIdx] + maxScore(leftIdx, rightIdx + 1), 
			std::max(maxScore(leftIdx + 1, rightIdx), maxScore(leftIdx + 1, rightIdx + 1)));

	//그 외에는 고려사항 2가지

	else
		result += std::max(maxScore(leftIdx + 1, rightIdx), maxScore(leftIdx + 1, rightIdx + 1));

	return result;
}

int main(void)
{
	std::cin >> N;

	for (int i = 0; i < N; i++)
		std::cin >> leftCard[i];

	for (int i = 0; i < N; i++)
		std::cin >> rightCard[i];

	memset(cache, -1, sizeof(cache));
	std::cout << maxScore(0, 0) << std::endl;

	return 0;
}