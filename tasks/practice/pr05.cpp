//Разработать программу, решающую следующую задачу: протабулировать функцию f(x) на интервале [A, B] 
// с шагом h и провести вычисления согласно вариантам в таблице:

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

double f(double x);

int main() {
	double a, b, h, x0, y0;
	double max_d = 0;
	double max_x, max_y;
	cout << "a b h x0 y0" << endl;
	cin >> a >> b >> h >> x0 >> y0;
	double b1 = a;
	
	while (a < b) {
		double y = f(a);
		double d = sqrt(pow((a - x0), 2) + pow((f(a) - y0), 2));
		if (d > max_d) {
			max_d = d;
			max_y = f(a);
			max_x = a;
		}
		a += h;
	}

	a = b1;

	while (a < b) {
		double d = sqrt(pow((a - x0), 2) + pow((f(a) - y0), 2));
		if (d == max_d) {
			cout << a << " " << f(a) << "*" << endl;
		}
		else {
			cout << a << " " << f(a) << endl;
		}
		a += h;
	}
	
	
	//cout << "Max length = " << max_d << " x = " << max_x << " y = " << max_y << endl;

	return 0;
}

double f(double x) {
	return pow(M_E, x) - 10 * x;
}