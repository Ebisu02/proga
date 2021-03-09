#include "include.h"


void lab_5_1() {
	srand(time(NULL));
	int sizeM = 10;
	int* arrA; 
	arrA = new int[sizeM];
	cout << "Start array:\n";
	for (int i = 0; i < sizeM; ++i) {
		arrA[i] = rand() % 10;
		cout << arrA[i] << " ";
	}
	/*
	int k;
	cout << "Enter a \"k\", this variable should be k < m\n";
	cin >> k;
	*/
	cout << "\nMatrix:\n";
	int sizeK = 9;
	int sizeKv = sizeM / sizeK + 1;  
	int** arrB;
	arrB = new int* [sizeKv];
	for (int i = 0; i < sizeKv; ++i) {
		arrB[i] = new int[sizeK];
	}
	for (int i = 0, z = 0, k = 0; i < sizeKv; ++i) {
		for (int j = 0; j < sizeK; ++j) {
			if (k < sizeM) {
				arrB[i][j] = arrA[z];
				++z;
				cout << arrB[i][j] << " ";
				++k;
				continue;
			}
			arrB[i][j] = 0;
			cout << arrB[i][j] << " ";
		}
		cout << "\n";
	}
	delete[] arrA;
	for (int i = 0; i < sizeKv; ++i) {
		delete[] arrB[i];
	}
	delete[] arrB;
	return;
}

/*
Создать двумерный массив с переменной длиной строки, в который записать таблицу умножения следующего вида :
1
2   4
3   6   9
4   8  12 16
5  10 15 20 25
6  12 18 24 30 36
7  14 21 28 35 42 49
8  16 24 32 40 48 56 64
9  18 27 36 45 54 63 72 81
*/

void lab_5_2() {
	srand(time(NULL));
	int** arr;
	int size = 9;
	arr = new int* [size];
	for (int i = 0; i < size; ++i) {
		arr[i] = new int[i + 1];
	}
	for (int i = 0; i < size; ++i) {
		for (int k = 0; k < i + 1; ++k) {
			arr[i][k] = (i + 1) * (k + 1);
			cout << arr[i][k] << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < size; ++i) {
		delete[] arr[i];
	}
	delete[] arr;
	return;
}

void lab_5() {
	cout << "\n\n\nEx. #1\n\n";
	lab_5_1();
	cout << "\n\n\nEx. #2\n\n";
	lab_5_2();
	return;
}