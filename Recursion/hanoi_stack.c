#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct {
	int n;
	int state;
	char start;
	char temp;
	char end;
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

void hanoi_stack(int N) {
	Frame f = { N,0,'A','B','C'};
	push(f);
	int res = 0;
	while (top != -1) {
		Frame* p = peek();

		if (p->n == 1) {
			printf("%d번 기둥을 %c에서 %c로 옮김\n", p->n, p->start,p->end);
			pop();
		}
		else if (p->state == 0) {
			p->state = 1; 
			Frame f1 = { p->n - 1,0,p->start,p->end,p->temp };
			push(f1);
		}
		else if (p->state == 1) {
			printf("%d번 기둥을 %c에서 %c로 옮김\n", p->n, p->start, p->end);
			p->state = 2;
			Frame f1 = { p->n - 1,0,p->temp,p->start,p->end};
			push(f1);
		}
		else if (p->state == 2) {
			
			pop();
		}
	}

}

int main() {

	int n;
	scanf("%d", &n);
	hanoi_stack(n);

	return 0;
}
