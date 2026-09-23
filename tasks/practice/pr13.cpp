//Дополнительное упражнение № 2 (по вариантам, 100% — отл.)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <locale>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	float v1, t1, v2, t2, result_v, result_t;
	
	cout << "Ввод данных: v1 t1 v2 t2" << endl;
	cout << "             ";
	scanf("%f%f%f%f", &v1, &t1, &v2, &t2);
	result_v = v1 + v2;
	result_t = (t1 * v1 + t2 * v2) / (v1 + v2);
	printf("Обьем образовавшейся смеси = %f\nТемпература данной смеси = %f", result_v, result_t);
	
	return 0;
}