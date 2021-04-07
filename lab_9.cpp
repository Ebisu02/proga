#include "include.h"

const int size_of_grades = 4;

typedef struct infoAboutStudent {
	string surname;
	int grade[size_of_grades];
	struct infoAboutStudent *next;
}list;

template <typename T>

void index_sort(T arr[], int size, int indexArr[]) {
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
	const int size_for_examples = 4;
	string examples_Surname[size_for_examples] = { { "Pertsev" }, { "Ivanov" }, { "Petrov" }, { "Fedorov" } };
	int examples_Grades[size_for_examples] = { { 2 }, { 3 }, { 4 }, { 5 } };
	list List;
	srand(time(nullptr));
	const int size = 5;
	int link;
	while (int i = 0 < size) {
		for (int j = 0; j < size_of_grades; ++j) {
			List.grade[j] = examples_Grades[rand() % size_for_examples];
		}
		List.surname = examples_Surname[rand() % size_for_examples];

	}
	return;
}

void lab_9_2() {

	return;
}

void lab_9() {
	lab_9_1();
	return;
}
