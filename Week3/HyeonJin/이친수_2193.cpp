#include <stdio.h>
//피보나치 함수와 동일한 문제
int main()
{
	int N;
	long long result[91] = { 0 };//N의 최대값이 90이기 때문에 90번째의 피보나치 함수를 출력하기 위해서 long long타입 설정

	result[1] = 1;
	result[2] = 1;
	result[3] = 2;
	//1,2,3 인덱스 초기값 설정
	scanf("%d", &N);
	for (int i = 4; i <= N; i++)
	{
		//규칙 발견
		result[i] = result[i - 1] + result[i - 2];
	}
	printf("%lld\n", result[N]);//출력

	return 0;
}