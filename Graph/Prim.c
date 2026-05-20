#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VSIZE 100   // 최대 정점 수
typedef char VElement;  // 정점의 자료형 정의
#define INF 9999        // 무한대. 가중치가 INF이면 간선이 없는 것으로 처리
#define InsertVtx(i) (printf("%c ", vdata[i])) // 정점 i를 MST에 추가하는 함수

int vsize = 7;
VElement vdata[MAX_VSIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };

int adj[MAX_VSIZE][MAX_VSIZE] = {
	{ 0, 25, INF, 12, INF, INF, INF },
	{ 25, 0, 10, INF, 15, INF, INF },
	{ INF, 10, 0, INF, INF, INF, 16 },
	{ 12, INF, INF, 0, 17, 37, INF },
	{ INF, 15, INF, 17, 0, 19, 14 },
	{ INF, INF, INF, 37, 19, 0, 42 },
	{ INF, INF, 16, INF, 14, 42, 0 }
};
int selected[MAX_VSIZE]; // MST 포함 여부
int dist[MAX_VSIZE]; // MST와의 최단 거리

int getMinVertex() {
	int minv = 0, mindist = INF;
	for (int v = 0; v < vsize; v++) {
		if (!selected[v] && dist[v] < mindist) {
			mindist = dist[v];
			minv = v;
		}
	}
	return minv;
}

void Prim() {
	for (int i = 0; i < vsize; i++) {
		dist[i] = INF;
		selected[i] = 0;
	}
	dist[0] = 0;

	for (int i = 0; i < vsize; i++) {
		int v = getMinVertex(); //최소 경로를 찾고 그 경로를 선택함
		selected[v] = 1;
		if (dist[v] == INF) // 최소 비용 신장 트리를 만들 수 없는 경우
			return;
		InsertVtx(v);
		for (int w = 0; w < vsize; w++) {
			if (!selected[w]) // 선택되지 않았다면
				if (adj[v][w] < dist[w])
					/*
					연결되있지 않은 간선의 가중치는 INF로 저장되어있고 dist 배열의 초기값도 INF 이다
					즉 연결되있지 않은건 자동으로 걸러지고 연결되있는 곳의 가중치중 현재 dist에 있는 값보다 작은 것들만
					dist 배열에 저장해놨다가 getMinVertex 함수에서 최솟값 찾음
					adj[v][w]: v에서 w로 가는 비용
					dist[w]: 예전에 탐색했던 곳중 w로 가는 가장 적은 비용
					*/
					dist[w] = adj[v][w];
		}
	}
	printf("\n");

}


int main() {
	printf("MST By Prim's Algorithm\n");
	Prim();

	return 0;
}
