#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h> // atof 함수 사용을 위해 필요
#include <string.h>

double stack[20];
int top = -1;

void push(double val) {
	stack[++top] = val;
}

double pop() {
	return stack[top--];
}

int main() {
	char str[] = "12.5 100 + 2.5 /";
	//공백으로 구분하여 저장
	char* ptr = strtok(str, " ");

	while (ptr != NULL) {
		// 연산자인지 확인 (글자 수가 1이고 기호인 경우)
		if (strlen(ptr) == 1 && (ptr[0] == '+' || ptr[0] == '-' || ptr[0] == '*' || ptr[0] == '/')) {
			double op2 = pop();
			double op1 = pop();
			char c = ptr[0];

			if (c == '+') push(op1 + op2);
			else if (c == '-') push(op1 - op2);
			else if (c == '*') push(op1 * op2);
			else if (c == '/') {
				if (op2 == 0) {
					return 0;
				}
				push(op1 / op2);
			}
		}
		else {
			// 숫자 문자열을 실수(double)로 변환하여 push
			push(atof(ptr));
		}
		ptr = strtok(NULL, " "); //다음 문자열로 이동
	}

	printf("최종 계산 결과: %.2f\n", pop());

	return 0;
}
