#include <stdio.h>
//피보나치 함수 f(x) = f(x-1) + f(x-2)
int main()
{
	int T;
	int N;
	scanf("%d", &T); 

	for (int i = 0; i < T; i++)
	{
		int tmp, current = 1, last = 0; //tmp 는 current값을 저장할 임시변수
		//current 는 현재 위치의 피보나치 값, last는 이전 피보나치 값
		scanf("%d", &N);
		if (N == 0)//0일 경우 
		{
			printf("%d %d\n", current, last); // 0: 1 1: 0
		}
		else if (N == 1)//1일 경우
		{
			printf("%d %d\n", last, current); // 0: 0 1: 1
		}
		else//2 이상일 경우
		{
			for (int j = 2; j <= N; j++)
			{
				tmp = current;//tmp에 current값 임시 저장
				current += last; // f(x) = f(x-1) + f(x-2)
				last = tmp; // last를 current로 바꿔줌
			}
			printf("%d %d\n", last, current); //f(N)에서 0의 개수는 f(N-1) 1의 개수는 f(N)
		}
	}
	return 0;
}