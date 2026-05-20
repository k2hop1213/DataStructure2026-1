#include <stdio.h>
int ascend(int x, int y) { return y - x; }
int descend(int x, int y) { return x - y; }

void insertion_sort_fn(int A[], int n, int(*f)(int, int)) {

	for (int i = 1; i < n; i++) {
		int key = A[i];
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (f(A[j], key) < 0)
				A[j + 1] = A[j];
			else break;
		}
		A[j + 1] = key;
	}

}
