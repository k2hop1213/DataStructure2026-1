#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
char stack[31];
int top = -1;

int isEmpty() { return top == -1; }

void push(char a) {
	stack[++top] = a;
}

char pop() {
	if (isEmpty())return 0;
	return stack[top--];
}

int main() {
	char str[31];
	scanf("%s", str);
	int depth = 1;
	int res = 0;
	for (int i = 0; i < strlen(str); i++) {

		if (str[i] == '(' || str[i] == '[') {
			int t = (str[i] == '(') ? 2 : 3;
			push(str[i]);
			depth *= t;
		}
		else if (str[i] == ')' || str[i] == ']') {
			if (isEmpty()) {
				printf("0");
				return 0;
			}
			if (str[i - 1] == '(' && str[i] == ')') {
				res += depth;
			}
			else if (str[i - 1] == '[' && str[i] == ']') {
				res += depth;
			}
			else if ((stack[top] == '(' && str[i] == ']') || (stack[top] == '[' && str[i] == ')')) {
				printf("0");
				return 0;
			}
			int t1 = (str[i] == ')') ? 2 : 3;
			pop();
			depth /= t1;
		}

	}

	if (!isEmpty())printf("0");
	else printf("%d", res);

	return 0;
}
