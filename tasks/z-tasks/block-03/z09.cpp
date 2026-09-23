//9. Даны действительные числа a, b, c. Если a больше 0,5, вывести большее из чисел b, c. 
// Иначе вывести меньшее из чисел b, c. Вычисление оформить как функцию 
//float min_or_max(float a, float b, float c).

#include <iostream>
using namespace std;

float min_or_max(float a, float b, float c);

int main() {
	float a, b, c;
	cout << "a b c\n";
	cin >> a >> b >> c;
	min_or_max(a, b, c);
	return 0;
}

float min_or_max(float a, float b, float c) {
	if (a > 0.5) {
		return max(b, c);
	}
	else {
		return min(b, c);
	}
}