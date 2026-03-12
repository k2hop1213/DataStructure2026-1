#include <stdio.h>
#include <stdlib.h>
#include <string.h>


double num_stack[100]; // 숫자 
char op_stack[100];    // 기호
int n_top = -1, o_top = -1;

// 연산자 힘(우선순위) 측정
int get_p(char op) {
	if (op == '*' || op == '/') return 2;
	if (op == '+' || op == '-') return 1;
	return 0; // 괄호용
}

// 실제 계산 수행 (숫자 2개, 기호 1개)
void compute() {
	double v2 = num_stack[n_top--];
	double v1 = num_stack[n_top--];
	char op = op_stack[o_top--];

	if (op == '+') num_stack[++n_top] = v1 + v2;
	else if (op == '-') num_stack[++n_top] = v1 - v2;
	else if (op == '*') num_stack[++n_top] = v1 * v2;
	else if (op == '/') num_stack[++n_top] = v1 / v2;
}

int main() {

	char str[] = "12.5 + ( 7.5 * 2 )";
	char* ptr = strtok(str, " ");

	while (ptr != NULL) {
		// 1. 숫자인 경우 (첫 글자가 숫자거나, 마이너스 부호 뒤에 숫자인 경우)
		if (isdigit(ptr[0]) || (ptr[0] == '-' && isdigit(ptr[1]))) {
			num_stack[++n_top] = atof(ptr);
		}
		// 2. 열린 괄호
		else if (ptr[0] == '(') {
			op_stack[++o_top] = '(';
		}
		// 3. 닫힌 괄호 (괄호가 닫힐 때까지 쌓인 연산 다 하기)
		else if (ptr[0] == ')') {
			while (o_top >= 0 && op_stack[o_top] != '(') compute();
			o_top--; // '(' 버리기
		}
		// 4. 연산자 (+, -, *, /)
		else if (ptr[0]=='+'|| ptr[0] == '-' || ptr[0] == '*' || ptr[0] == '/' ) {
			while (o_top >= 0 && get_p(op_stack[o_top]) >= get_p(ptr[0])) {
				compute();
			}
			op_stack[++o_top] = ptr[0];
		}
		ptr = strtok(NULL, " "); // 다음 조각 가져오기
	}

	//남은 연산 마무리
	while (o_top >= 0) compute();

	printf("계산 결과: %.2f\n", num_stack[n_top]);

	return 0;
}
