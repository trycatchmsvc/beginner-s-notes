//Дополнительное упражнение 2 (по вариантам, 100% — отл.)
//Разработать, отладить, продемонстрировать и защитить преподавателю программу, 
// которая для произвольного числа x, введенного с клавиатуры, вычисляет значение y
// по следующей формуле : y = f1(x) + f2(x),
//где, f1(x) и f2(x) вычисляются по формулам из табл. 2 согласно вариантам.
// Вычисление f1(x) и f2(x) оформить как функции.
#include <iostream>
#include <cmath>

float f1(float x);
float f2(float x);

int main() {
	float x;
	std::cout << "x" << std::endl;
	std::cin >> x;
	std::cout << f1(x) + f2(x) << std::endl;
	return 0;
}

float f1(float x) {
	return cbrt(30 * sin(pow(x, 2)));
}

float f2(float x) {
	return (pow(2, x) + (2.7 * pow(10, 5)));
}