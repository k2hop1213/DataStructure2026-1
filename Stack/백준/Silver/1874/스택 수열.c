#include <stdio.h>

int stack[100001];
char str[200001];

int top = -1;

int isEmpty() { return top == -1; }

void push(int a) {
	stack[++top] = a;
}

int pop() {
	if (isEmpty())return 0;
	return stack[top--];
}


int main() {

	int n;
	scanf("%d", &n);
	int a = 1;
	int idx = 0;
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		
		if (a <= t) {
			for (int j = a; j <= t; j++) {
				push(j);
				str[idx++] = '+';
			}
			pop();
			str[idx++] = '-';
			a = t + 1;
			if (a > n)a = n;
		}
		else if (a > t) {
			while (!isEmpty()) {
				if (stack[top] == t) {
					pop();
					str[idx++] = '-';
					break;
				}
				else if (stack[top] > t) {
					printf("NO");
					return 0;
				}
				pop();
				str[idx++] = '-';
				
			}
		}
		

	}


	for (int i = 0; str[i] != '\0'; i++) {
		printf("%c\n", str[i]);
	}

	return 0;
}