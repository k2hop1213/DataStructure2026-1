#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void init_queue(int** queue,int* front, int* rear,int size) {

	*queue = malloc(sizeof(int) * size);
	*front = 0;
	*rear = 0;

}

int is_empty(int front, int rear) {
	return front == rear;
}

int is_full(int front, int rear,int size) {
	return (rear + 1) % size == front;
}
int dequeue(int* queue, int* front, int rear, int size) {
	if (is_empty(*front, rear)) {
		printf("underflow\n");
		exit(0);
	}
	*front = (*front + 1) % size;
	return queue[*front];
}

void enqueue(int** queue,int* front, int* rear, int* size, int data) {
	if (is_full(*front,*rear,*size)) {
		int temp = *size;
		*size *= 2;
		printf("overflow 발생, 메모리 재할당 size = %d\n", *size);

		*queue = realloc(*queue, sizeof(int) * (*size));

		if (*front > *rear) { 
			/*
			예를 들어 5   2 3 4 라고 하면 확장할 때 5 (4칸)  2 3 4로 만들기 위함 (2,3,4 뒤로 복사)
					  r f						   r       f
			만약에 그냥   1 2 3 4 이렇게 있으면 그냥 확장해서 쓰면 됨 
						f       r
			결론 : rear가 앞으로 다시 돌아왔는지를 확인해야한다.
			*/

			int cnt = temp - (*front + 1);

			for (int i = 1; i <= cnt; i++) {
				(*queue)[*size - i] = (*queue)[temp - i];
			}
			// front를 이동시킨 데이터 바로 앞칸으로 정확히 지정
			*front = *size - cnt - 1;
		}
	}
	*rear = (*rear + 1) % *size;
	(*queue)[*rear] = data;
}



int main() {
	int* queue = NULL;
	int size;
	int front = 0;
	int rear = 0;
	scanf("%d", &size);
	init_queue(&queue, &front, &rear, size);
	while (1) {
		int a;
		scanf("%d", &a);
		if (a > 0) {
			enqueue(&queue, &front, &rear, &size, a);
		}
		else if (a == 0) {
			int i = (front + 1) % size;
			while (i != rear) {
				printf("%d ", queue[i]);
				i = (i + 1) % size;
			}
			printf("%d ", queue[i]);
			return 0;
		}
		else if (a == -1) {
			printf("%d front:%d, rear:%d\n", dequeue(queue, &front, rear, size), front, rear);
		}
	}


	return 0;
}
