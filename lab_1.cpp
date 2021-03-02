#include "include.h"

int factorial(int x) {
	if (x <= 0) {
		cout << "\nWrong number\n";
		return 1;
	}
	if (x >= 1) {
		return x * factorial(x - 1);
	}
}

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

void lab_1() {
	cout << "\nEx. #1\n";
	cout << "\nFunction named Factorial (in test we are finding factorial for 5)\n5! = " << factorial(5) << "\n";
	cout << "\nEx. #2\n";
	cout << "\nFunction named Power (int test we are finding power -3 for 2, more simply - 2^-3)\n2^-3 = " << power(2, -3);
	return;
}