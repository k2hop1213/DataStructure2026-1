#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int n;
	int state;
	int result;
}Frame;

Frame stack[10000];

int top = -1;

void push(Frame f) {
	stack[++top] = f;
}

Frame pop() {
	return stack[top--];
}

Frame* peek() {
	return &stack[top];
}

int fib_stack(int N) {
	Frame f = { N,0,0 };
	push(f);
	int res = 0;
	while (top != -1) {
		Frame* p = peek();

		if (p->n <= 1) {
			res = p->n;
			pop();
		}
		else if (p->state == 0) {
			p->state = 1; // fib_stack(n - 1)을 호출한 상태
			Frame f1 = { p->n - 1,0,0 };
			push(f1);
		}
		else if (p->state == 1) {
			p->result = res;//부분 결과 저장
			p->state = 2;// fib_stack(n - 2)을 호출한 상태
			Frame f1 = { p->n - 2,0,0 };
			push(f1);
		}
		else if (p->state == 2) {
			res += p->result;
			pop();
		}

	}
	return res;

}

int main() {

	int n;
	scanf("%d", &n);
	printf("%d", fib_stack(n));

	return 0;
}
