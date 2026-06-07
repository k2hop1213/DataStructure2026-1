#include <stdio.h>
// Upper Bound: key 값 초과가 처음 나오는 위치
int upper_bound(int arr[], int size, int key) {
    int left = 0;
    int right = size;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] > key) {
            right = mid; // key보다 크면 더 왼쪽을 탐색합니다.
        } else {
            left = mid + 1; // key와 같거나 작으면 오른쪽을 탐색합니다.
        }
    }
    return left;
}
