#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SWAP(x,y,t) ((t)=(x),(x)=(y),(y)=(t))
int partition(int A[], int left, int right) {
	int pivot = A[left];
	int low = left + 1;
	int high = right;
	int tmp;

	while (low <= high) {
		while (low <= high && A[low] <= pivot)low++;
		while (low <= high && A[high] > pivot)high--;
		if (low < high)
			SWAP(A[low], A[high], tmp);
	}
	SWAP(A[left], A[high], tmp);
	return high;
}

void quick_sort(int A[], int left, int right) {
	if (left < right) {
		int q = partition(A, left, right);
		quick_sort(A, left, q - 1);
		quick_sort(A, q + 1, right);
	}

}



int main() {
	int arr[] = { 5,3,8,4,9,1,6,2,7 };
	quick_sort(arr, 0, 8);
	for (int i = 0; i < 9; i++) {
		printf("%d ", arr[i]);
	}


	return 0;
}
