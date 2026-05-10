#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_HSIZE 100
#define PARENT(i) (i/2)
#define LEFT(i) (i*2)
#define RIGHT(i) (i*2 + 1)

int A[MAX_HSIZE];
int heap_size = 0;
#define KEY(i) (A[i])

void init_heap() { heap_size = 0; }
int is_empty_heap() { return heap_size == 0; }
int is_full_heap() { return (heap_size == MAX_HSIZE - 1); }
int heap_peak() { return A[1]; }

void heap_push(int n) {
	if (is_full_heap())
		return;

	heap_size++;
	A[heap_size] = n;
	int i = heap_size;

	while (i != 1) {
		if (KEY(i) > KEY(PARENT(i))) {
			A[i] = A[PARENT(i)];
			A[PARENT(i)] = n;
			i = PARENT(i);
		}
		else break;

	}

}

int heap_pop() {
	if (is_empty_heap())
		return -1;

	int root = A[1];
	int last = A[heap_size];
	A[1] = last;
	heap_size--;
	int i = 1;
	while (LEFT(i) <= heap_size) {
		int child = LEFT(i);
		if (RIGHT(i) <= heap_size && KEY(RIGHT(i)) > KEY(LEFT(i))) {
			child = RIGHT(i);
		}
		if (KEY(i) > KEY(child)) break;
		A[i] = A[child];
		A[child] = last;
		i = child;
	}
	return root;
}
void print_heap()
{
	for (int i = 1; i <= heap_size; i++)
		printf("%2d", A[i]);
	printf("\n");
}


int is_max_heap(int arr[], int len)
{
	for (int i = 1; i <= len / 2; i++) {
		if (arr[i] < arr[LEFT(i)])
			return 0;
		if (RIGHT(i) <= len && arr[i] < arr[RIGHT(i)])
			return 0;
	}
	return 1;          
}
int main() {

	int data[] = { 2, 5, 4, 8, 9, 3, 7, 3 };
	init_heap();

	printf("\n최대 힙 삽입 연산 테스트\n");
	for (int i = 0; i < 8; i++) {
		heap_push(data[i]);
		printf("%2d ---> ", data[i]);
		print_heap();
	}
	printf("\n최대 힙 삭제 연산 테스트\n");
	while (!is_empty_heap()) {
		printf("%2d <--- ", heap_pop());
		print_heap();
	}
	printf("\n");


	int a[] = { 0, 9, 7, 6, 5, 4, 3, 2, 2, 1, 3 }; // 최대힙 맞음
	int b[] = { 0, 9, 7, 6, 5, 3, 3, 2, 2, 1, 4 }; // 최대힙 아님
	printf("a[]: 최대힙 %s\n", is_max_heap(a, 11) ? "맞음" : "아님");
	printf("b[]: 최대힙 %s\n", is_max_heap(b, 11) ? "맞음" : "아님");

	return 0;
}
