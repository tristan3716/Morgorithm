#include <stdio.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

int count = 0;
int chess[226] = { -1, };

void search(int currentRow,int N);
int isPossible(int currentRow);

int main()
{
	int N;

	scanf("%d", &N);
	search(0, N);//0행부터 시작
	
	printf("%d\n", count);

	return 0;
}
//행을 하나씩 내려가면서 퀸이 위치할 수 있는 곳 찾음
void search(int currentRow,int N)
{
	if (currentRow == N)//현재행과 마지막행이 같으면 퀸이 모두 위치하였으므로 count증가
		count++;
	else {
		//첫행부터 마지막 행까지 가능한 자리 검사
		for (int i = 0; i < N; i++)
		{
			chess[currentRow] = i;//현재 행의 모든 열에 다 넣어봄
			if (isPossible(currentRow) == TRUE)//현재 행이 가능하다면 
				search(currentRow + 1, N); //다음행으로 넘어감
		}
	}
}
int isPossible(int currentRow)
{
	//검사하려는 행의 모든 열마다 퀸을 위치시키고, 해당 위치에서 위 아래 옆 대각선으로 퀸 존재하는지 확인
	for (int i = 0; i < currentRow; i++) {
		//서로 각은 열에 존재하는지 검사
		if (chess[i] == chess[currentRow])
			return FALSE;
		//서로 대각선상에 존재하는지 검사
		if (abs(chess[i] - chess[currentRow]) == abs(i - currentRow))
			return FALSE;
	}
	return TRUE;
}