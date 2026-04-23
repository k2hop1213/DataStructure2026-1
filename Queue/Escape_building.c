#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
char board[32][32][32];
int vis[32][32][32];
int sec[32][32][32];
int dx[6] = { 1,0,0,-1,0,0 };
int dy[6] = { 0,1,0,0,-1,0 };
int dz[6] = { 0,0,1,0,0,-1 };
typedef struct {
	int x;
	int y;
	int z;
}tiii;

typedef struct node {
	tiii a;
	struct node* next;
}node;

node* front = NULL;
node* rear = NULL;

node* alloc_node(tiii t) {
	node* p = malloc(sizeof(node));
	p->a = t;
	p->next = NULL;
	return p;
}

void init_queue() {
	front = rear = NULL;
}

int is_empty() {
	return front == NULL;
}

void enqueue(tiii a) {
	node* p = alloc_node(a);
	if (is_empty()) {
		front = rear = p;
	}
	else {
		rear->next = p;
		rear = p;
	}

}

tiii dequeue() {
	if (is_empty()) return (tiii) { -1, -1, -1 };

	node* temp = front;
	tiii res = front->a;
	if (front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
	}
	free(temp);
	return res;
}

int main() {
	while (1) {
		int n, m, l;
		scanf("%d %d %d", &n, &m, &l);
		if (n == 0 && m == 0 && l == 0) return 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%s", &board[i][j]);
			}
		}

		for (int i = 0; i < 31; i++) {
			for (int j = 0; j < 31; j++) {
				for (int k = 0; k < 31; k++) {
					sec[i][j][k] = 0;
					vis[i][j][k] = 0;
				}
			}
		}
		init_queue();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				for (int k = 0; k < l; k++) {
					if (board[i][j][k] == 'S') {
						enqueue((tiii) { i, j, k });
						vis[i][j][k] = 1;
						break;
					}
				}
			}
		}
		int flag = 0;
		while (!is_empty()) {
			tiii cur = dequeue();
			if (board[cur.x][cur.y][cur.z] == 'E') { 
				
				printf("Escaped in %d minute(s).\n", sec[cur.x][cur.y][cur.z]);
				flag = 1;

				break; 
			
			}
			for (int dir = 0; dir < 6; dir++) {
				int nx = cur.x + dx[dir];
				int ny = cur.y + dy[dir];
				int nz = cur.z + dz[dir];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= l)continue;
				if (vis[nx][ny][nz] || board[nx][ny][nz] == '#') continue;
				vis[nx][ny][nz] = 1;
				sec[nx][ny][nz] = sec[cur.x][cur.y][cur.z] + 1;
				enqueue((tiii) { nx, ny, nz });
			}

		}

		if (flag == 0) {
			printf("Trapped!\n");
		}
	}


	return 0;
}
