#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
후위표기식을 계산할때 나오는 수식 자체를 문자열로 변환해서
스택에 저장을 할것이다.
구조체에 문자열과 연산자의 우선순위를 함께 저장한다
우선순위에서 피연산자는 가장 높게 설정하여 불필요하게 괄호로 묶이는 일이 없도록한다
*/
typedef struct node {
	char str[101];
	int p;
}Node;

Node stack[20];
int top = -1;

void push(Node a) {
	stack[++top] = a;
}

Node pop() {
	return stack[top--];
}

int get_p(char a) {
	if (a == '+' || a == '-')return 1;
	if (a == '*' || a == '/')return 2;
	return 3;
}

int main() {

	char s[101] = "8 2 / 3 3 2 + * -";

	for (int i = 0; s[i] != '\0'; i++) {
		char cur = s[i];
		if ((cur >= 'A' && cur <= 'Z') || (cur >= '1' && cur <= '9')) { //피연산자일 때는 스택에 push한다
			Node n; sprintf(n.str, "%c", cur); n.p = 3;
			push(n);
		}
		else if (cur == '+' || cur == '-' || cur == '*' || cur == '/') {// 연산자일 때는 두 개의 수식(피연산자)를 pop한 뒤 우선순위를 비교하여 괄호를 씌울지 말지 결정
			Node a2 = pop();
			Node a1 = pop();
			int cur_p = get_p(cur);
			Node res;
			char s1[101]; char s2[101];
      //sprintf를 사용해 새로운 문자열을 저장한다
			if (a1.p < cur_p) sprintf(s1, "(%s)", a1.str);
			else strcpy(s1, a1.str);

			if (a2.p <= cur_p) sprintf(s2, "(%s)", a2.str);
			else strcpy(s2, a2.str);
      // 피연산자 연산자 피연산자 형태의 새로운 문자열로 다시 저장 후 스택에 연산결과를 push한다
			sprintf(res.str, "%s%c%s", s1, cur, s2);
			res.p = cur_p;
			push(res);

		}

	}


	printf("변환 결과: %s", stack[top].str);

	return 0;
}
