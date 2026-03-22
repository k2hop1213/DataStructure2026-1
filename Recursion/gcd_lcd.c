#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int gcd(int a, int b) {
	if (b == 0)return a;
	return gcd(b, a % b);
}

int lcd(int a, int b) {

	return a / gcd(a, b) * b;
}

int main() {
	int n1, n2;
	printf("두 수를 입력하세요: ");
	scanf("%d %d", &n1, &n2);

	if(gcd(n1,n2)!=1)printf("%d와 %d의 최대공약수는 %d\n", n1, n2, gcd(n1, n2));
	else printf("최대공약수는 없습니다.");
	printf("%d와 %d의 최소공배수는 %d\n", n1, n2, lcd(n1, n2));

	return 0;
}
