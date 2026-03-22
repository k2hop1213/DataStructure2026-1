#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 10005

int board[105][105];
int vis[105][105];
int dist[105][105];
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

typedef struct {
	int x;
	int y;
}pii;

pii deque[SZ];
int front, rear;

int isEmpty() { return front == rear; }
int isFull() { return (rear + 1) % SZ == front; }

void push_front(pii a) {
	if (isFull())return;
	deque[front] = a;
	front = (front - 1 + SZ) % SZ;
}
void push_back(pii a) {
	if (isFull())return;
	rear = (rear + 1) % SZ;
	deque[rear] = a;
}

pii pop_front() {
	if (isEmpty()) {

	}
	front = (front + 1) % SZ;
	return deque[front];
}

pii pop_back() {
	if (isEmpty()) {
		
	}
	int t = rear;
	rear = (rear - 1 + SZ) % SZ;
	return deque[t];
}


int main() {

	int n, m;
	scanf("%d %d", &n, &m);
	
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &board[i][j]);
		}
	}
	pii a = { 1,1 };
	vis[1][1] = 1;
	push_back(a);
	dist[1][1] = 1;
	while (!isEmpty()) {
		pii cur = pop_front();

		if (cur.x == n && cur.y == m)break;


		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if (nx <= 0 || nx > n || ny <= 0 || ny > m)continue;
			if (board[nx][ny] == 0 || vis[nx][ny])continue;
			dist[nx][ny] = dist[cur.x][cur.y] + 1;
			vis[nx][ny] = 1;
			pii next = { nx,ny };
			push_back(next);

		}



	}

	printf("%d", dist[n][m]);



	return 0;
}
