#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct TNode {
	int data;
	struct TNode* left;
	struct TNode* right;
}TNode;
#define MAX_SIZE 100

TNode* queue[MAX_SIZE];
int front = 0;
int rear = 0;

int is_empty() { return front == rear; }
int is_full() { return (rear + 1) % MAX_SIZE == front; }
void init_queue() {
	front = rear = 0;
}
void enqueue(TNode*a) {
	if (is_full()) {

		return;
	}
	rear = (rear + 1) % MAX_SIZE;
	queue[rear] = a;
}

TNode* dequeue() {
	if (is_empty()) {
		return NULL;
	}
	front = (front + 1) % MAX_SIZE;
	return queue[front];
}

void levelorder(TNode* root) {
	if (root != NULL) {
		init_queue();
		enqueue(root);
		while (!is_empty()) {
			TNode* n = dequeue();
			if (n != NULL) {
				printf("%d ", n->data);
				enqueue(n->left);
				enqueue(n->right);
			}
		}

	}


}

int count_node(TNode* n) {
	if (n == NULL)
		return 0;
	else return 1 + count_node(n->left) + count_node(n->right);
}

int calc_level(TNode* n, TNode* key, int level) {
	if (n == NULL)
		return 0;
	if (n == key)
		return level;
	int lev = calc_level(n->left, key, level + 1);
	if (lev > 0)
		return lev;
	return calc_level(n->right, key, level + 1);
}

void reverse(TNode* p) {
	if (p != NULL) {
		TNode* tmp = p->left;
		p->left = p->right;
		p->right = tmp;
		reverse(p->left);
		reverse(p->right);

	}
}
#define MAX(a,b) ((a)>(b) ? (a):(b))

int calc_height(TNode* n) {
	if (n == NULL)
		return 0;
	else return 1 + MAX(calc_height(n->left), calc_height(n->right));
}

int main() {



	return 0;
}
