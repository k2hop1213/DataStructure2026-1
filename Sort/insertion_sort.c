#include <stdio.h>
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
void insertion_sort(int A[], int n) {

	for (int i = 1; i < n; i++) {
		int key = A[i];
		int j;
		for (j = i - 1; j >= 0; j--) {
			if (key < A[j])
				A[j + 1] = A[j];
			else break;
		}
		A[j + 1] = key;
	}

}
