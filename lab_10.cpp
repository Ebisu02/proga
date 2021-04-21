#include "include.h"

void lab_10_1() {
	srand(time(NULL));
	int N = 10;
	const int size_str_example = 5;


	// Example and some words for comparing (for gl.txt and sogl.txt)
	string exampleWords[size_str_example] = { "hi" , "ugly" ,  "woman" , "archer" , "code"  };
	char glas[11] = { "AEIOUaeiou" };
	char sogl[44] = { "BCDFGHJKLMNPQRSTVWXYZbcdfghjklmnpqrstvmwxyz" };


	// Prepare out var's
	ofstream fout_file;
	ofstream fout_file_gl;
	ofstream fout_file_sogl;
	string file = "out.txt";
	string file_gl = "gl.txt";
	string file_sogl = "sogl.txt";


	// Fill the out.txt
	fout_file.open(file);
	if (!fout_file.is_open()) {
		// !ERROR
		cout << "\nError of opening file\n";
	}
	else {
		for (int i = 0; i < N; ++i) {
			fout_file << exampleWords[rand() % size_str_example] << "\n";
		}
	}
	cout << "\nWords from main file:\n";
	fout_file.close();


	// out in Console what we have in out.txt
	ifstream fin_file;
	fin_file.open(file);
	if (!fin_file.is_open()) {
		// !ERROR
		cout << "\nError of opening file\n";
	}
	else {
		string str; // buf
		while (!fin_file.eof()) {
			str = "";
			getline(fin_file, str);
			cout << str << "\n";
		}
	}
	fin_file.close();


	// Fill the gl.txt and sogl.txt from out.txt
	fin_file.open(file);
	fout_file_gl.open(file_gl);
	fout_file_sogl.open(file_sogl);
	if (!fin_file.is_open() && !fout_file_sogl.is_open() && !fout_file_gl.is_open()) {
		// !ERROR
		cout << "\nError of opening file\n";
	}
	else {
		string str; // buf
		while (!fin_file.eof()) {
			str = "";
			bool flag = false;
			getline(fin_file, str);
			if (!flag) {
				for (int i = 0; i < 10; ++i) {
					if (str[0] == glas[i]) {
						fout_file_gl << str << "\n";
						flag = true;
						break;
					}
				}
				for (int i = 0; i < 44; ++i) {
					if (str[0] == sogl[i]) {
						fout_file_sogl << str << "\n";
						flag = true;
						break;
					}
				}
			}
		}
	}
	fin_file.close();
	fout_file_gl.close();
	fout_file_sogl.close();


	// Out in console what we have in gl.txt and sogl.txt
	// in gl.txt
	cout << "\nWords in gl.txt:\n";
	ifstream fin_file_gl;
	fin_file_gl.open(file_gl);
	if (!fin_file_gl.is_open()) {
		// !ERROR
		cout << "\nError of opening file\n";
	}
	else {
		string str; // buf
		while (!fin_file_gl.eof()) {
			str = "";
			getline(fin_file_gl, str);
			cout << str << "\n";
		}
	}
	fin_file_gl.close();
	// in sogl.txt
	cout << "\nWords in sogl.txt:\n";
	ifstream fin_file_sogl;
	fin_file_sogl.open(file_sogl);
	if (!fin_file_sogl.is_open()) {
		// !ERROR
		cout << "\nError of opening file\n";
	}
	else {
		string str; // buf
		while (!fin_file_sogl.eof()) {
			str = "";
			getline(fin_file_sogl, str);
			cout << str << "\n";
		}
	}
	fin_file_sogl.close();
	return; 
} 

void lab_10_2() {
	srand(time(NULL));
	int N = 10;
	const int size_str_example = 5;
	string exampleWords[size_str_example] = { "hi" , "ugly" ,  "woman" , "archer" , "code" };
	return;
}

void lab_10() {
	lab_10_1();
	lab_10_2();
	return;
}