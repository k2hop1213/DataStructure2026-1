#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define M 10000
int table[M];
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

int stringFolding(char* key) {
	int hash = 0;
	int len = strlen(key);

	// 4글자씩 묶어서 하나의 정수로 변환 후 더하기
	for (int i = 0; i < len; i += 4) {
		int val = 0;
		for (int j = 0; j < 4; j++) {
			val <<= 8; // 8비트씩 왼쪽으로 밀어줍니다 (자릿수 이동)
			if (i + j < len) {
				val += key[i + j];
			}
		}
		hash += val;
	}
	return hash;
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
