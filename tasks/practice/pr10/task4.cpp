// 4. Модифицировать программу, заменив используемый целый тип другим целым типом (например, int на long), провести необходимые изменения в программе, возникающие в связи с этим.

#include <cstdio>
#include <iostream>
using namespace std;

int main() {
	long int a, b;
	
	printf("Input 2 numbers\n");
	scanf("%ld%ld", &a, &b);
	
	long result_sum = a + b;
	long result_mult = a * b;
	long reslt_minus = a - b;
	
	printf("%ld + %ld = %ld\n",a, b, result_sum);
	printf("%ld * %10ld = %ld\n", a, b, result_mult);
	printf("%ld - %-10ld = %ld\n", a, b, reslt_minus);

	return 0;
}
