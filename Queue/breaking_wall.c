#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int board[1005][1005];
int dis[1005][1005][2];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };



typedef struct {
	int x;
	int y;
	int z;
}pii;

typedef struct node {
	pii data;
	struct node* prev;
	struct node* next;
}node;

node* front;
node* rear;

void init_deque()
{
	front = NULL;
	rear = NULL;
}

node* alloc_node(pii a) {
	node* p = malloc(sizeof(node));
	p->data = a;
	p->prev = NULL;
	p->next = NULL;
	return p;
}

int is_empty() {
	return front == NULL;
}

void add_front(pii a) {
	node* p = alloc_node(a);
	if (is_empty()) {
		front = p;
		rear = p;
	}
	else {
		p->next = front;
		front->prev = p;
		front = p;
	}
}

void add_rear(pii a) {
	node* p = alloc_node(a);
	if (is_empty()) {
		front = p;
		rear = p;
	}
	else {
		p->prev = rear;
		rear->next = p;
		rear = p;
	}
	
}

pii del_front() {
	if (is_empty()) return (pii){0,0,0};
	node* p = front;
	if (front == rear) {
		front = NULL;
		rear = NULL;
	}
	else {
		front = front->next;
		
	}
	pii res = p->data;
	free(p);
	return res;
}

pii del_rear() {
	if (is_empty()) return(pii) { 0, 0, 0 };
	node* p = rear;
	if (front == rear) {
		front = NULL;
		rear = NULL;
	}
	else {
		rear = rear->prev;

	}
	pii res = p->data;
	free(p);
	return res;
}

int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &board[i][j]);
		}
	}

	init_deque();

	add_rear((pii) { 1, 1, 0 });
	dis[1][1][0] = 1;
	int cur_z = 0;
	while (!is_empty()) {
		pii cur = del_front();
		
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			int nz = cur.z;
			if (cur.x == n && cur.y == m) {
				break;
			}
			if (nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
			if (board[nx][ny]) {
				if (nz == 0) {
					nz = 1;
					dis[nx][ny][nz] = dis[cur.x][cur.y][cur.z] + 1;
					add_rear((pii) { nx, ny, nz });
				}
			}
			else {
				if (dis[nx][ny][nz] == 0) {

					dis[nx][ny][nz] = dis[cur.x][cur.y][cur.z] + 1;
					add_rear((pii) { nx, ny, nz });
				}
			}
		}

	}

	int ans0 = dis[n][m][0];
	int ans1 = dis[n][m][1];

	if (ans0 == 0 && ans1 == 0) {
		printf("-1");
	}
	else if (ans0 == 0) {
		printf("%d", ans1);
	}
	else if (ans1 == 0) {
		printf("%d", ans0);
	}
	else {
		printf("%d", ans0 < ans1 ? ans0 : ans1);
	}

	return 0;
}
