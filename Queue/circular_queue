#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 10

int queue[SZ];
int front, rear;
int isEmpty() { return front == rear; }
int isFull() { return (rear + 1) % SZ == front; }

void enqueue(int a) {
	if (isFull())return;
	rear = (rear + 1) % SZ;
	queue[rear] = a;
}

int dequeue() {
	if (isEmpty()) return -999;
	return front = (front + 1) % SZ;
}

void printQueue() {
	while (!isEmpty()) {
		printf("%d ", dequeue());
	}
	printf("\n");
}


int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		enqueue(t);
	}
	printQueue();

	return 0;
}
