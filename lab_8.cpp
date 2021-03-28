#include "include.h"

struct School {
	int school_number; // Number of school
	int amount_school; // Amount of students what done with school
	int amount_university; // Amount of students what join to the university after school
	double procent_university;
};

void IndexSort(School arr[], int size, int indexArr[]) {
	for (int i = 0; i < size - 1; i++) {
		for (int j = 0; j < size - i - 1; j++) {
			if (arr[indexArr[j]].procent_university < arr[indexArr[j + 1]].procent_university) {
				swap(indexArr[j], indexArr[j + 1]);
			}
		}
	}
	return;
}

void lab_8_1() {
	const int size = 10;
	School info[10];
	srand(time(NULL));
	cout << "\nEx. 1\n\n";
	// Формируем массив записей 
	for (int i = 0, j = 11000; i < size; ++i, j -= 1000) {
		info[i].school_number = rand() % 100 + 1;
		info[i].amount_school = j;
		info[i].amount_university = j / (rand() % 10 + 2);
		info[i].procent_university = (( (double) info[i].amount_university / (double) info[i].amount_school) * 100);
	}
	int IndexArray[size];
	for (int i = 0; i < size; ++i) {
		IndexArray[i] = i;
	}
	// Index Array after sort
	IndexSort(info, size, IndexArray);
	cout << "\n\nIndex Array:\n";
	for (int i = 0; i < size; ++i) {
		cout << IndexArray[i] << " ";
	}
	// School structure array after sort
	cout << "\n\nSchool Number|Amount students|Amount in university|Procent";
	for (int i = 0; i < size; ++i) {
		cout << "\n" << info[IndexArray[i]].school_number << "\t     |" << info[IndexArray[i]].amount_school
			 << "\t     |"  << info[IndexArray[i]].amount_university << "\t          |" << info[IndexArray[i]].procent_university;
	}
	cout << "\n";
}

struct Hostel {
	int room_number;
	int square_of_room;
	int amount_of_living;
	string faculty;
};

void lab_8_2() {
	cout << "\nEx. 2\n\n";
	srand(time(NULL));
	const int size = 10;
	Hostel arr[size];
	const int size_for_examples = 4;
	string examples[size_for_examples] = { {"Math"}, {"Filology"}, {"Development"}, {"Physics"} };
	for (int i = 0; i < size; ++i) {
		arr[i].room_number = rand() % 100 + 1;
		arr[i].square_of_room = 32 + (rand() % 10 - 10);
		arr[i].amount_of_living = rand() % 8 + 1;
		arr[i].faculty = examples[rand() % 4];
		//cout << arr[i].faculty << " ";
	}
	//cout << "\n\n";
	set<string> faculty_dif;
	for (int i = 0; i < size; ++i) {
		faculty_dif.insert(arr[i].faculty);
	}
	cout << "Amount of different faculty's: " << faculty_dif.size() << "\n";
	//cout << "\n\nFaculty \t Amount_of_rooms \t Amount_of_students \t Square_on_student";
	for (auto& i : faculty_dif) {
		int amount_of_rooms = 0;
		int amount_of_students = 0;
		int square_all = 0;
		for (int j = 0; j < size; ++j) {
			if (i == arr[j].faculty) {
				++amount_of_rooms;
				amount_of_students += arr[j].amount_of_living;
				square_all += arr[j].square_of_room;
			}
		}
		double sqaure_on_student = (double)square_all / (double)amount_of_students;
		cout << "\nFaculty: " << i
			 << "\nAmount of rooms: " << amount_of_rooms
			 << "\nAmount of students: " << amount_of_students
			 << "\nSqaure on one Student: " << sqaure_on_student << "\n";
	}
	return;
}

void lab_8() {
	lab_8_1();
	lab_8_2();
	return;
}