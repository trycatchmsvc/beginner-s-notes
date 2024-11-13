//15. Дано натуральное число N. Определить S=∑i=1Ni∗s(i), где s(i)={1,−1если i — чётноеиначе.
//Проверочные значения : 1) N = 7 ⇨ S = -4; 2) N = 10 ⇨ S = 5.

#include <iostream>
using namespace std;

double ai(int i);

int main() {
	double s = 0, n;
	cin >> n;
	for (double i{ 1 }; i != n + 1; i++) {
		s += ai(i);
	}
	cout << s;
	return 0;
}

double ai(int i) {
	double res;
	if (i % 2 == 0) {
		res = i * 1;
	}
	else {
		res = i * (-1);
	}
	return res;
}