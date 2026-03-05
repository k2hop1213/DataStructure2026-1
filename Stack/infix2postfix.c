#include <stdio.h>

int top = -1;
char stack[51];

void push(char a) {
	stack[++top] = a;
}

char pop() {

	if (top == -1)return 0;//스택이 비어 있으면 반환 안 함
	return stack[top--];
}

int func2(char c) {
  //괄호와 연산자의 우선순위를 반환해주는 함수
	if (c == '(' || c == ')')return 0;
	if (c == '+' || c == '-')return 1;
	if (c == '/' || c == '*')return 2;

}

void func1(char* str) {
	int i = 0;// 문자열을 순회할 변수

	while (str[i] != '\0') {
		char cur = str[i++];

		if (cur >= '0' && cur <= '9') {//현재 문자가 숫자일 경우 바로 출력
			printf("%c ", cur);
		}
		else {
			if (cur == '(') {//왼쪽 괄호는 무조건 스택에 저장
				push(cur);
			}
			else if (cur == ')') {// 오른쪽 괄호를 만나면 왼쪽 괄호를 만날 때까지 스택에 있는 연산자 모두 출력

				while (top != -1) {
					if (stack[top] == '(')break;
					printf("%c ", pop());
				}
				pop(); // 왼쪽 괄호 pop()
			}
			else if (cur == '+' || cur == '-' || cur == '*' || cur == '/') {
				// 연산자를 만났을 경우 스택에 있는 연산자들의 우선순위와 비교하면 출력할지 스택에 push할지 결정
				while (top != -1) {
					char t = stack[top]; //스택 맨 위 문자를 불러옴
					if (func2(cur) <= func2(t)) {
            
						printf("%c ", stack[top]);
						pop();
					}
					else break;//현재 문자의 우선순위가 높으면 break
				}
				push(cur);//현재 문자는 스택에 저장

			}


		}
	}
	while (top != -1)printf("%c ", pop()); //문자열을 모두 순회하였으면 스택에 남아있는 모든 문자를 출력하고 종료
	printf("\n");


}



int main() {
	char expr[2][80] = { "8 / 2 - 3 * (3 + 2)", "1 / 2 * 4 * (1 / 4)" };

	printf("중위수식: %s ==> 후위수식:", expr[0]);
	func1(expr[0]);
	printf("중위수식: %s ==> 후위수식:", expr[1]);
	func1(expr[1]);
  //중위수식: 8 / 2 - 3 * (3 + 2) ==> 후위수식:8 2 / 3 3 2 + * -
  //중위수식: 1 / 2 * 4 * (1 / 4) ==> 후위수식:1 2 / 4 * 1 4 / *

	return 0;
}
