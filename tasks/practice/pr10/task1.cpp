// 1. Разработать программу, которая предлагает пользователю ввести два целых числа, получает числа от пользователя с помощью функции scanf() и затем печатает сумму, произведение, разность и среднее арифметическое этих чисел с помощью функции printf()

#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	int a, b;
	
	printf("Input 2 numbers\n");
	scanf("%d%d", &a, &b);
	
	int result_sum = a + b;
	int result_mult = a * b;
	int reslt_minus = a - b;
	
	printf("%d + %d = %d\n",a, b, result_sum);
	printf("%d * %d = %d\n", a, b, result_mult);
	printf("%d - %d = %d\n", a, b, reslt_minus);

	return 0;
}
