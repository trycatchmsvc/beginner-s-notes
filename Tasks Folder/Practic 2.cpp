1. Разработать программу, которая предлагает пользователю ввести два целых числа, получает числа от пользователя с помощью функции scanf() и затем печатает сумму, произведение, разность и среднее арифметическое этих чисел с помощью функции printf()

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int a, b;
	
	printf("Input 2 numbers\n");
	scanf_s("%d%d", &a, &b);
	
	int result_sum = a + b;
	int result_mult = a * b;
	int reslt_minus = a - b;
	
	printf("%d + %d = %d\n",a, b, result_sum);
	printf("%d * %d = %d\n", a, b, result_mult);
	printf("%d - %d = %d\n", a, b, reslt_minus);

	return 0;
}

2. Выполнить вывод суммы, произведения и разности с использованием следующих спецификаций преобразования функции printf(): а) %d; б) %10d; в) %-10d.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int a, b;
	
	printf("Input 2 numbers\n");
	scanf_s("%d%d", &a, &b);
	
	int result_sum = a + b;
	int result_mult = a * b;
	int reslt_minus = a - b;
	
	printf("%d + %d = %d\n",a, b, result_sum);
	printf("%d * %10d = %d\n", a, b, result_mult);
	printf("%d - %-10d = %d\n", a, b, reslt_minus);

	return 0;
}

4. Модифицировать программу, заменив используемый целый тип другим целым типом (например, int на long), провести необходимые изменения в программе, возникающие в связи с этим.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	long int a, b;
	
	printf("Input 2 numbers\n");
	scanf_s("%d%d", &a, &b);
	
	int result_sum = a + b;
	int result_mult = a * b;
	int reslt_minus = a - b;
	
	printf("%d + %d = %d\n",a, b, result_sum);
	printf("%d * %10d = %d\n", a, b, result_mult);
	printf("%d - %-10d = %d\n", a, b, reslt_minus);

	return 0;
}

