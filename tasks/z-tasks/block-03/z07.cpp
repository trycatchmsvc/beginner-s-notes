//7. Даны числа a, b, c, d, которые могут быть равны 0 или 1. Определить, какое число встречается чаще.
// Алгоритм определения оформить как функцию int find_most_frequent(int a, int b, int c, int d). 
// Функция должна возвращать: 0, если 0 встречается чаще; 1, если 1 встречается чаще; -1, 
// если 0 и 1 встречаются одинаково часто.
#include <iostream>
#include <string>
using namespace std;

int find_most_frequent(int a, int b, int c, int d);

int main() {
	int a, b, c, d, res;
	cout << "a b c d\n";
	cin >> a >> b >> c >> d;
	res = find_most_frequent(a, b, c, d);
	cout << res << endl;
	return 0;
}

int find_most_frequent(int a, int b, int c, int d) {
	if ((a + b + c + d) > 2) {
		return 1;
	}
	else if ((a + b + c + d) < 2) {
		return 0;
	}
	else {
		return -1;
	}
}


