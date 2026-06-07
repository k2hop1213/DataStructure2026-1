#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define M 10000
int table[M];
void print_lp(const char* msg)  // 테이블 출력을 위한 함수
{
    printf("%s: ", msg);
    for (int i = 0; i < M; i++)
        printf("[%2d] ", table[i]);
    printf("\n");
}
int hashFn(int key) { return key % M; }
int hashFn2(int key, int part) {
	if (key <= 0 || part <= 0) return 0;
	int len = 0;
	int temp = key;
	while (temp > 0) {
		temp /= 10;
		len++;
	}

	int size = len / part;
	if (size == 0) size = 1;
	if (size == len) return -1;

	int res = 0;


	for (int i = 0; i < part - 1; i++) {

		int cut = 1;
		for (int j = 0; j < len - size; j++) {
			cut *= 10;
		}

		res += key / cut; 
		key %= cut;       
		len -= size;          
	}

	res += key;

	return res;
}
void init_lp() {
	for (int i = 0; i < M; i++)
		table[i] = 0;
}

void insert_lp(int key) {
	int i = hashFn(key);
	for (int k = 0; k < M; k++) {
		if (table[i] == 0 || table[i] == -1) {
			table[i] = key;
			return;
		}
		i = (i + 1) % M;
	}
}

int search_lp(int key) {
	int i = hashFn(key);
	for (int k = 0; k < M; k++) {
		if(table[i] == key) return i;
		if (table[i] == 0) return -1;
		i = (i + 1) % M;
	}
	return -1;
}

int delete_lp(int key) {
	int i = hashFn(key);
	for (int k = 0; k < M; k++) {
		if (table[i] == key) {
			table[i] = -1;
			return i;
		}
		if (table[i] == 0)
			return -1;
		i = (i + 1) % M;
	}
	return -1;
}
int main()
{
    Entry data[9] = { 45, 27, 88, 9, 71, 60, 46, 38, 24 };
    init_lp();
    print_lp("삽입전");
    for (int i = 0; i < 9; i++) {
        insert_lp(data[i]);
        print_lp(" ");
    }
    printf("46탐색: %d\n", search_lp(46));
    printf("39탐색: %d\n", search_lp(39));
    delete_lp(60); print_lp("60삭제");
    delete_lp(46); print_lp("46삭제");
	return 0;
}
