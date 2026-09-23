//3. Дано натуральное число N. Определить S=∑i=1Nii+1. Вычисление ii+1 оформить как 
// функцию double ai(double i).
//Проверочные значения 1) N = 4 ⇨ S = 2, 72; 2) N = 9 ⇨ S = 7, 07.

#include <iostream>
using namespace std;

double ai(double i);

int main() {
	double s = 0, n;
	cin >> n;
	for (double i{ 1 }; i != n + 1; i++) {
		s += ai(i);
	}
	cout << s;
	return 0;
}

double ai(double i) {
	double res = (i / (i + 1));
	return res;
}