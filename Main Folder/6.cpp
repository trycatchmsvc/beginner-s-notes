//6. Найти действительные корни квадратного уравнения ax2+bx+c=0. Если корней нет, вывести сообщение. 
// Вывести значения левой части уравнения после подстановки найденных корней.

#include <iostream>
#include <math.h>
using namespace std;

int main() {
	float a, b, c, discr, x1, x2;
	setlocale(LC_ALL, "Russian");

	cout << "a b c\n";
	cin >> a >> b >> c;
	
	discr = (pow(b, 2) - (4 * a * c));
	
	if (discr == 0) {
		x1 = ((-1) * b) / (2 * a);
		printf("x1 = %f\n", x1);
	}
	else if (discr > 0) {
		x1 = ((((-1) * b) + sqrt(discr)) / (2 * a));
		x2 = ((((-1) * b) - sqrt(discr)) / (2 * a));
		printf("x1 = %f\nx2 = %f\n", x2, x1);
	}
	else {
		cout << "Корней нет";
	}

	return 0;
}