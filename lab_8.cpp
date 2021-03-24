#include "include.h"

struct School {
	int sch_num; // Number of school
	int am_std_dsch; // Amount of students what done with school
	int am_std_univ; // Amount of students what join to the university after school
};

void lab_8_1() {
	const int size = 10;
	School info[10];
	srand(time(0));
	// Формируем массив записей 
	for (int i = 0; i < size; ++i) {
		info[i].sch_num = rand() % 100 + 1;
		info[i].am_std_dsch = info[i].sch_num + rand() % 100 + 1;
		info[i].am_std_univ = info[i].am_std_dsch / (rand() % 5 + 1);
	}

}

void lab_8() {

}