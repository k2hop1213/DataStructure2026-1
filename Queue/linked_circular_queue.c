#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int Element;

typedef struct node {
	Element data;
	struct node* next;
} node;

typedef struct {
	node* rear;
} queue;


void init_queue(queue* q) { q->rear = NULL; }
int is_empty(queue* q) { return q->rear == NULL; }

node* alloc_node(Element n) {
	node* temp = (node*)malloc(sizeof(node));
	temp->data = n;
	temp->next = NULL;
	return temp;
}

void enqueue(queue* q, Element n) {
	node* p = alloc_node(n);
	if (is_empty(q)) {
		q->rear = p;
		p->next = p;
	}
	else {
		p->next = q->rear->next;
		q->rear->next = p;
		q->rear = p;
	}
}

Element dequeue(queue* q) {
	if (is_empty(q)) return -1;
	node* front = q->rear->next;
	Element res = front->data;
	if (q->rear == front) q->rear = NULL;
	else q->rear->next = front->next;
	free(front);
	return res;
}

void print_queue(queue* q) {
	if (is_empty(q)) {
		printf("Queue is empty.\n");
		return;
	}
	node* curr = q->rear->next;
	printf("[ ");
	do {
		printf("%d ", curr->data);
		curr = curr->next;
	} while (curr != q->rear->next);
	printf("]\n");
}

int main() {
	queue q;
	init_queue(&q);

	printf("1. 데이터 10, 20, 30 삽입\n");
	enqueue(&q, 10);
	enqueue(&q, 20);
	enqueue(&q, 30);
	print_queue(&q);

	printf("\n2. 데이터 하나 꺼내기(Dequeue): %d\n", dequeue(&q));
	print_queue(&q);

	printf("\n3. 데이터 40 삽입\n");
	enqueue(&q, 40);
	print_queue(&q);

	return 0;
}
