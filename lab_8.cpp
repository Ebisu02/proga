#include "include.h"

struct School {
	int sch_num; // Number of school
	int am_std_dsch; // Amount of students what done with school
	int am_std_univ; // Amount of students what join to the university after school
	float proc_un;
};

void IndexSort(School arr[], int size, int indexArr[]) {
	for (int i = 0; i < size; ++i) {
		indexArr[i] = i;
	}
	for (int i = 0; i < size; ++i) {
		for (int j = i + 1; j < size - i; ++j) {
			if
		}
	}
	return;
}

void lab_8_1() {
	const int size = 10;
	School info[10];
	srand(time(0));
	// Формируем массив записей 
	for (int i = 0, j = 11000; i < size; ++i, j -= 1000) {
		info[i].sch_num = rand() % 100 + 1;
		info[i].am_std_dsch = j;
		info[i].am_std_univ = j / (rand() % 10 + 2);
		info[i].proc_un = (info[i].am_std_dsch / info[i].am_std_univ) * 100;
	}
	int IndexArray[size];
 }

void lab_8() {

}