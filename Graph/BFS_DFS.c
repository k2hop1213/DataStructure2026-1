#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VSIZE 100   // 최대 정점 수
typedef char VElement;  // 정점의 자료형 정의

int vsize = 8;          // 그래프의 정점 수
VElement vdata[MAX_VSIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
int adj[MAX_VSIZE][MAX_VSIZE] = {
	{ 0, 1, 1, 0, 0, 0, 0, 0 }, // A
	{ 1, 0, 0, 1, 0, 0, 0, 0 }, // B
	{ 1, 0, 0, 1, 1, 0, 0, 0 }, // C
	{ 0, 1, 1, 0, 0, 1, 0, 0 }, // D
	{ 0, 0, 1, 0, 0, 0, 1, 1 }, // E
	{ 0, 0, 0, 1, 0, 0, 0, 0 }, // F
	{ 0, 0, 0, 0, 1, 0, 0, 1 }, // G
	{ 0, 0, 0, 0, 1, 0, 1, 0 } // H
};

#define PrintVtx(i) (printf("%c ", vdata[i]))

int visited[MAX_VSIZE];
void reset_visited() {
	for (int i = 0; i < vsize; i++)
		visited[i] = 0;
}

void DFS(int v) {
	visited[v] = 1;
	PrintVtx(v);
	for (int u = 0; u < vsize; u++) {
		if (adj[v][u] != 0 && visited[u] == 0)
			DFS(u);
	}
}

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front, rear;

void init_queue() { front = rear = 0; }
int is_empty() { return front == rear; }
int is_full() { return (rear + 1) % MAX_SIZE == front; }
void enqueue(int n) {
	rear = (rear + 1) % MAX_SIZE;
	queue[rear] = n;
}
int dequeue() {
	front = (front + 1) % MAX_SIZE;
	return queue[front];
}

void BFS(int v) {
	init_queue();
	PrintVtx(v);
	visited[v] = 1;
	enqueue(v);
	while (!is_empty()) {
		v = dequeue();
		for (int u = 0; u < vsize; u++) {
			if (adj[v][u] != 0 && visited[u] == 0) {
				PrintVtx(u);
				visited[u] = 1;
				enqueue(u);
			}
		}
	}
}

int main() {

	int s = 0;  // 시작 정점 A

	reset_visited();
	printf("\nDFS(%c출발) ==> ", vdata[s]);
	DFS(s);

	reset_visited();
	printf("\nBFS(%c출발) ==> ", vdata[s]);
	BFS(s);
	printf("\n\n");
	return 0;
}
