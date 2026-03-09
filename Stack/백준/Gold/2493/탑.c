#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct info {
	int data;
	int idx;
}pair;

pair stack[500001];
int top = -1;
int isEmpty() { return top == -1; }
void push(int _data,int _idx) { 
	top += 1;
	stack[top].data = _data;
	stack[top].idx = _idx;
}
pair pop() {
	if (!isEmpty()) return stack[top--];
}

int main() {

	int n;
	scanf("%d", &n);

	int max = 0;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		if (max < t) {
			printf("0 ");
			max = t;
			push(t, i + 1);
		}
		else {
			while (!isEmpty()) {
				if (t < stack[top].data) {
					printf("%d ", stack[top].idx);
					break;
				}
				pop();
			}
			push(t, i + 1);
		}


	}




	return 0;
}
