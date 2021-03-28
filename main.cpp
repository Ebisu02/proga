#include "include.h"

int main() {
	int ex = 0;
	cout << "\nenter a numb of lab\n";
	cin >> ex;
	switch (ex) {
	case 1: cout << "\n\n\n\t\t\t\tLab. #1\n";
			lab_1();
			break;
	case 2: cout << "\n\n\n\t\t\t\tLab. #2\n";
			lab_2();
			break;
	case 3: cout << "\n\n\n\t\t\t\tLab. #3\n";
			lab_3();
			break;
	case 4: cout << "\n\n\n\t\t\t\tLab. #4\n";
			lab_4();
			break;
	case 5:	cout << "\n\n\n\t\t\t\tLab. #5\n";
			lab_5();
			break;
	case 6: cout << "\n\n\n\t\t\t\tLab. #6\n";
			lab_6();
			break;
	case 7: cout << "\n\n\n\t\t\t\tLab. #7\n";
			lab_7();
			break;
	case 8: cout << "\n\n\n\t\t\t\tLab. #8\n";
			lab_8();
			break;
	}
	system("PAUSE");
	return 0;
}