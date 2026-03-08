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

	for (int i = 0; i < strlen(buf)/2; i++) {//절반까지만 stack에 삽입
		push(buf[i]);
	}
	int t = (strlen(buf) % 2 == 1) ? 1 : 0;//문자열의 짝수 여부에 따라 1을 더할지 말지 정함(홀수면 한 칸 건너 뛰어야함)
	for (int i = strlen(buf) / 2 + t; i < strlen(buf); i++) {
		if (buf[i] == stack[top]) pop();
		else {
			printf("펠린드롬 아님");//나머지 절반에서 다른것이 나온다면 펠린드롬이 아님
			return 0;
		}
	}
	printf("펠린드롬임 ㅇㅇ");

	return 0;
}
