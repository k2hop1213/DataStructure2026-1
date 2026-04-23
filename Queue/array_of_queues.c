//BOJ 28107
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define SZ 200001

typedef struct node {
	int data;
	struct node* next;
}node;

typedef struct {
	node* front;
	node* rear;
}queue;

queue q[SZ];

void init_queue(queue* q) {
	q->front = NULL;
	q->rear = NULL;
}
node* alloc_node(int n) {
	node* new_node = malloc(sizeof(node));
	new_node->data = n;
	new_node->next = NULL;
	return new_node;
}
int isEmpty(queue* q) {
	return (q->front == NULL) && (q->rear == NULL);

}

void enqueue(queue* q,node* a) {
	if (q->rear == NULL) {
		q->rear = a;
		q->front = a;
		return;
	}
	q->rear->next = a;
	q->rear = a;
}

int dequeue(queue* q) {
	if (isEmpty(q))return 0;
	int res = q->front->data;
	node* temp = q->front;
	q->front = q->front->next;
	if (q->front == NULL) {
        q->rear = NULL;
    }
	free(temp);
	return res;
}



int main() {
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 0; i < SZ; i++) {
		init_queue(&q[i]);
	}
	for (int i = 0; i < n; i++) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; j++) {
			int ak;
			scanf("%d", &ak);
			node* a = alloc_node(i + 1);
			enqueue(&q[ak], a);
		}

	}
	int* res = calloc(n + 1, sizeof(int));
	for (int i = 0; i < m; i++) {
		int t;
		scanf("%d", &t);
		res[dequeue(&q[t])]++;
		
	}

	for (int i = 1; i <= n; i++)printf("%d ", res[i]);


	return 0;
}
