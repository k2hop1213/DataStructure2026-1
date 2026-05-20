#include <stdio.h>
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))

void selection_sort(int A[], int n) {

	int tmp;
	for (int i = 0; i < n - 1; i++) {
		int least = i;
		for (int j = i + 1; j < n; j++) {
			if (A[least] > A[j])
				least = j;
		}
		SWAP(A[i], A[least], tmp);
	}

}
