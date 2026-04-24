#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node;

node* head = NULL;

node* alloc_node(int _data) {
	node* p = malloc(sizeof(node));
	p->data = _data;
	p->next = NULL;
	return p;
}

int free_node(node* p) {
	int a = p->data;
	free(p);
	return a;
}

node* get_node(int pos) {
	if (pos < 0) return NULL;
	node* p = head;
	for (int i = 0; i < pos; i++, p = p->next)
		if (p == NULL) return NULL;

	return p;
}


void insert(int a,int pos) {
	node* p = alloc_node(a);
	if (pos == 0) {
		p->next = head;
		head = p;
		return;
	}

	node* before = get_node(pos - 1);
	if (before == NULL) return;
	
	p->next = before->next;
	before->next = p;

}

int del_node(int pos) {
	if (head == NULL) return -999;

	if (pos == 0) { // 맨 앞 노드 삭제 처리
		node* target = head;
		head = head->next;
		return free_node(target);
	}

	node* before = get_node(pos - 1);
	if (before == NULL || before->next == NULL) return -999;

	node* target = before->next;
	before->next = target->next;
	return free_node(target);
}

void print_list() {
	node* temp = head;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp -> next;
	}
	printf("\n");
}


int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		insert(t, i);
	}

	print_list();



	return 0;
}
