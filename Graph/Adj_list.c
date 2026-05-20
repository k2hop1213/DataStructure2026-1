#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define MAX_VSIZE 100
typedef struct GNode {
	int id;
	struct GNode* link;
}GNode;

int vsize = 5;
char vdata[5] = { 'U','V','W','X','Y' };
GNode* adj[5] = { NULL,NULL, NULL, NULL, NULL };

GNode* prepend_node(GNode* head, int v) {
	GNode* n = malloc(sizeof(GNode));
	n->id = v;
	n->link = head;
	return n;
}

void insert_edge(int u, int v) {
	adj[u] = prepend_node(adj[u], v);
	adj[v] = prepend_node(adj[v], u);
}

int degree(int v) {
	int count = 0;
	for (GNode* p = adj[v]; p != NULL; p = p->link)
		count++;
	return count;

}


int main() {
	insert_edge(0, 1);
	insert_edge(0, 2);
	insert_edge(1, 2);
	insert_edge(1, 3);
	insert_edge(2, 4);

	for (int i = 0; i < vsize; i++) {
		printf("정점 %c(차수=%d): ", vdata[i], degree(i));
		for (GNode* p = adj[i]; p!=NULL; p = p->link)
			printf(" %c", vdata[p->id]);
		printf("\n");
	}

	return 0;
}
