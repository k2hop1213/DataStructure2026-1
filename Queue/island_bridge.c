#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
/*
10 10
1110000111
1111000011
1011000011
0011100001
0001000001
0000000001
0000000000
0000110000
0000111000
0000000000

*/
int board[105][105];
int Gajang_Jari[105][105];
int vis[105][105];
int dist[105][105];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

typedef struct {
	int x;
	int y;
}pii;

typedef struct node {
	pii data;
	struct node* next;
}node;

node* front = NULL;
node* rear = NULL;

void init_queue() {
	front = rear = NULL;

}

node* alloc_node(pii a) {
	node* p = malloc(sizeof(node));
	p->data = a;
	p->next = NULL;
	return p;
}

int is_empty() { return front == NULL; }

void enqueue(pii a) {
	node* p = alloc_node(a);
	if (is_empty()) {
		front = rear = p;
	}
	else {
		rear->next = p;
		rear = p;
	}

}

pii dequeue() {

	if (is_empty())return (pii) { -1, -1 };

	pii res = front->data;
	node* temp = front;
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
	int n,m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%1d", &board[i][j]);
		}
	}
	int cnt = 0;
	while (1) { // 영역 개수 count + 테두리 따기
		
		int flag = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (vis[i][j] == 0 && board[i][j]) {
					enqueue((pii) { i, j });
					vis[i][j] = 1;
					flag = 1;
					cnt++;
					int temp = 0;
					for (int dir = 0; dir < 4; dir++) {
						int x1 = i + dx[dir];
						int y1 = j + dy[dir];
						if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m)continue;
						if (board[x1][y1]) {
							temp++;
						}
					}
					if (temp != 4) {
						Gajang_Jari[i][j] = cnt;
					}
					break;
				}
			}
			if (flag == 1) break;
		}
		if (flag == 0) break;

		while (!is_empty()) {
			pii cur = dequeue();
			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
				if (vis[nx][ny] || board[nx][ny] == 0) continue;
				enqueue((pii) { nx, ny });
				int temp = 0;
				for (int dir = 0; dir < 4; dir++) {
					int x1 = nx + dx[dir];
					int y1 = ny + dy[dir];
					if (x1 < 0 || x1 >= n || y1 < 0 || y1 >= m)continue;
					if (board[x1][y1]) {
						temp++;
					}
				}
				if (temp != 4) {
					Gajang_Jari[nx][ny] = cnt;
				}
				vis[nx][ny] = 1;
			}
		}

	}
	

	int res = n * m;
	pii end = { -1,-1 };
	for (int i = 1; i <= cnt; i++) {
		init_queue();
		
		for (int j = 0; j < 101; j++) {
			for (int k = 0; k < 101; k++) {
				vis[j][k] = 0;
				dist[j][k] = 0;
			}
		}
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (Gajang_Jari[j][k] == i) {
					enqueue((pii) { j, k });
					vis[j][k] = 1;
				}
			}
		}
		
		while (!is_empty()) {
			pii cur = dequeue();

			for (int i = 0; i < 4; i++) {
				int nx = cur.x + dx[i];
				int ny = cur.y + dy[i];
				if (nx < 0 || nx >= n || ny < 0 || ny >= m)continue;
				if (vis[nx][ny] || Gajang_Jari[nx][ny] == i) continue;
				if (Gajang_Jari[nx][ny] != i && Gajang_Jari[nx][ny] > 0) {
					
					if (res > dist[cur.x][cur.y]) {
						res = dist[cur.x][cur.y];
						end = cur;
						break;
					}
				}
				enqueue((pii) { nx, ny });
				vis[nx][ny] = 1;
				dist[nx][ny] = dist[cur.x][cur.y] + 1;
			}
		}
	}

	if (res != n * m) { 
		printf("%d", dist[end.x][end.y]); 
	}
	else printf("실패요");

	return 0;
}
