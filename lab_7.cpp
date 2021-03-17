#include "include.h"

void BubbleSort_inv(int arr[], int size) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
			}
		}
	}
	return;
}





int pereborSearch(int arr[], int size, int key_what_we_find, int &c) {
	c = 0; 
	for (int i = 0; i < size; i++) {
		++c;
		if (arr[i] == key_what_we_find) {
			return i;
		}
	}
	return -1;
}


void lab_7_1() {
	srand(time(NULL));
	const int size = 100;
	const int size_a = 1000;
	int arr[size];
	int arr_a[size_a];


	// For array with size = 100
	cout << "\n\nEx. #1" << "\n\nOur arrray(N = 100):\n";
	for (int i = 0; i < size; ++i) {
		arr[i] = rand() % 100;
		cout << arr[i] << " ";
	}
	cout << "\nSorted array(N = 100):\n";
	BubbleSort_inv(arr, size);
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	// For example, lets find number 10
	int key = 10;

	// Perebor Search for N = 100
	cout << "\n\nPerebor search:\n";
	int c = 0; 
	if (pereborSearch(arr, size, key, c) != -1) {
		cout << pereborSearch(arr, size, key, c) << " - index in what we have this key = " << key << "\n";
		cout << "Compares = " << c << "\n";
	}
	else {
		cout << "\nWe havent this number in array\n";
	}

	//Binary search for N = 100
	cout << "\nBinary search:\n";
	c = 0;
	if (binarySearch(arr, size, key, c) != -1) {
		cout << binarySearch(arr, size, key, c) << " - index in what we have this key = " << key << "\n";
		cout << "Compares = " << c << "\n";
	}
	else {
		cout << "\nWe havent this number in array\n";
	}

	// For array with size = 1000
	cout << "\n\n\nOur arrray(N = 1000) :\n";
	for (int i = 0; i < size_a; ++i) {
		arr_a[i] = rand() % 100;
		cout << arr_a[i] << " ";
	}
	cout << "\nSorted array(N = 1000):\n";
	BubbleSort_inv(arr_a, size_a);
	for (int i = 0; i < size_a; ++i) {
		cout << arr_a[i] << " ";
	}


	// For example we take same num (key = 10)
	// Perebor Search for N = 1000
	cout << "\n\nPerebor search:\n";
	if (pereborSearch(arr_a, size_a, key, c) != -1) {
		cout << pereborSearch(arr_a, size_a, key, c) << " - index in what we have this key = " << key << "\n";
		cout << "Compares = " << c << "\n";
	}
	else {
		cout << "\nWe havent this number in array\n";
	}

	//Binary search for N = 1000
	cout << "\nBinary search:\n";
	c = 0;
	if (binarySearch(arr_a, size_a, key, c) != -1) {
		cout << binarySearch(arr_a, size_a, key, c) << " - index in what we have this key = " << key << "\n";
		cout << "Compares = " << c << "\n";
	}
	else {
		cout << "\nWe havent this number in array\n";
	}
	return;
}

void lab_7() {
	lab_7_1();
	return;
}