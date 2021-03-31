#include "include.h"

const int size_of_grades = 4;

typedef struct infoAboutStudent {
	string surname;
	int grade[size_of_grades];
}list;

void index_sort(list arr[], int size, int indexArr[]) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[indexArr[j]].surname[0] > arr[indexArr[j + 1]].surname[0]) {
				swap(indexArr[j], indexArr[j + 1]);
			}
		}
	}
	return;
}

void lab_9_1() {
	cout << "\n\nEx.1\n";
	const int size = 10;
	list arr[size];
	setlocale(LC_ALL, "RUSSIAN");
	int indexArr[size];
	for (int i = 0; i < size; ++i) {
		indexArr[i] = i;
	}
	string examples[size] = { {"Иванов"}, {"Петров"}, {"Смирнов"}, {"Кашигин"}, {"Калмыков"},
							  {"Федеров"}, {"Ким"}, {"Чын"}, {"Осипов"}, {"Дрон"} };
	cout << "List:";
	for (int i = 0; i < size; ++i) {
		arr[i].surname = examples[i];
		cout << "\n" << arr[i].surname;
		for (int j = 0; j < size_of_grades; ++j) {
			arr[i].grade[j] = rand() % 4 + 2;
			cout << " " << arr[i].grade[j];
		}
	}
	index_sort(arr, size, indexArr);
	cout << "\n\n\nSorted list:";
	for (int i = 0; i < size; ++i) {
		cout << "\n" << arr[indexArr[i]].surname;
		for (int j = 0; j < size_of_grades; ++j) {
			cout << " " << arr[indexArr[i]].grade[j];
		}
	}
	cout << "\n";
	return;
} 

void lab_9_2() {
	
	return; 
}

void lab_9() {
	lab_9_1();
	return; 
}