#include <stdio.h>

// Lower Bound: key 값 이상이 처음 나오는 위치
int lower_bound(int arr[], int size, int key) {
    int left = 0;
    int right = size; // 범위를 배열의 크기까지로 잡습니다.

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= key) {
            right = mid; // key와 같거나 크면 더 왼쪽을 탐색합니다.
        } else {
            left = mid + 1; // key보다 작으면 오른쪽을 탐색합니다.
        }
    }
    return left;
}
