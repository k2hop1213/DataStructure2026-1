#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char board[3500][3500];

void func(int N, int r, int c) {
	if (N == 3) {
		board[r][c] = '*';

		board[r + 1][c - 1] = '*';
		board[r + 1][c + 1] = '*';

		for (int j = 0; j < 5; j++) {

			board[r + 2][c - 2 + j] = '*';
		}

		return;
	}

	func(N / 2, r, c);
	func(N / 2, r + N / 2, c + N / 2);
	func(N / 2, r + N / 2, c - N / 2);

}

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2 * n; j++) {
			board[i][j] = ' ';
		}
	}

	func(n, 0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%s\n", board[i]);
	}

	return 0;
}
