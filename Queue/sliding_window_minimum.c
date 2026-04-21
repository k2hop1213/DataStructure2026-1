#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int x;
	int y;
}pii;

typedef struct node {
	pii data;
	struct node* prev;
	struct node* next;
}node;

node* front;
node* rear;

int is_empty() {
	return front == NULL;
}

node* alloc_node(pii a) {
	node* p = malloc(sizeof(node));
	p->data = a;
	p->prev = NULL;
	p->next = NULL;
	return p;
}

pii free_node(node* p) {
	pii res = p->data;
	free(p);
	return res;
}

void add_front(pii a) {
	node* p = alloc_node(a);
	if (front == NULL) {
		front = rear = p;
	}
	else {
		p->next = front;
		front->prev = p;
		front = p;
	}
}

void add_rear(pii a) {
	node* p = alloc_node(a);
	if (front == NULL) {
		front = rear = p;
	}
	else {
		p->prev = rear;
		rear->next = p;
		rear = p;
	}
}

pii del_front() {
	if (front == NULL) return (pii){ -1, -1 };

	if (front == rear) {
		front = rear = NULL;
	}
	else {
		node* t = front;
		front = front->next;
		return free_node(t);
	}
	
	
}

pii del_rear() {
	if (front == NULL) return (pii){ -1, -1 };
	if (front == rear) {
		front = rear = NULL;
	}
	else {
		node* t = rear;
		rear = rear->prev;
		return free_node(t);
	}

}


int main() {

	int N, L;
	scanf("%d %d", &N, &L);

	for (int i = 0; i < N; i++) {
		int t;
		scanf("%d", &t);
		while (!is_empty() && rear->data.x >= t) del_rear();
		add_rear((pii) { t, i });
		if (front->data.y <= (i - L)) del_front();
		printf("%d ", front->data.x);
	}

	return 0;
}
