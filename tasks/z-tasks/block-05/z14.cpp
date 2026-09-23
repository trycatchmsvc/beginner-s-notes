//4. Дано натуральное число N и действительное число x. Определить P=∏i=1N2xi. 
//Проверочные значения : 1) N = 4, x = 2 ⇨ P = 16384; 2) N = 5, x = 1, 5 ⇨ P = 14012, 6.

#include <iostream>
#include <cmath>
using namespace std;

double factorial(double n, double x);

int main() {
	double x, n;
	
	cout << "N X" << endl;
	cin >> n >> x;
	cout << factorial(n, x) << endl;

	return 0;
}

double factorial(double n, double x) {
	double last_value = 1, i = 1, res = 0;

	while (i <= n) {
		last_value = last_value * 2 * pow(x, i);
		i++;
	}

	return last_value;
}