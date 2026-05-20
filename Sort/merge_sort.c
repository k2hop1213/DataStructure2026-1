#include <stdio.h>
#define MAX_SIZE 1024

static void merge(int A[], int left, int mid, int right) {
	static int sorted[MAX_SIZE];
	int i = left;
	int j = mid + 1;
	int k = left;
	while (i <= mid && j <= right) {
		if (A[i] <= A[j])
			sorted[k++] = A[i++];
		else
			sorted[k++] = A[j++];
	}
	while (i <= mid) sorted[k++] = A[i++];
	while (j <= right) sorted[k++] = A[j++];

	for (i = left; i <= right; i++)
		A[i] = sorted[i];
}

void merge_sort(int A[], int left, int right) {
	if (left < right) {
		int mid = (left + right) / 2;
		merge_sort(A, left, mid);
		merge_sort(A, mid + 1, right);
		merge(A, left, mid, right);
	}
}
