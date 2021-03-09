#include "include.h"

void sqrAndPer(int* a, int* b, int* c) {
	if (*a > 0 && *b > 0 && *c > 0) {
		double per = *a + *b + *c;
		double sqr = sqrt((per / 2) * ((per / 2) - *a) * ((per / 2) - *b) * ((per / 2) - *c));
		cout << "\nPerimetr = " << per;
		cout << "\nSquare = " << sqr;
		return;
	}
	else {
		//	ERROR
		cout << "\nERROR\n";
		return;
	}
}

void lab_6_1() {
	int a = 3, b = 3, c = 3;
	sqrAndPer(&a, &b, &c);
	cout << "\n";
	return;
}

/*
Написать функцию, определяющую вероятность того, что среди n детей будет m девочек или m мальчиков. 
Предусмотреть контроль входных данных. Вероятность рождения девочки p=0.45, мальчика q=1-p. Вероятность того, что из n детей будет m девочек  равна:
pd=cnm .pm.qn-m ,
для мальчиков
pm=cnm .qm.pn-m
cnm=n!/(m! *(n-m)!)   Вероятности передать через параметры-ссылки.
*/

double power(double a, int n) { // a - number , n - power
	if (n == 0) {
		return 1;
	}
	if (n > 0) {
		return a * power(a, n - 1);
	}
	if (n < 0) {
		n = -n;
		return 1. / (a * power(a, n - 1));
	}
}

double factorial(double x) {
	if (x <= 0) {
		return 1;
	}
	if (x >= 1) {
		return x * factorial(x - 1);
	}
}

void maleOrFemale(double n, double m, double c, double &pd, double &pm) {
	double p = 0.45, q = 1 - p; // p - for girl's, q - for man's
	pd = c * power(p, m) * power(q, n - m);
	pm = c * power(q, m) * power(p, n - m);
	//cout << "\npd = " << pd;
	//cout << "\npm = " << pm << "\n";
	return;
}

void lab_6_2() {
	double n = 20; //  Amount child's
	double m = 12; // M - girl's or M - man's
	double pd = 0, pm = 0; // pd - for N child's = M girl's, pm - for N child's = M man's
	double C /* from N to M*/ = factorial(n) / (factorial(m) * factorial(n - m)); // cout << "C = " << C;
	maleOrFemale(n, m, C, pd, pm);
	cout << "\npd = " << pd * 100 << "%";
	cout << "\npm = " << pm * 100 << "%" << "\n";
	return;
}

void lab_6() {
	cout << "\n\n\nEx. #1\n\n";
	lab_6_1();
	cout << "\n\n\nEx. #2\n\n";
	lab_6_2();
	return;
}