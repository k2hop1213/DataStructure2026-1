#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h>
#define SZ 10005
/*

예제 입력 1
4 6
101111
101010
101011
111011

예제 입력 2
7 7
1011111
1110001
1000111
1110100
1010111
1010001
1111111

예제 입력 3
3 3
111
000
111
*/
int board[105][105];//미로를 저장할 배열
int vis[105][105]; //방문 여부를 저장하는 배열
int dist[105][105]; //거리를 저장하는 배열
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

typedef struct {
	int x;
	int y;
}pii;
pii chase[105][105];
pii deque[SZ];//구조체 배열로 원형 데크 구현
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
	else {
		front = (front + 1) % SZ;
		return deque[front];
	}
}

pii pop_back() {
	if (isEmpty()) {

	}
	else {
		int t = rear;
		rear = (rear - 1 + SZ) % SZ;
		return deque[t];
	}
}
void display_maze(int n, int m, int cur_x, int cur_y) {
	system("cls");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (i == cur_x && j == cur_y) printf("Y"); // 현재 위치
			else if (board[i][j] == 0) printf("X");    // 벽
			else if (vis[i][j]) printf(".");           // 방문한 곳
			else printf("0");                          // 빈 길
		}
		printf("\n");
	}
	Sleep(300);
}

int main() {

	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &board[i][j]);
		}
	}
	//시작은 1,1 고정 
	//끝은 n,m 고정
	pii a = { 1,1 };
	pii end = { -1,-1 };
	vis[1][1] = 1;
	chase[1][1] = (pii){ -1,-1 };
	push_back(a);
	dist[1][1] = 1;
	while (!isEmpty()) {
		pii cur = pop_front();

		if (cur.x == n && cur.y == m) { end = cur;  break; } //미로 끝에 도달하였으면 break
		display_maze(n, m, cur.x, cur.y);

		for (int dir = 0; dir < 4; dir++) {
			int nx = cur.x + dx[dir];
			int ny = cur.y + dy[dir];
			if (nx <= 0 || nx > n || ny <= 0 || ny > m)continue;
			if (board[nx][ny] == 0 || vis[nx][ny])continue;
			dist[nx][ny] = dist[cur.x][cur.y] + 1;
			vis[nx][ny] = 1;
			chase[nx][ny] = cur;
			pii next = { nx,ny };
			push_back(next);

		}



	}
	//역추적을 통해 경로를 거꾸로 출력
	if (end.x != -1 && end.y != -1) {
		pii temp = end;
		while (temp.x != -1) {
			printf("(%d ,%d)\n", temp.x, temp.y);
			temp = chase[temp.x][temp.y];
		}
	}
	if (dist[n][m])printf("%d", dist[n][m]);
	else printf("미로탈출 실패!!!!!");

	return 0;
}
