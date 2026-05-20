#include <stdio.h>
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
void bubble_sort(int A[], int n) {
	int tmp;
	for (int end = n - 1; end > 0; end--) {
		int bChanged = 0;
		for (int j = 0; j < end; j++) {
			if (A[j] > A[j + 1]) {
				SWAP(A[j], A[j + 1], tmp);
				bChanged = 1;
			}
		}
		if (!bChanged) break;
	}
}
