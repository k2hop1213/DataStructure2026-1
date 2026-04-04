#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node;

node* front;
node* rear;

int is_emtpy() {
	return front == NULL;
}

node* alloc_node(int _data) {
	node* temp = malloc(sizeof(node));
	temp->data = _data;
	temp->next = NULL;
	return temp;
}

void enqueue(node* a) {
	if (front == NULL) {
		front = rear = a;

	}
	else {
		rear->next = a;
		rear = a;
	}
}

int dequeue() {
	if (is_emtpy()) return 0;
	node* temp = front;
	int a = front->data;
	if (front == rear) {
		front = rear = NULL;
	}
	else {
		front = front->next;
	}
	free(temp);
	return a;
}

int main() {

	int n;
	scanf("%d", &n);//n번째 피보나치 수를 출력 (n>=2)
	node* f0 = alloc_node(0);
	node* f1 = alloc_node(1);
	enqueue(f0);
	enqueue(f1);

	for (int i = 0; i < n; i++) {
		int a1 = dequeue();
		int a2 = front->data;
		node* a3 = alloc_node(a1 + a2);
		enqueue(a3);
	}

	printf("%d", front->data);

	return 0;
}
