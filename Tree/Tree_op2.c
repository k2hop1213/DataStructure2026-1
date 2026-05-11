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
int path_length_helper(TNode* root, int level) {
	if (root == NULL)
		return 0;

	return level + path_length_helper(root->left, level + 1) + path_length_helper(root->right, level + 1);
}

int path_length_all(TNode* root) {

	return path_length_helper(root, 0);
}


TNode* create_node(int data, TNode* left, TNode* right) {
	TNode* new_node = (TNode*)malloc(sizeof(TNode));
	new_node->data = data;
	new_node->left = left;
	new_node->right = right;
	return new_node;
}

void free_tree(TNode* root) {
	if (root == NULL) return;
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}

void run_test(TNode* root, const char* tree_name) {
	printf("=== [%s] ===\n", tree_name);

	init_queue();

	printf("1. 포화 이진 트리(Full)   : %s\n", is_full_tree(root) ? "O (Yes)" : "X (No)");
	printf("2. 완전 이진 트리(Complete): %s\n", is_complete_tree(root) ? "O (Yes)" : "X (No)");
	printf("3. 균형 이진 트리(Balanced): %s\n", is_balanced_tree(root) ? "O (Yes)" : "X (No)");
	printf("4. 모든 경로의 길이 합     : %d\n\n", path_length_all(root));
}

int main() {
	/*
	   [트리 1] 포화 이진 트리 (Perfect Binary Tree)
			 1
		   /   \
		  2     3
		 / \   / \
		4   5 6   7
	*/
	TNode* tree1 = create_node(1,
		create_node(2, create_node(4, NULL, NULL), create_node(5, NULL, NULL)),
		create_node(3, create_node(6, NULL, NULL), create_node(7, NULL, NULL))
	);
	run_test(tree1, "트리 1: 포화 이진 트리");

	/*
	   [트리 2] 완전 이진 트리 (Complete Binary Tree) - 포화 트리는 아님
			 1
		   /   \
		  2     3
		 / \   /
		4   5 6  (7이 빠짐)
	*/
	TNode* tree2 = create_node(1,
		create_node(2, create_node(4, NULL, NULL), create_node(5, NULL, NULL)),
		create_node(3, create_node(6, NULL, NULL), NULL)
	);
	run_test(tree2, "트리 2: 완전 이진 트리 (포화X)");

	/*
	   [트리 3] 균형 이진 트리 (Balanced Binary Tree) - 완전/포화 트리는 아님
			 1
		   /   \
		  2     3
		 /       \
		4         7
	*/
	TNode* tree3 = create_node(1,
		create_node(2, create_node(4, NULL, NULL), NULL),
		create_node(3, NULL, create_node(7, NULL, NULL))
	);
	run_test(tree3, "트리 3: 균형 이진 트리 (완전X, 포화X)");

	/*
	   [트리 4] 불균형 트리 (Unbalanced Binary Tree) - 왼쪽으로 치우침
			 1
		   /
		  2
		 /
		4
	*/
	TNode* tree4 = create_node(1,
		create_node(2, create_node(4, NULL, NULL), NULL),
		NULL
	);
	run_test(tree4, "트리 4: 불균형 이진 트리");

	// 동적 할당 메모리 해제
	free_tree(tree1);
	free_tree(tree2);
	free_tree(tree3);
	free_tree(tree4);

	return 0;
}
