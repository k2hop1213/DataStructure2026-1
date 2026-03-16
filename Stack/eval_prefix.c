#include <stdio.h>
#include <string.h>

int stack[101];
int top = -1;

int main() {
	char str[] = "- 1 + 3 2";

	for (int i = strlen(str) - 1; i >= 0; i--) {

		if (str[i] >= '0' && str[i] <= '9') {
			stack[++top] = str[i] - '0';
		}
		else if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') {
			int a1 = stack[top--];
			int a2 = stack[top--];

			if (str[i] == '+')stack[++top] = a1 + a2;
			else if (str[i] == '-')stack[++top] = a1 - a2;
			else if (str[i] == '*')stack[++top] = a1 * a2;
			else if (str[i] == '/')stack[++top] = a1 / a2;
		}


	}

	printf("%d", stack[top]);

	return 0;
}
