//18. Протабулировать функцию f(x)=sin2(πx) на отрезке [a;b] с шагом s. 
// Вычисление f(x) оформить как функцию double f(double x). 
//Результат вывести в виде псевдографика, определяемого уравнениями :

#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double f(double x);

int main() {
	double a, b, s, scale;
	cout << "a b s scale" << endl;
	cin >> a >> b >> s >> scale;
	
	while (a < b) {
		double res = f(a);
		cout << setw(1 + res * scale) << "$" << "(" << a << ", " << res << ")" << endl;
		a += s;
	}
	return 0;
}

double f(double x) {
	return pow(sin(M_PI * x), 2);
}