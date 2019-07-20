package 등굣길_42898;

import java.util.Scanner;

public class Solution_42898 {
	 public static int solution(int m, int n, int[][] puddles) {
		 int arr[][] = new int[101][101];//최대 100개
		 int arr1[][] = new int[101][101];
		 //arr , arr1 배열 0으로 초기화
		 for(int i=0;i<arr.length;i++)
			{
				for(int j=0;j<arr[i].length;j++)
				{
					arr[i][j] = 0;
					arr1[i][j] = 0;
				}
			}
		 //연못 위치 값 -1로 만들어줌
		 for(int i=0;i<puddles.length;i++)
		 {
				 arr1[puddles[i][0]][puddles[i][1]]  = -1;

		 }
		 //멘 처음 집의 위치
		 arr[1][1] = 1;
		
		 for (int i = 1; i <= m; i++)
			{
				for (int j = 1; j <= n; j++)
				{
					//연못일경우
						if (arr1[i][j]== -1)
						{
							arr[i][j] = 0;	//연못일 경우 최단경로의 수 0으로 만들어줌
						}
						else
						{
							if (i == 1 && j == 1)
								arr[i][j] = 1;
							else {
								//특정 좌표(i,j)의 최단 경로 개수는  (i-1,j)의 최단경로의 수 + (i,j-1)의 최단 경로수의 수 
								//이때 1000000007을 초과하는 경우가 있기 때문에 더하기 전 1000000007으로 항상 나눠줘야 함
								arr[i][j] = (arr[i - 1][j]%1000000007) + (arr[i][j - 1]%1000000007);	
							}	
						}
				}
			}
			return arr[m][n] % 1000000007;
	    }
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int m = scanner.nextInt();
		int n = scanner.nextInt();
		
		int arr[][] = new int[101][101];
		int arr1[][] = new int[2][2];
		for(int i=0;i<arr.length;i++)
		{
			for(int j=0;j<arr[i].length;j++)
			{
				arr[i][j] = 0;
		
			}
		}
		//테스트 케이스
		arr1[0][0] = 2;
		arr1[0][1] = 2;
		arr1[1][0] = 3;
		arr1[1][1] = 2;
		arr[m][n] = solution(m,n,arr1);
		
		System.out.println(arr[m][n]);
		
		scanner.close();
	}

}
