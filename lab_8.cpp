#include "include.h"

struct School {
	int sch_num; // Number of school
	int am_std_dsch; // Amount of students what done with school
	int am_std_univ; // Amount of students what join to the university after school
	float pr_post = (am_std_dsch / am_std_univ) * 100;
};

void indexSort(School arr[], int size, int* arr_ind) {
	for (int i = 0; i < size; i++)
	{
		arr_ind[i] = i;
	}
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; ++j)
		{
			if (arr[arr_ind[i]].pr_post < arr[arr_ind[j]].pr_post)
			{
				swap(arr_ind[i], arr_ind[j]);
			}
		}
	}
	return;
}

void lab_8_1() {
	const int size = 10;
	School info[10];
	srand(time(0));
	// Filling our array
	for (int i = 0; i < size; ++i) {
		info[i].sch_num = rand() % 100 + 1;
		info[i].am_std_dsch = info[i].sch_num + rand() % 100 + 1;
		info[i].am_std_univ = info[i].am_std_dsch / (rand() % 5 + 1);
	}
	int* arr; 
	indexSort(info, size, arr);
	return;
}

void lab_8() {

}
