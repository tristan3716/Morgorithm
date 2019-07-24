/* ================================================================================================
 * Baekjoon Online Judge
 *		5549 - 행성 탐사
 * 상근이가 보내온 지도는 가로 Ncm, 세로 Mcm 직사각형 모양이다. 
 * 지도는 1cm 크기의 정사각형으로 나누어져 있고, 각 구역의 지형이 알파벳으로 표시되어 있다. 
 * 지형은 정글, 바다, 얼음 중 하나이며, 정글은 J, 바다는 O, 얼음은 I로 표시되어 있다.
 * 지구에 있는 정인이는 조사 대상 영역을 K개 만들었다. 
 * 이때, 각 영역에 정글, 바다, 얼음이 각각 몇 개씩 있는지 구하는 프로그램을 작성하시오.
 * ------------------------------------------------------------------------------------------------
 * N*M의 조사구역이 K개 있다면...?
 * 매번 새로 탐사하려면 O(NMK)의 시간복잡도 -> 1000억
 * 즉, 탐사는 단 한번만 해야한다
 * 
 * 1~N까지의 누적합을 구해놓았을 때, L~N의 누적합은??
 * 1~N의 누적합 - 1~L의 누적합.
 * ------------------------------------------------------------------------------------------------ */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int m, n;
	int k;
	scanf("%d %d %d", &m, &n, &k);

	int **map_ice = (int **)calloc(m + 1, sizeof(int *));
	int **map_jungle = (int **)calloc(m + 1, sizeof(int *));
	int **map_ocean = (int **)calloc(m + 1, sizeof(int *));
	for (int i = 0; i <= m; i++) {
		map_ice[i] = (int *)calloc(n + 1, sizeof(int));
		map_jungle[i] = (int *)calloc(n + 1, sizeof(int));
		map_ocean[i] = (int *)calloc(n + 1, sizeof(int));
	}

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			char ch;
			int fi = 0, fj = 0, fo = 0;
			scanf(" %c", &ch);

			switch (ch) {
			case 'J':
				fj = 1;
				break;
			case 'I':
				fi = 1;
				break;
			case 'O':
				fo = 1;
				break;
			default:
				printf("Something Wrong!\n");
				break;
			}
			map_jungle[i][j] = fj - map_jungle[i - 1][j - 1] + map_jungle[i][j - 1] + map_jungle[i - 1][j];
			map_ice[i][j] = fi - map_ice[i - 1][j - 1] + map_ice[i][j - 1] + map_ice[i - 1][j];
			map_ocean[i][j] = fo - map_ocean[i - 1][j - 1] + map_ocean[i][j - 1] + map_ocean[i - 1][j];
		}
	}
	for (int i = 1; i <= k; i++) {
		int a, b, c, d;
		scanf("%d %d %d %d", &a, &b, &c, &d);

		int count_jungle = 0, count_ice = 0, count_ocean = 0;
		count_ice = map_ice[a - 1][b - 1] - map_ice[c][b - 1] - map_ice[a - 1][d] + map_ice[c][d];
		count_jungle = map_jungle[a - 1][b - 1] - map_jungle[c][b - 1] - map_jungle[a - 1][d] + map_jungle[c][d];
		count_ocean = map_ocean[a - 1][b - 1] - map_ocean[c][b - 1] - map_ocean[a - 1][d] + map_ocean[c][d];

		printf("%d %d %d\n", count_jungle, count_ocean, count_ice);
	}

	return 0;
}