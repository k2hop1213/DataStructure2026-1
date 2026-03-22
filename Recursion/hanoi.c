#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void hanoi(int n, int start, int temp, int end) {
	if (n == 1) {
		printf("%d를 %d에서 %d로 옮김\n", n, start, end);
		return;
	}
	hanoi(n - 1, start, end, temp);
	printf("%d를 %d에서 %d로 옮김\n", n, start, end);
	hanoi(n - 1, temp, start, end);
}

int main() {
	int n;
	scanf("%d", &n);
	printf("총 이동횟수: %d\n", (1 << n) - 1);
	hanoi(n, 1, 2, 3);

	return 0;
}
