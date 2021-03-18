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


int binarySearch(int arr[], int size, int key, int &c) { 
	/*int left = 0;                 // left, right — левая и правая границы
	int right = size;
	int mid = 0;
	while (left < right - 1) {   
		++c;
		mid = (left + right) / 2;  // mid — середина области поиска
		if (arr[mid] > key) {
			left = mid;
		}
		else {
			right = mid;
		}
	}
	if (arr[right] == key) 
		return right;
	else
		return -1;*/
	int low = size - 1;
	int high = 0;
	while (low >= high) {
		int mid = (low + high) / 2;
		if (key == arr[mid] && ++c) {
			return mid;
		}
		else if (key > arr[mid] && ++c) {
			low = mid - 1;
		}
		else {
			high = mid + 1;
		}
	}
	return -1;
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

void lab_7_2() {
	int** arr; 
	const int size = 10;
	arr = new int*[size];
	int arr_size[size];
	for (int i = 0; i < size; ++i) {
		arr_size[i] = rand() % 10 + 1;
		arr[i] = new int[arr_size[i]];
	}
	cout << "\nOur array:\n";
	for (int i = 0; i < size; ++i) {
		arr[i][0] = arr_size[i];
		cout << arr[i][0] << " ";
		for (int j = 1; j < arr_size[i]; ++j) {
			arr[i][j] = rand() % 10;
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	return;
}

void lab_7() {
	cout << "\nEx.1\n\n";
	lab_7_1();
	cout << "\nEx.2\n\n";
	lab_7_2();
	return;
}
