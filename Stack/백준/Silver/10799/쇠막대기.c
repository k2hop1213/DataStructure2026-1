#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char stack[100001];
char str[100001];
int top;

int isEmpty() {
	return top == -1;
}

void push(char a) {
	stack[++top] = a;
}

char pop() {
	if (isEmpty()) return 0;
	return stack[top--];
}



int main() {

	scanf("%s", str);
	int res = 0;
	int depth = 0;

	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '(') {
			push(i);
		}
		else {
			if (str[i - 1] == '(') {
				pop();
				res += top;
			}
			else { pop(); res++; }
		}
	}

	printf("%d", res);
	return 0;
}