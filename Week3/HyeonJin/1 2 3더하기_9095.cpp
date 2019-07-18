#include <stdio.h>

int main()
{
	int T;
	int n;
	int result[11] = { 0 };//n 최대값 10
	scanf("%d", &T);

	result[1] = 1;
	result[2] = 2;
	result[3] = 4;
	//배열 인덱스 1 2 3 초기값 설정
	for (int i = 0; i < T; i++)
	{
		scanf("%d", &n);//입력
		for (int j = 4; j <= n; j++)//입력값 4 이상일 경우
		{
			//규칙 발견
			result[j] = result[j - 1] + result[j - 2] + result[j - 3];
		}
		printf("%d\n", result[n]);//출력
	}
	return 0;
}