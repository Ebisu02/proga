#include "include.h"

const int n = 5;
typedef int row[n];
typedef int rowC[n - 1];

void lab_4_1() {
	cout << "\n\nEx.1\n\n";
	srand(time(NULL));
	row* arr;
	int m = 4;
	/*
	cout << "\nEnter a amount of strings\n";
	cin >> m;
	*/
	cout << "\nOur Matrix:\n";
	arr = new row[m];
	int max = 0;
	int link_i;
	int link_j;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			arr[i][j] = rand() % 100;
			cout << arr[i][j] << " ";
			if (arr[i][j] > max) {
				max = arr[i][j];
				link_i = i;
				link_j = j;
			}
		}
		cout << "\n";
	}
	++link_i; ++link_j;
	cout << "\nMax element in this Matrix = " << max << "\nString - " << link_i << "\nColumn - " << link_j << "\n";
	rowC* arrC;
	arrC = new rowC[m - 1];
	cout << "\nOur Matrix C:\n";
	for (int i = 0, ic = 0; ic < m - 1; ++i) {
		if (i + 1 == link_i) {
			continue;
		}
		for (int j = 0, jc = 0; jc < n - 1; ++j) {
			if (j + 1 == link_j) {
				continue;
			}
			arrC[ic][jc] = arr[i][j];
			cout << arrC[ic][jc] << " ";
			++jc;
		}
		cout << "\n";
		++ic;
	}
	delete[] arr; delete[] arrC;
	arr = NULL; arrC = NULL;
	return;
}

void lab_4_2() {
	srand(time(NULL));
	cout << "\n\nEx.2\n\n";
	int sizeM = 3; int sizeN = 3;
	/*
	cout << "\nEnter a size for Matrix with size m x n: \n";
	cout << "\nm = ";
	cin >> sizeM;
	cout << "\nn = ";
	cin >> sizeN;
	*/
	int** arrA;
	arrA = new int* [sizeM];
	for (int i = 0; i < sizeM; ++i) {
		arrA[i] = new int[sizeN];
	}
	cout << "\nOur Matrix:\n";
	for (int i = 0; i < sizeM; ++i) {
		for (int j = 0; j < sizeN; ++j) {
			arrA[i][j] = rand() % 100;
			cout << arrA[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\nMatrix D:\n";
	int** arrD;
	arrD = new int* [sizeM + 1];
	for (int i = 0; i < sizeN + 1; ++i) {
		arrD[i] = new int[sizeN + 1];
	}
	int sum = 0;
	for (int i = 0; i < sizeM; ++i) {
		int sumstr = 0, sumcol = 0;
		for (int j = 0; j < sizeN; ++j) {
			sumstr += arrA[i][j];
			if (j < sizeM) {
				sumcol += arrA[j][i];
			}
			sum += arrA[i][j];
			arrD[i][j] = arrA[i][j];  
			if (i == sizeM - 1 && j == sizeN - 1) {
				arrD[sizeM][sizeN] = sum;
			}
			arrD[sizeM][i] = sumcol;
			arrD[i][sizeN] = sumstr;
		}
	}
	for (int i = 0; i <= sizeM; ++i) {
		for (int j = 0; j <= sizeN; ++j) {
			cout << arrD[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 0; i < sizeM; ++i) {
		delete[] arrA[i];
	}
	delete[] arrA;
	arrA = NULL;
	for (int i = 0; i < sizeM + 1; ++i) {
		delete[] arrD[i];
	}
	delete[] arrD;
	arrD = NULL;
	return;
}

void lab_4() {
	lab_4_1();
	lab_4_2();
	return;
}