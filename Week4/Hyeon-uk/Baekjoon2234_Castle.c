/* ================================================================================================
 * Baekjoon Online Judge
 *		2234 - 성곽
 *
 * time limit per test : 2 seconds
 * memory limit per test : 128 megabytes
 * standard input/standard output
 *
 * 성의 지도를 입력받아서 다음을 계산하는 프로그램을 작성하시오.
 *
 * 1. 이 성에 있는 방의 개수
 * 2. 가장 넓은 방의 넓이
 * 3. 하나의 벽을 제거하여 얻을 수 있는 가장 넓은 방의 크기
 *
 * 성은 m×n(1 ≤ m, n ≤ 50)개의 정사각형 칸으로 이루어진다. 
 * 성에는 최소 두 개의 방이 있어서, 항상 하나의 벽을 제거하여 두 방을 합치는 경우가 있다.
 *
 * ------------------------------------------------------------------------------------------------
 *
 * BFS로 1, 1에서 시작
 * 주위 4칸 큐1에 삽입
 * 큐에서 꺼내서 또 주위 4칸~~
 * 벽이 있으면 큐2에 삽입
 * 큐1을 모두 탐색한 후(큐가 비었으면)
 * 현재까지의 넓이를 저장
 * 1:x
 *
 * 다음 방(큐2에서 팝) 검사 시작
 * 2 : y
 * 3 : z
 * ....
 * 50 : zz
 *
 * 연결상태는 큐2에 삽입할 때 2차원 배열로 저장함
 *
 * 넓이의 최대값 : 1 : x ~50 : zz에서 맥스
 * 방 2개 넓이 최대값 : 연결상태 확인해서 1 : x ~50 : zz로부터 계산
 * 방의 개수
 * 1 : x ~50 : zz 계산 과정에서 저장함
 *
 * ------------------------------------------------------------------------------------------------ */

#include <stdio.h>

enum Direction {
	WEST = 0b0001,
	NORTH = 0b0010,
	EAST = 0b0100,
	SOUTH = 0b1000
};

typedef struct {
	int x;
	int y;
	int room_number;
} Pos;

typedef struct {
	Pos *queue;
	int first;
	int last;
} Queue;

__inline void init(Queue *q, Pos *queue) {
	q->queue = queue;
	q->first = 0;
	q->last = 0;
}

__inline void push(int x, int y, int rn, Queue *q) {
	Pos *qp = q->queue;
	int idx = q->last;
	qp[idx].x = x;
	qp[idx].y = y;
	q->last++;
	qp[idx].room_number = rn;
}

__inline void pop(int *x, int *y, int *rn, Queue *q) {
	Pos *qp = q->queue;
	int idx = q->first;
	*x = qp[idx].x;
	*y = qp[idx].y;
	q->first++;
	*rn = qp[idx].room_number;
}

__inline int isEmpty(Queue q) {
	return q.first == q.last;
}

int isValid(int x, int y, int n, int m) {
	if (x >= n || y >= m || x < 0 || y < 0) {
		return 0;
	}
	return 1;
}

int adjacent_matrix[2500][2500];
int main(void) {
	int n, m;
	int castle[50][50][2]; // [0] : wall state, [1] : room number

	Pos queue_same[4*2500];
	Pos queue_diff[4*2500];
	Queue q_same; // bfs Same room
	Queue q_diff; // bfs different room

	int visit_count = 0;

	int room_count = 0;
	int current_room_size = 0;
	int max_room_size = 0;
	int room_size[2500] = { 0 };

	scanf("%d %d", &n, &m);
	init(&q_same, queue_same);
	init(&q_diff, queue_diff);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &castle[i][j][0]);
			castle[i][j][1] = -1;
		}
	}

	push(0, 0, 0, &q_same); // BFS start at (0,0)
	while ((!isEmpty(q_same) || !isEmpty(q_diff)) && visit_count < n*m) {
		int cx, cy;
		int from;
		if (isEmpty(q_same)) {
			pop(&cx, &cy, &from, &q_diff);

			if (castle[cy][cx][1] != -1) {
				adjacent_matrix[castle[cy][cx][1]][from] = 1;
				continue;
			}
			else {
				adjacent_matrix[room_count + 1][from] = 1;
			}

			if (max_room_size < current_room_size) {
				max_room_size = current_room_size;
			}
			room_size[room_count] = current_room_size;
			current_room_size = 0;
			room_count++;
		}
		else {
			pop(&cx, &cy, &from, &q_same);

			adjacent_matrix[room_count][from] = 1;
			if (castle[cy][cx][1] != -1) {
				continue;
			}
		}

		castle[cy][cx][1] = room_count;
		visit_count++;
		current_room_size++;

		if (isValid(cx, cy - 1, n, m) != 0) {
			if (castle[cy][cx][0] & NORTH)
				push(cx, cy - 1, room_count, &q_diff);
			else 
				push(cx, cy - 1, room_count, &q_same);
		}
		if (isValid(cx, cy + 1, n, m) != 0) {
			if (castle[cy][cx][0] & SOUTH)
				push(cx, cy + 1, room_count, &q_diff);
			else
				push(cx, cy + 1, room_count, &q_same);
		}
		if (isValid(cx - 1, cy, n, m) != 0) {
			if (castle[cy][cx][0] & WEST)
				push(cx - 1, cy, room_count, &q_diff);
			else
				push(cx - 1, cy, room_count, &q_same);
		}
		if (isValid(cx + 1, cy, n, m) != 0) {
			if (castle[cy][cx][0] & EAST)
				push(cx + 1, cy, room_count, &q_diff);
			else
				push(cx + 1, cy, room_count, &q_same);
		}
	}
	// set last room
	room_size[room_count] = current_room_size;
	if (max_room_size < current_room_size) {
		max_room_size = current_room_size;
	}

	// handle remaining coordinates
	while (!isEmpty(q_diff)) {
		int cx, cy, from;
		pop(&cx, &cy, &from, &q_diff);
		adjacent_matrix[castle[cy][cx][1]][from] = 1;
	}

	// expand all rooms to find the maximum
	int max_expanded_room_size = 0;
	for (int i = 0; i < room_count + 1; i++) {
		for (int j = i + 1; j < room_count + 1; j++) {
			if (adjacent_matrix[j][i] == 1) {
				int size = room_size[i] + room_size[j];
				if (max_expanded_room_size < size)
					max_expanded_room_size = size;
			}
		}
	}

	printf("%d\n", room_count + 1);
	printf("%d\n", max_room_size);
	printf("%d\n", max_expanded_room_size);

	return 0;
}