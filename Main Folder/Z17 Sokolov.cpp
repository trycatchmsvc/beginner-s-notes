//17. Протабулировать функцию f(x)=5x+2 на отрезке [a;b] с шагом s. Вычисление f(x) оформить
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
	double n = a;
	
	while (a < b) {
		cout << setprecision(3) << setw(15) << fixed << a;
		a += s;
	}
	cout << endl;
	while (n < b) {
		cout << setprecision(5) << setw(15) << scientific << f(n);
		n += s;
	}
	return 0;
}

double f(double x) {
	return 5 * x + 2;
}