#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct HTNode {
	int data;
	struct HTNode* parent;
	struct HTNode* left;
	struct HTNode* right;
}HTNode;

typedef struct {
	int size;
	HTNode* root;
}Heap;

HTNode* create_node(int d, HTNode* p) {
	HTNode* n = malloc(sizeof(HTNode));
	n->data = d;
	n->left = NULL;
	n->right = NULL;
	n->parent = p;
	return n;
}

HTNode* find(Heap* h, int index) {
	if (index == 1) return h->root;

	HTNode* parent = find(h, index / 2);
	if (index % 2 == 0) return parent->left;
	else return parent->right;

}

void heap_push(Heap* h, int data) {
	h->size++;
	if (h->root == NULL) {
		h->root = create_node(data, NULL);
		return;
	}

	HTNode* parent = find(h, h->size / 2);
	HTNode* n = create_node(data, parent);

	if (h->size % 2 == 0) parent->left = n;
	else parent->right = n;

	HTNode* cur = n;
	while (cur->parent != NULL) {
		if (cur->data > cur->parent->data) {
			cur->data = cur->parent->data;
			cur->parent->data = data;
			cur = cur->parent;
		}
		else break;
	}

}

int heap_pop(Heap* h) {
	if (h->size == 0) return -1;
	int res = h->root->data;
	if (h->size == 1) {
		free(h->root);
		h->root = NULL;
		h->size = 0;
		return res;
	}
	HTNode* last = find(h, h->size);
	HTNode* cur = h->root;
	h->root->data = last->data;

	if (h->size % 2 == 0) last->parent->left = NULL;
	else last->parent->right = NULL;
	free(last);
	h->size--;

	while (cur->left != NULL) { //자식이 하나라도 존재하는지 확인
		HTNode* child = cur->left;

		if (cur->right != NULL && cur->right->data > cur->left->data) {
			child = cur->right;
		}

		if (child->data < cur->data) break;

		int temp = cur->data;
		cur->data = child->data;
		child->data = temp;

		cur = child;

	}
	return res;

}

int main() {
	// 1. Heap 초기화
	Heap h;
	h.size = 0;
	h.root = NULL;

	// 2. 힙에 데이터 삽입 (Max Heap 테스트)
	printf("데이터 삽입: 15, 10, 30, 20, 5, 40\n");
	heap_push(&h, 15);
	heap_push(&h, 10);
	heap_push(&h, 30);
	heap_push(&h, 20);
	heap_push(&h, 5);
	heap_push(&h, 40);

	// 3. 힙에서 데이터 추출 및 출력
	// Max Heap이므로 가장 큰 수부터 내림차순으로 정렬되어 출력되어야 합니다.
	printf("데이터 추출: ");
	while (h.size > 0) {
		printf("%d ", heap_pop(&h));
	}
	printf("\n");

	return 0;
}
