#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_VSIZE	100	
typedef char VElement;	
#define PrintVtx(i)		(printf("%c  ", vdata[i]))
#define INF		9999

int vsize = 7;
VElement vdata[MAX_VSIZE] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G' };
int adj[MAX_VSIZE][MAX_VSIZE] = {
	{   0,  29, INF, INF, INF,  10, INF },
	{  29,   0,  16, INF, INF, INF,  15 },
	{ INF,  16,   0,  12, INF, INF, INF },
	{ INF, INF,  12,   0,  22, INF,  18 },
	{ INF, INF, INF,  22,   0,  27,  25 },
	{  10, INF, INF, INF,  27,   0, INF },
	{ INF,  15, INF,  18,  25, INF,   0 }
};

int parent[MAX_VSIZE];
int set_size;

void init_set(int nSets) {
	set_size = nSets;
	for (int i = 0; i < nSets; i++)
		parent[i] = -1;
}

int find_set(int id) {
	while (parent[id] >= 0) id = parent[id];
	return id;
}

void union_set(int s1, int s2) {
	parent[s1] = s2;
	set_size--;
}

#define MAX_HSIZE 100
struct HeapNode {
	int key;
	int v1;
	int v2;
};

typedef struct HeapNode HNode;
#define Compare(n1,n2) ((n2.key) - (n1.key))

HNode A[MAX_HSIZE];
int heap_size;

void init_heap() { heap_size = 0; }
int is_empty() { return heap_size == 0; }
int is_full() { return heap_size == MAX_HSIZE - 1; }

void heap_push(HNode n) {
	if (is_full())
		return;

	heap_size++;
	int i = heap_size;

	while (i != 1) {
		if (n.key < A[i / 2].key) {
			A[i] = A[i / 2];
			i = i / 2;
		}
		else break;
	}
	A[i] = n;
}

HNode heap_pop() {
	if (is_empty()) {
		return (HNode) { -1, -1, -1 };
	}

	HNode root = A[1];
	HNode last = A[heap_size];
	heap_size--;

	int i = 1;
	while (i * 2 <= heap_size) {
		int child = i * 2;

		if (child + 1 <= heap_size && A[child + 1].key < A[child].key) {
			child++;
		}

		if (last.key <= A[child].key) break;

		A[i] = A[child];
		i = child;
	}
	A[i] = last;

	return root;
}

void Kruskal() {
	init_set(vsize);

	init_heap();
	for (int i = 0; i < vsize - 1; i++) {
		for (int j = i + 1; j < vsize; j++) {
			if (adj[i][j] > 0 && adj[i][j] < INF) {
				HNode e;
				e.key = adj[i][j];
				e.v1 = i;
				e.v2 = j;
				heap_push(e);
			}
		}
	}
	int edgeAccepted = 0;
	while (edgeAccepted < vsize - 1) {
		HNode e = heap_pop();
		int uset = find_set(e.v1);
		int vset = find_set(e.v2);
		if (uset != vset) {
			printf("간선 추가 : %c - %c (비용:%d)\n", vdata[e.v1], vdata[e.v2], e.key);
			union_set(uset, vset);
			edgeAccepted++;

		}
		else {
			printf("간선 무시: %c - %c\n", vdata[e.v1], vdata[e.v2]);
		}
	}
}

int main() {

	printf("MST By Kruskal's Algorithm\n");
	Kruskal();
	return 0;
}
