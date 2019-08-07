#include <iostream>
#include <intrin.h>
using namespace std;

enum Direction {
	DIR_U = 0,
	DIR_D = 1,
	DIR_R = 2,
	DIR_L = 3,
	NONE = -1
};
int dx[4] = { -1,1,0,0 }; // U, D, R, L
int dy[4] = { 0,0,1,-1 };
int bit[4] = { 0b0001, 0b0010, 0b0100, 0b1000 };

bool isValid(int cx, int cy) {
	if (cx < 0 || cx == 11 || cy < 0 || cy == 11) {
		return false;
	}
	return true;
}

void move(int map[11][11], int dir, int *cx, int *cy) {
	int nx = *cx + dx[dir];
	int ny = *cy + dy[dir];
	if (isValid(nx, ny)) {
		cout << "move" << dir << endl;
		map[*cx][*cy] |= bit[dir];
		*cx = nx;
		*cy = ny;
	}
}

int solution(string dirs)
{
	int map[11][11] = { 0 };
	int cx = 5, cy = 5;
	for (unsigned int i = 0; i < dirs.length(); i++) {
		int dir;
		switch (dirs[i])
		{
		case 'U':
			dir = DIR_U; break;
		case 'R':
			dir = DIR_R; break;
		case 'L':
			dir = DIR_L; break;
		case 'D':
			dir = DIR_D; break;
		default:
			dir = NONE;
			break;
		}
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				printf("%2d ", map[i][j]);
			}
			puts("");
		}
		printf("%d, %d\n", cx, cy);
		move(map, dir, &cx, &cy);
	}

	int answer = 0;
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			answer += __popcnt(map[i][j]);
			printf("%2d ", map[i][j]);
		}
		puts("");
	}

	return answer;
}

int main()
{
	cout << solution("ULURRDLLU");
}