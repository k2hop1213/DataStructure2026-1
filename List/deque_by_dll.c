#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
	struct node* prev;
}node;

node* front;
node* rear;

node* alloc_node(int _data) {
	node* p = malloc(sizeof(node));
	p->data = _data;
	p->next = NULL;
	p->prev = NULL;
	return p;
}

void add_front(int n) {
	node* temp = alloc_node(n);
	if (front == NULL) {
		front = rear = temp;

	}
	else {
		temp->next = front;
		front->prev = temp;
		front = temp;
	}
}

void add_rear(int n) {
	node* temp = alloc_node(n);
	if (front == NULL) {
		front = rear = temp;
	}
	else {
		temp->prev = rear;
		rear->next = temp;
		rear = temp;
	}

}

int del_front() {

	if (front == NULL) return 0;

	node* temp = front;
	if (front == rear)      
		front = rear = NULL;
	else {                 
		front = front->next;  
		front->prev = NULL;
	}
	int res = temp->data;
	free(temp);
	return res;

}
int del_rear() {

	if (front == NULL) return 0;

	node* temp = rear;
	if (front == rear)      
		front = rear = NULL;
	else {                  
		rear = rear->prev;  
		rear->next = NULL;
	}

	int res = temp->data;
	free(temp);
	return res;

}


int main() {
	// 1. 뒤로 데이터 삽입: [10] -> [20]
	add_rear(10);
	add_rear(20);
	printf("뒤에 10, 20 삽입 후...\n");

	// 2. 앞으로 데이터 삽입: [30] -> [10] -> [20]
	add_front(30);
	printf("앞에 30 삽입 후...\n");

	// 3. 현재 상태 확인 (앞에서부터 삭제하며 출력)
	// 예상 순서: 30, 10, 20
	printf("앞에서 삭제하며 출력: %d\n", del_front()); // 30
	printf("뒤에서 삭제하며 출력: %d\n", del_rear());  // 20
	printf("앞에서 삭제하며 출력: %d\n", del_front()); // 10

	// 4. 비어있는 상태에서 삭제 시도
	printf("빈 데크에서 삭제 시도: %d\n", del_front()); // 0

	return 0;
}
