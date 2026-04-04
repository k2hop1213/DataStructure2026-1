#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
	struct node* prev;

}node;

node* head;

node* alloc_node(int _data){
	node* p = malloc(sizeof(node));
	p->data = _data;
	p->next = NULL;
	p->prev = NULL;
	return p;
}

node* get_node(int pos) {

	if (pos < 0) return NULL;
	node* p = head;
	for (int i = 0; i < pos; i++, p = p->next)
		if (p == NULL) return NULL; //pos가 범위 밖일 경우

	return p;

}

int size() {
	node* p = head;
	int sz = 0;
	while (p != NULL) {
		p = p->next;
		sz++;
	}
	return sz;
}

void insert(int pos, int num) {

	if (pos < 0) return;

	node* p1 = alloc_node(num);

	if (pos == 0) {
		p1->next = head;
		if (head != NULL) {
			head->prev = p1;
		}
		head = p1;
		return;
	}
	node* p = get_node(pos - 1);

	if (p == NULL) {
		free(p1);
		return;
	}

	p1->next = p->next;
	p1->prev = p;

	if (p->next != NULL)
		p->next->prev = p1;
	p->next = p1;
}

int delete(int pos) {
	
	node* p = get_node(pos);
	if (p == NULL)return 0;
	if (pos == 0) {
		head = head->next;
		if (head != NULL) {
			head->prev = NULL; // 새로운 head의 prev를 NULL로 초기화
		}
	}
	else {

		p->prev->next = p->next;
		if (p->next != NULL)p->next->prev = p->prev;
	}

	int res = p->data;
	free(p);
	return res;
}


// 리스트 상태를 시각적으로 확인하기 위한 헬퍼 함수
void print_list() {
	node* p = head;
	printf("List: ");
	while (p != NULL) {
		printf("%d <-> ", p->data);
		p = p->next;
	}
	printf("NULL (Size: %d)\n", size());
}

int main() {
	insert(0, 10); // 인덱스 0에 10 삽입 (List: 10)
	insert(1, 20); // 인덱스 1에 20 삽입 (List: 10 <-> 20)
	insert(0, 5);  // 인덱스 0에 5 삽입  (List: 5 <-> 10 <-> 20)
	insert(3, 30); // 인덱스 3에 30 삽입 (List: 5 <-> 10 <-> 20 <-> 30)

	print_list();

	printf("Deleted: %d\n", delete(0)); // 5 삭제
	print_list();

	printf("Deleted: %d\n", delete(2)); // 30 삭제
	print_list();

	return 0;
}
