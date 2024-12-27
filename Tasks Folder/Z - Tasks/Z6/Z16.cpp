//16. Протабулировать функцию f(x)=2x2−3x+1 на отрезке [a;b] с шагом s. Вычисление f(x) оформить 
// как функцию double f(double x).

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

double f(double x);

int main() {

	double a, b, s;
	cout << "a b s" << endl;
	cin >> a >> b >> s;

	while (a < b) {
		cout << setw(10) << fixed << a << scientific << setw(15) << f(a) << endl;
		a += s;
	}

	return 0;
}

double f(double x) {
	return 2 * pow(x, 2) - 3 * x + 1;
}