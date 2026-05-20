#include <stdio.h>
#include <stdlib.h>
#define QUEUE_SIZE 101
#define BUCKETS 10
#define DIGITS 4

typedef struct {
	int q[QUEUE_SIZE];
	int rear;
	int front;
}Queue;

void init_queue(Queue* Q) {
	Q->rear = Q->front = 0;
}

void enqueue(Queue* Q, int data) {
	Q->rear = (Q->rear + 1) % QUEUE_SIZE;
	Q->q[Q->rear] = data;
}

int is_empty(Queue* Q) {
	return Q->rear == Q->front;
}

int dequeue(Queue* Q) {
	Q->front = (Q->front + 1) % QUEUE_SIZE;
	return Q->q[Q->front];
}

void radix_sort(int A[], int n) {
	Queue queues[BUCKETS];
	for (int b = 0; b < BUCKETS; b++)
		init_queue(&queues[b]);

	int factor = 1;
	for (int d = 0; d < DIGITS; d++) {
		for (int i = 0; i < n; i++) {
			int id = (A[i] / factor) % BUCKETS;
			enqueue(&queues[id], A[i]);
		}
		int i = 0;
		for (int b = 0; b < BUCKETS; b++)
			while (!is_empty(&queues[b]))
				A[i++] = dequeue(&queues[b]);
		factor *= BUCKETS;
		print_step(A, n, d + 1);
	}
}

int main() {
	int list[10] = { 7792, 2104, 7009, 2001, 7116, 6099, 7971, 1912, 4846, 8929 };
	radix_sort(list, 10);

	return 0;
}
