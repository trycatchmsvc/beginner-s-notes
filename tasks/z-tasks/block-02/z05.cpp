//5. Определить взаимное расположение отрезков числовой прямой A = [a1; a2], B = [b1; b2], 
// выбирая один и только один из следующих вариантов (перечислены по убыванию приоритета):
// 1) A равно B; 2) A внутри B; 3) B внутри A; 4) нет пересечение; 5) другое пересечение.

#include <iostream>
#include <locale>
#include <math.h>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	float a1, a2, b1, b2;
	cout << "a1 a2 b1 b2" << endl;
	cin >> a1 >> a2 >> b1 >> b2;

	if (a1 == b1 && a2 == b2) {
		cout << "A равно B" << endl;
	}
	else if ((b1 < a1 and a1 < b2) && (b1 < a2 and a2 < b2)) {
		printf("A внутри B");
	}	
	else if ((a1 < b1 and b1 < a2) && (a1 < b2 and b2 < a2)) {
		printf("B внутри A");
	}
	else if (a2 < b1 || b2 < a1) {
		printf("Нет пересечений");
	}
	else {
		printf("Другое пересечение");
	}
	return 0;
	}