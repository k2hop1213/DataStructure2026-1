#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int binary_search(int A[], int key, int low, int high) {
	if (low <= high) {
		int mid = (low + high) / 2;
		if (key == A[mid])
			return mid;
		else if (key < A[mid])
			return binary_search(A, key, low, mid - 1);
		else return binary_search(A, key, mid + 1, high);
	}
	return -1;
}

int binary_search_iter(int A[], int key, int low, int high) {
	while (low <= high) {
		int mid = (low + high) / 2;
		if (key == A[mid])
			return mid;
		else if (key < A[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	return -1;
}

int main()
{
    int	list[16] = { 8, 11, 12, 15, 16, 19, 20, 23, 25, 28, 29, 31, 33, 35, 38, 40 };
    int key = 28;
    printf("  %d 이진탐색(순환): %d\n", key, binary_search(list, key, 0, 15));
    printf("\n");
	return 0;
}
