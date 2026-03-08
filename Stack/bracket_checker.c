#include <stdio.h>

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

	char s[51];
	scanf("%s", s);

	int i = 0;//문자열을 순회할 변수

	while (s[i] != '\0') {
		char cur = s[i++];

		if (cur == '(' || cur == '{' || cur == '[') {//여는 괄호는 스텍으로 push
			push(cur);
		}
		else if (cur == ')' || cur == '}' || cur == ']') {//닫는 괄호가 나왔을 때

			if (isEmpty()) {// 닫는 괄호가 나왔는데 스택에 아무것도 없다면 잘못된것임
				printf("잘못됨");
				return 0;
			}
      //같은 종류의 괄호끼리 만났다면 pop을 한다.
			if (stack[top] == '(' && cur == ')') {
				pop();

			}
			else if (stack[top] == '{' && cur == '}') {
				pop();
			}
			else if (stack[top] == '[' && cur == ']') {
				pop();
			}
			else {//다른 종류끼리 만난 경우 올바르지 않음.
				printf("잘못됨");
				return 0;
			}

		}

	}
  // 문자열을 다 순회했음에도 스택에 괄호가 있다면 올바르지 못한 경우임
	if (!isEmpty()) printf("잘못됨");
	else printf("잘 됨");


	return 0;
}
