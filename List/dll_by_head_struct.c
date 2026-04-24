#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
	struct node* prev;
}node;

node head = { 0,NULL,NULL };

node* alloc_node(int _data) {
	node* p = malloc(sizeof(node));
	p->data = _data;
	p->next = NULL;
	p->prev = NULL;
	return p;
}

int free_node(node* p) {
	int res = p->data;
	free(p);
	return res;
}

node* get_node(int pos) {
	node* p = &head;

	for (int i = 0; i <= pos; i++, p = p->next)
		if (p == NULL) return NULL;
	return p;
}

void insert(int a, int pos) {
	node* before = get_node(pos - 1);
	if (before == NULL) return;
	node* p = alloc_node(a);

	p->next = before->next;
	p->prev = before;
	before->next = p;
	if (p->next != NULL)
		p->next->prev = p;
}

int del_node(int pos) {
	node* p = get_node(pos);

	if (pos < 0 || p == NULL)
		return -999;
	
	if (p->prev != NULL)
		p->prev->next = p->next;
	if (p->next != NULL)
		p->next->prev = p->prev;

	return free_node(p);

}

void print_list() {
	node* temp = head.next;
	while (temp != NULL) {
		printf("%d ", temp->data);
		temp = temp->next;
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
	del_node(3);
	print_list();

	return 0;
}
