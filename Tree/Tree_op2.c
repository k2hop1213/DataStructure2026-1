#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct TNode {
	int data;
	struct TNode* left;
	struct TNode* right;
}TNode;

int count_node(TNode* n) {
	if (n == NULL)
		return 0;
	return 1 + count_node(n->left) + count_node(n->right);
}

#define MAX(a,b) ((a)>(b) ? (a):(b))
int calc_height(TNode* n) {
	if (n == NULL)
		return 0;
	return 1 + MAX(calc_height(n->left), calc_height(n->right));
}

int calc_level(TNode* root, TNode* key, int level) {
	if (root == NULL)
		return 0;
	if (root == key)
		return level;
	int lev = calc_level(root->left, key, level + 1);
	if (lev > 0)
		return lev;
	else return calc_level(root->right, key, level + 1);
}

//포화 이진 트리 검사
int is_full_tree(TNode* root) {
	int cnt = count_node(root);
	int height = calc_height(root);
	if ((1 << height) - 1 == cnt)
		return 1;
	else return 0;
}

#define MAX_SIZE 100
TNode* queue[MAX_SIZE];
int front = 0;
int rear = 0;
void init_queue() { front = rear = 0; }
int is_empty() { return front == rear; }
int is_full() { return (rear + 1) % MAX_SIZE == front; }
void enqueue(TNode* t) {
	if (is_full())
		return;
	rear = (rear + 1) % MAX_SIZE;
	queue[rear] = t;
}
TNode* dequeue() {
	if (is_empty())
		return NULL;
	front = (front + 1) % MAX_SIZE;
	return queue[front];
}

//완전 이진 트리 검사
int is_complete_tree(TNode* root) {
	if (root == NULL)
		return 1;

	enqueue(root);
	int flag = 0;
	while (!is_empty()) {
		TNode* cur = dequeue();
		if (cur == NULL) {
			flag = 1;
		}
		else {
			if (flag == 1)
				return 0;
			enqueue(cur->left);
			enqueue(cur->right);
		}
	}
	return 1;
}
//균형 이진 트리 검사
int is_balanced_tree(TNode* root) {
	if (root == NULL)
		return 1;

	int left = calc_height(root->left);
	int right = calc_height(root->right);

	if (left - right < -1 || left - right > 1)
		return 0;

	return is_balanced_tree(root->left) && is_balanced_tree(root->right);
}
//모든 경로의 길이의 구하기
int path_length_all(TNode* root, int level) {
	if (root == NULL)
		return 0;

	return level + path_length_all(root->left, level + 1) + path_length_all(root->right, level + 1);
}
