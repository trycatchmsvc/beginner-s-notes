// 1.Поменять местами значения целых переменных a и b, не используя дополнительные переменные.
#include <iostream>
using namespace std;

// решение задачи через арифметическую операцию
int main() {
	int a, b;
	cin >> a >> b;
	a = a + b;
	b = a - b;
	a = a - b;
	cout << a << ' ' << b << endl;
	return 0;
}
