#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define VisitNode(n)(printf("%d ", (n)->data))
#define KEY(n) (n->data)

typedef int TElement;

typedef struct TNode {
	TElement        data;   // 노드에 저장할 자료
	struct TNode* left;   // 왼쪽 서브 트리
	struct TNode* right;  // 오른쪽 서브 트리
} TNode;

TNode* create_tree(TElement data, TNode* left, TNode* right)
{
	TNode* n = (TNode*)malloc(sizeof(TNode));
	n->data = data;
	n->left = left;
	n->right = right;
	return n;
}
void delete_tree(TNode* n)
{
	if (n != NULL) {
		delete_tree(n->left);   // 왼쪽 서브트리 삭제
		delete_tree(n->right);  // 오른쪽 서브트리 삭제
		free(n);                // 현재 노드 삭제
	}
}

TNode* search_bst(TNode* root, int key) {
	if (root == NULL) return NULL;
	if (KEY(root) == key)return root;
	else if (key < KEY(root))
		return search_bst(root->left, key);
	else
		return search_bst(root->right, key);
}

void insert_bst(TNode* root, TNode* n) {
	if (KEY(n) < KEY(root)) {
		if (root->left == NULL) root->left = n;
		else insert_bst(root->left, n);
	}
	else if (KEY(n) > KEY(root)) {
		if (root->right == NULL) root->right = n;
		else insert_bst(root->right, n);
	}
	else free(n);
}

TNode* delete_bst(TNode* root, int key) {
	TNode* n = root;
	TNode* parent = NULL;
	while (n != NULL && key != KEY(n)) {
		parent = n;
		n = (key < KEY(n)) ? n->left : n->right;
	}
	if (n == NULL) return root;

	if ((n->left == NULL) && (n->right == NULL)) {
		if (parent == NULL) root = NULL;
		else {
			if (parent->left == n) parent->left = NULL;
			else parent->right = NULL;
		}
		free(n);
	}
	else if ((n->left == NULL) || (n->right == NULL)) {
		TNode* child = (n->left != NULL) ? n->left: n->right;
		if (n == root) root = child;
		else {
			if (parent->left == n) parent->left = child;
			else parent->right = child;
		}
		free(n);
	}
	else {
		TNode* succ = n->right;
		while (succ->left != NULL)
			succ = succ->left;
		n->data = succ->data;
		n->right = delete_bst(n->right, KEY(succ));
	}
	return root;
}
/*
return root 를 하는 이유:
root가 아닌 노드를 삭제했을시에는 원본에 반영이 되지만 root 노드가 삭제 되었을시에는 반영이 되지 않으므로
root = delete_bst(root, key); 의 형태로 사용하여 root가 삭제되었을때도 원본에 덮어씌워서 반영을 해준다
*/

void preorder(TNode* n) {
	if (n != NULL) {
		VisitNode(n);
		preorder(n->left);
		preorder(n->right);
	}
}

int main() {

	int keys[] = { 35, 18, 7, 26, 12, 3, 68, 22, 30, 99 };

	// 삽입 연산 테스트
	TNode* root = create_tree(keys[0], NULL, NULL);
	for (int i = 1; i < 10; i++) {
		TNode* n = create_tree(keys[i], NULL, NULL);
		insert_bst(root, n);
		printf("\n 삽입 %2d: ", keys[i]);
		preorder(root);
	}
	printf("\n");

	// 탐색 연산 테스트
	TNode* n = search_bst(root, 26);
	printf("26 탐색: %s\n", (n != NULL) ? "성공" : "실패");
	n = search_bst(root, 25);
	printf("25 탐색: %s\n", (n != NULL) ? "성공" : "실패");

	// 삭제 연산 테스트
	root = delete_bst(root, 3);
	printf("\ncase1: < 3> 삭제: ");
	preorder(root);
	root = delete_bst(root, 68);
	printf("\ncase2: <68> 삭제: ");
	preorder(root);
	root = delete_bst(root, 18);
	printf("\ncase3: <18> 삭제: ");
	preorder(root);
	root = delete_bst(root, 35);
	printf("\ncase4: <35> root: ");
	preorder(root);

	return 0;
}
