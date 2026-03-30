#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node* next;
}node;

node head;//head를 포인터가 아니라 구조체 변수로 선언

node* alloc_node(int _data) {
	node* newNode = malloc(sizeof(node));
	newNode->data = _data;
	newNode->next = NULL;
	return newNode;
}

node* get_node(int pos) {
	if (pos < -1)return NULL;
	if (pos == -1) return &head;
	node* temp = head.next;
	for (int i = 0; i < pos; i++, temp = temp->next)
		if (temp == NULL)return NULL;
	return temp;

}

void insert(int pos, int n) {
	node* p = alloc_node(n);
	
	node* before = get_node(pos - 1);
	if (before == NULL) return;
	p->next = before->next;
	before->next = p;
}

int delete(int pos) {
	node* before = get_node(pos - 1);

	if (before == NULL || before->next == NULL) {
		return 0;
	}
	node* cur = before->next;
	int res = cur->data;

	before->next = cur->next;
	free(cur);
	return res;
}
void print_list(char* msg)
{
	printf("단순연결리스트 %s: ", msg);
	for (node* p = head.next; p != NULL; p = p->next)
		printf("%2d ", p->data);
	printf("\n");
}
int main() {

	head.next = NULL;

	insert(0, 10); 
	insert(0, 20); 
	insert(1, 30); 
	insert(2, 50);
	print_list("(삽입x4)");

	delete(2); 
	delete(0);
	print_list("(삭제x2)");


	return 0;
}
