#include <stdio.h>

int result[1000002] = { 0 };

int main()
{
	int N;
	
	result[1] = 0;
	result[2] = 1;
	result[3] = 1;
	//배열 인덱스 1 2 3 초기값 설정
	scanf("%d", &N);//입력
	for (int i = 4; i <= N; i++)//4 이상일 경우
	{
		int temp1 = 500001, temp2 = 500001, temp3 = 500001;//출력으로 나올 수 없는 큰 값 임시로 설정
		int max = 500000;//출력으로 나올 수 없지만 temp 보다는 작은 값 설정
		if (i % 3 == 0)
		{
			//3으로 나눠질 경우 temp1에 result[i/3] 번째보다 1 큰 값 저장
			temp1 = result[i / 3] + 1;
		}
		if (i % 2 == 0 )
		{
			//2으로 나눠질 경우 temp2에 result[i/2] 번째보다 1 큰 값 저장
			temp2 = result[i / 2] + 1;
			
		}
		//temp3에 result[i-1] 번째보다 큰 값 무조건 저장
		temp3 = result[i - 1] + 1;
		//비교
		if (max > temp1) //temp1 비교, temp1의 값이 바뀔 경우 즉 i % 2 == 0 인 경우
			max = temp1;
		if (max > temp2) // temp2 비교, temp2의 값이 바뀔 경우, 즉 i%3 == 0 인 경우
			max = temp2;
		if (max > temp3) // temp3 비교, temp3는 무조건 변경됨 
			max = temp3;

		//위의 비교를 통해서 가장 작은 값 저장
		result[i] = max;
	
	} 
	printf("%d\n", result[N]);//출력

	return 0;
}