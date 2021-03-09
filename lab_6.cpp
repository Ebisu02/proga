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

void maleOrFemale() {
	return;
}

void lab_6_2() {

	return;
}

void lab_6() {
	cout << "\n\n\nEx. #1\n\n";
	lab_6_1();
	return;
}