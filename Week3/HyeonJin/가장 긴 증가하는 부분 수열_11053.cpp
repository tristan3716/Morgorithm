#include <stdio.h>

int main()
{
	int N;
	int num[1001] = { 0, };
	int result[1001] = { 0, };
	int count = 0;
	scanf("%d", &N);//배열 개수 입력

	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &num[i]);//배열 값 입력
	}
	//result 배열의 1번 인덱스 값 복사
	result[1] = num[1];
	//2번 인덱스부터 시작
	for (int i = 2; i <= N; i++)//i는 인덱스 2번부터 N까지 오름차순으로 num 배열 탐색
	{
		for (int j = i - 1; j >= 1; j--)//j는 인덱스 i-1번째부터 1번까지 내림차순으로 result배열 탐색
		{
			if (result[j] == 0)//result 배열을 0으로 초기화 했기 때문에 인덱스 값이 0일 경우 넘어감
				continue;
			if (num[i] > result[j])//i번째 값이 j번째 값보다 클 경우
			{
				result[j + 1] = num[i];//j+1번째 result 값을 i번째 num값으로 복사
				break;
			}
			else if (j == 1) //끝까지 도달하였을 경우 1번 인덱스의 result 배열 값을 num[i]값으로 바꿔줌
				result[j] = num[i];	
		}
	}
	for (int i = 1; i <= N; i++)
	{
		
		//result 배열에 0이 아닌 값의 개수 세기
		if (result[i] != 0)
			count++;
	}

	printf("%d", count);//출력

	return 0;
}
