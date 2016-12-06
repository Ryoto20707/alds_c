#include <stdio.h>
#include <stdlib.h>
#include "../util/queue.h"

typedef struct point point;

struct point{
	int x, y;
};

point *newP(int x, int y) {
	point *p;
	p = malloc(sizeof(point));
	p->x = x;
	p->y = y;
	return p;
}

int main(void) {
	int H, W, i, j, cnt;
	char **map;
	point start;
	int nextX[] = {0, 1, 0, -1}, nextY[] = {1, 0, -1, 0};
	while (1) {
		cnt = 0;
		scanf("%d %d", &W, &H);
		if (W == 0 && H == 0) break;
		map = malloc(H * sizeof(char *));
		Queue *next = qInit();
		for (i = 0; i < H; i++) {
			map[i] = malloc(W * sizeof(char));
			for (j = 0; j < W; j++) {
				scanf("%c", &map[i][j]);
				if (map[i][j] == '\n') {
					j--;
					continue;
				}
				if (map[i][j] == '@') {
					start.x = j;
					start.y = i;
					map[i][j] = '.';
				}
			}
		}
		add(next, &start);
		while (next->size != 0) {
			point *p = poll(next);
			if (map[p->y][p->x] == '#') continue;
			map[p->y][p->x] = '#';
			cnt++;
			for (i = 0; i < 4; i++) {
				if (p->y + nextY[i] >= 0 && p->y + nextY[i] < H && p->x + nextX[i] >= 0 && p->x + nextX[i] < W
				    && map[p->y + nextY[i]][p->x + nextX[i]] == '.') {
					add(next, newP(p->x + nextX[i], p->y + nextY[i]));
				}
			}
		}
		printf("%d\n", cnt);
	}
	return 0;
}