#include <stdio.h>
#include <string.h>

char stack[51];
int top = -1;
int isEmpty() { return top == -1; }
int isFull() { return top == 50; }

void push(char a) {
	if (isFull())return;
	stack[++top] = a;
}

char pop() {
	if (isEmpty())return 0;
	return stack[top--];
}


int main() {
	char buf[51];
	scanf("%s", buf);

	for (int i = 0; i < strlen(buf)/2; i++) {
		push(buf[i]);
	}
	int t = (strlen(buf) % 2 == 1) ? 1 : 0;
	for (int i = strlen(buf) / 2 + t; i < strlen(buf); i++) {
		if (buf[i] == stack[top]) pop();
		else {
			printf("펠린드롬 아님");
			return 0;
		}
	}
	printf("펠린드롬임 ㅇㅇ");

	return 0;
}
