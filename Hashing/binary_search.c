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
