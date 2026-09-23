// 2. Выполнить вывод суммы, произведения и разности с использованием следующих спецификаций преобразования функции printf(): а) %d; б) %10d; в) %-10d.

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
	printf("%d * %10d = %d\n", a, b, result_mult);
	printf("%d - %-10d = %d\n", a, b, reslt_minus);

	return 0;
}
