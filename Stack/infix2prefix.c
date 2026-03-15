#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
char stack[101];
int top = -1;
int get_p(char a) {
	if (a == '+' || a == '-')return 1;
	if (a == '*' || a == '/')return 2;
	return 0;
}
int main() {
	/*
	식을 뒤집는다 (괄호도 반대 방향으로 뒤집음)
	그 식을 후위로 바꾼다
	그리고 거꾸로 출력한다
	*/
	char str[101] = "1 - 2 - 3";
	char str1[101] = { 0 };
	int idx = 0;

	for (int i = 0; i<strlen(str); i++) {
		if (str[i] == '(' || str[i] == ')') {
			char temp = (str[i] == ')') ? '(' : ')';
			str[i] = temp;
		}

	}
	for (int i = 0; i < strlen(str)/2; i++) {
		char temp = str[i];
		str[i] = str[strlen(str) - 1 - i];
		str[strlen(str) - 1 - i] = temp;
	}

	for (int i = 0; str[i]; i++) {
		if (isdigit(str[i])) {
			str1[idx++] = str[i];
		}
		else if (str[i] == '(') {
			stack[++top] = str[i];
		}
		else if (str[i] == ')') {
			while (top != -1) {
				if (stack[top] == '(')break;
				str1[idx++] = stack[top--];
			}
			top--;
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {

			while (top!=-1) {
				if (get_p(str[i]) < get_p(stack[top])) {//개큰별표
					str1[idx++] = stack[top--];
				}
				else break;
			}
			stack[++top] = str[i];

		}
	}
	while (top != -1)str1[idx++] = stack[top--];
	for (int i = 0; i < strlen(str1) / 2; i++) {
		char temp = str1[i];
		str1[i] = str1[strlen(str1) - 1 - i];
		str1[strlen(str1) - 1 - i] = temp;
	}
	printf("%s", str1);


	return 0;
}
