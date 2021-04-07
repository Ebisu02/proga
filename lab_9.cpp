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
	string str = { "ABC" };
	cout << str[0] << str[1] << str[2];
	return;
} 

void lab_9_2() {
	
	return; 
}

void lab_9() {
	lab_9_1();
	return; 
}