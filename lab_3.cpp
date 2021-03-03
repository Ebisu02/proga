#include "include.h"


/*
1.��������� ������� malloc(), �������� ������ ��� ���������� ������������ ������ b[n] (n ������� � ����������).
  ��������� ��� ������ ���������� ������� � ���������  -50 � 50.
  ��������  ������������ ������ c[m], ���������� ������������� ����� ������� b, �  ������������ ������ d[k], ���������� ������������� �����.
  m � k ������ ���� ����� ���������� ������������� � ������������� �����. ������� �������� ������ � ���������� �������. ���������� ������.
2.��������� �������� new, �������� ������ ��� ���������� ������������ ������ a[n] (n ������� � ����������) � ������ ���������� b[n].
  ��������� ������ a ������������� ���������� �������,  �  ������ b �������� ��������� ������� a. ������������� ������ �� �����������, ���������  ������ ���������� .
  �������� ������ ���������� �� ������. ������� ��������  � ��������������� ������. ���������� ������.
3.������ � ���������� ����� n, ��������� � ������� � ������� ��������� ������� �����������(�������  �������� ��������������) ������� ����� � �������� �� 2 �� n.
  ������������ ������������ ������ ������� n.
*/
void ShakerSort(double* arr, int size)
{
	int left = 0, right = size - 1;
	int flag = 1;
	while ((left < right) && flag > 0)
	{
		flag = 0;
		for (int i = left; i < right; i++)
		{
			if (arr[i] > arr[i + 1])
			{
				swap(arr[i], arr[i + 1]);
				flag = 1;
			}
		}
		right--;
		for (int i = right; i > left; i--)
		{
			if (arr[i - 1] > arr[i])
			{
				swap(arr[i], arr[i - 1]);
				flag = 1;
			}
		}
		left++;
	}
	cout << "\n";
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
}

void lab_3_1() {
	cout << "\n\nEx.1\n\n";
	int size = 10;
	int* arr;
	arr = (int*)malloc(size * sizeof(int));
	if (arr == NULL) {
		cout << "\nError\n";
		return;
	}
	cout << "\nOur array:\n";
	int size_pos = 0, size_neg = 0;
	for (int i = 0; i < size; ++i) {
		*(arr + i) = rand() % 101 - 50;
		cout << *(arr + i) << " ";
		if (*(arr + i) >= 0)
			++size_pos;
		else
			++size_neg;
	}
	int* arr_pos;
	arr_pos = (int*)malloc(size_pos * sizeof(int));
	int* arr_neg;
	arr_neg = (int*)malloc(size_neg * sizeof(int));
	for (int i = 0, j = 0, k = 0; i < size; ++i) {
		if (*(arr + i) >= 0) {
			*(arr_pos + j) = *(arr + i);
			++j;
		}
		else {
			*(arr_neg + k) = *(arr + i);
			++k;
		}
	}
	cout << "\nArray with Negative numbers:\n";
	for (int i = 0; i < size_neg; ++i) {
		cout << *(arr_neg + i) << " ";
	}
	cout << "\nArray with Positive numbers:\n";
	for (int i = 0; i < size_pos; ++i) {
		cout << *(arr_pos + i) << " ";
	}
	free(arr); 
	free(arr_pos); 
	free(arr_neg);
	return;
}

void lab_3_2() {
	cout << "\n\n\n" << "Ex. 2\n\n";
	srand(time(NULL));
	int size = 10;
	/*cout << "\nEnter a size for array, please\n";
	cin >> size;*/
	double* arr;
	arr = new double[size];
	cout << "Our array\n";
	for (int i = 0; i < size; ++i) {
		*(arr + i) = 0.01 * ((rand() % 100) - 50);
		cout << *(arr + i) << " ";
	}
	double* arr_link;
	arr_link = new double[size];
	cout << "\nLinks:\n";
	for (int i = 0; i < size; ++i) {
		arr_link[i] = *&arr[i];
		cout << &arr_link[i] << " ";
	}
	/*
	double** arr_link = &arr;
	cout << "\nLinks:\n";
	for (int i = 0; i < size; ++i) {
		cout << *(arr_link + i) << " ";
	}
	cout << "\nSorted array:\n";
	ShakerSort(arr_link, size);
	*/
	cout << "\nSorted array:";
	ShakerSort(arr_link, size);
	cout << "\nOriginal array\n";
	for (int i = 0; i < size; ++i) {
		cout << *(arr + i) << " ";
	}
	delete[] arr;
	delete[] arr_link;
	return;
}


void lab_3_3() {
	cout << "\n\nEx. 3\n\n";
	int n = 100;
	/*
	cout << "Enter a variable \"n\" ";
	cin >> n;
	*/
	bool* arr;
	arr = new bool[n];
	// ��������� ������������ ������ ���������� true
	for (int i = 2; i < n; ++i) {
		*(arr + i) = true;
	}
	// ���� ������� ����� �� ��������� ������ ����������
	cout << "Prime numbers in a range from 2 to " << n << ":\n";
	for (int i = 2; i < n; ++i) {
		if (*(arr + i) == true) {
			cout << i << " ";
			for (int j = 2; j * i < n; ++j) {
				*(arr + (j * i)) = false;
			}
		}
	}
	delete[] arr;
	return;
}

void lab_3() {
	lab_3_1();
	lab_3_2();
	lab_3_3();
	return;
}