#include "include.h"
#define MASSIV_SIZE 10

void pos_num(string s) {
	if (s.find('-') == -1) {
		cout << "\nOur positive numbers from this string\n";
		cout << s;
	}
	else {
		s.erase(s.find('-'), 2);
		if (s.find('0') != -1)
			s.erase(s.find('0'), s.find('0'));
		return pos_num(s);
	}
}

void lab_2_1() {
	srand(time(NULL));
	cout << "\n\nEx.1\n";
	const int size = 10;
	string s;
	for (int i = 0; i < size; ++i) {
		if (i == size - 1) {
			s += to_string(0);
		}
		if (i == 0) {
			s = to_string(rand() % 8 - 4);
		}
		if (i > 0 && i < size - 1) {
			s += to_string(rand() % 8 - 4);
		}
	}
	cout << "\nOur string\n";
	for (auto& i : s) {
		cout << i;
	}
	pos_num(s);
	return;
}

void pos_and_neg_num(int m[], int size) {
	if (size < MASSIV_SIZE - 1) {
		if (m[size] < 0)
			cout << m[size] << " ";
		pos_and_neg_num(m, size + 1);
		if (m[size] >= 0)
			cout << m[size] << " ";
	}
}

void lab_2_2() {
	cout << "\n\nEx.2\n\n";
	cout << "Our massiv\n";
	const int size = 10;
	int m[size];
	srand(time(NULL));
	for (int i = 0; i < size; ++i) {
		m[i] = rand() % 8 - 4;
		if (m[i] == 0)
			while (m[i] == 0)
				m[i] = rand() % 8 - 4;
		cout << m[i] << " ";
	}
	cout << "\n";
	pos_and_neg_num(m, 0);
}

void bin_2(int a, vector<int>& result) {
	if (a / 2 == 0) {
		result.push_back(a % 2);
		reverse(result.begin(), result.end());
		return;
	}
	else {
		result.push_back(a % 2);
		return bin_2(a / 2, result);
	}
}

void lab_2_3() {
	cout << "\n\nEx.3\n\n";
	cout << "Our number in 10 system\n";
	srand(time(NULL));
	int num = rand() % 100;
	vector <int> bin;
	cout << num;
	cout << "\nOur number in 2 system:\n";
	bin_2(num, bin);
	for (auto i : bin)
		cout << i;
	return;
}


void lab_2() {
	lab_2_1();
	lab_2_2();
	lab_2_3();
}