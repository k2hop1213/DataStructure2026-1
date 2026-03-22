#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int my_pow(int n, int x) {

	if (x == 0)return 1;

	if (x % 2) {
		return n * my_pow(n*n, (x-1) / 2);
	}
	else {
		return my_pow(n*n, x / 2);
	}

}


int main() {

	int n, x;
	printf("수를 입력하세요: "); scanf("%d", &n);
	printf("지수를 입력하세요: "); scanf("%d", &x);

	int res = my_pow(n, x);

	printf("%d의 %d승은 : %d", n, x, res);

	return 0;
}
