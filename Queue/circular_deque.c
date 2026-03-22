#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SZ 10
//push_back과 pop_back만 사용하면 stack
//push_back와 pop_front만 사용하면 queue

int deque[SZ];
int front, rear;

int isEmpty() { return front == rear; }
int isFull() { return (rear + 1) % SZ == front; }

void push_front(int a) {
	if (isFull())return;
	deque[front] = a;
	front = (front - 1 + SZ) % SZ;
}
void push_back(int a) {
	if (isFull())return;
	rear = (rear + 1) % SZ;
	deque[rear] = a;
}

int pop_front() {
	if (isEmpty()) {
		return -999;
	}
	front = (front + 1) % SZ;
	return deque[front];
}

int pop_back() {
	if (isEmpty()) {
		return -999;
	}
	int t = rear;
	rear = (rear - 1 + SZ) % SZ;
	return deque[t];
}

void printDeque() {
	while (!isEmpty()) {
		printf("%d ", pop_front());
	}
	printf("\n");
}

int main() {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		push_back(t);
	}
	printDeque();


	return 0;
}
