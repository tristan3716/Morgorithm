/*
 * https://www.acmicpc.net/problem/14502
 * ¿¬±¸¼Ò
 * Time Limit : 2 seconds
 * Memory Limit : 512 MB
 *
 */

#include <iostream>
#include <queue>

typedef struct _Pos {
	int x;
	int y;
} Pos;

const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

bool isValid(const int &x, const int &y, const int &n, const int &m) {
	if (x < 0 || y < 0 || x >= n || y >= m) {
		return false;
	}
	return true;
}

int bfs(const int * const * const map, int * const * const visit, const int &n, const int &m, const int &i, const int &j) {
	std::queue<Pos> q;
	bool corrupted = false;
	int area = 0;
	if (map[i][j] != 1)
		q.push({ i, j });

	while (!q.empty()) {
		Pos t = q.front(); q.pop();

		if (visit[t.x][t.y])
			continue;
		visit[t.x][t.y] = 1;
		if (map[t.x][t.y] == 2) {
			corrupted = true;
		}
		else {
			++area;
		}
		int x, y;
		for (auto i = 0; i < 4; ++i) {
			x = t.x + dx[i];
			y = t.y + dy[i];
			if (isValid(x, y, n, m) && map[x][y] != 1) {
				q.push({ x, y });
			}
		}
		if (corrupted)
			break;
	}
	while (!q.empty()) {
		Pos t = q.front(); q.pop();

		if (visit[t.x][t.y])
			continue;
		visit[t.x][t.y] = 1;
		int x, y;
		for (auto i = 0; i < 4; ++i) {
			x = t.x + dx[i];
			y = t.y + dy[i];
			if (isValid(x, y, n, m) && map[x][y] != 1) {
				q.push({ x, y });
			}
		}
	}
	if (corrupted) {
		return 0;
	}
	return area;
}

int getArea(const int * const * const map, const int &n, const int &m) {
	int area = 0;
	int **visit = (int **)calloc(n, sizeof(int *));
	for (auto i = 0; i < n; i++) {
		visit[i] = (int *)calloc(m, sizeof(int));
	}
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < m; ++j) {
			if (!visit[i][j]) {
				area += bfs(map, visit, n, m, i, j);
			}
		}
	}
	return area;
}

int makeWall(int * const map[8], int cnt, const int &n, const int &m, const int &is, const int &js) {
	int area = 0;
	if (cnt == 3) {
		area = getArea(map, n, m);
	}
	else {
		int j = js;
		for (int i = is; i < n; ++i, j = 0) {
			for (; j < m; ++j) {
				if (map[i][j] == 0) {
					map[i][j] = 1;
					int temp_area = makeWall(map, cnt + 1, n, m, i, j);
					if (temp_area > area) {
						area = temp_area;
					}
					map[i][j] = 0;
				}
			}
		}
	}
	return area;
}

int main(void) {
	using namespace std;
	int n, m;
	int *map[8];
	for (auto i = 0; i < 8; i++) {
		map[i] = (int *)calloc(8, sizeof(int));
	}
	cin >> n >> m;
	for (auto i = 0; i < n; ++i) {
		for (auto j = 0; j < m; ++j) {
			cin >> map[i][j];
		}
	}

	int area = makeWall(map, 0, n, m, 0, 0);
	cout << area;

	return 0;
}