//1. Определить, являются ли два заданных натуральных числа «дружественными». Два натуральных числа
// называются «дружественными», если каждое из них равно сумме всех делителей (кроме его самого) 
// другого числа (например, числа 220 и 284). Поиск суммы делителей числа оформить как функцию.

#include <iostream>
using namespace std;

void result(int x, int y, int a, int b);
int check_sum_del(int x);

int main() {
	int x, y, r1, r2;
	setlocale(LC_ALL, "Russian");
	cout << "X Y" << endl;
	cin >> x >> y;
	result(check_sum_del(x), check_sum_del(y), x, y);
	return 0;
}

int check_sum_del(int x) {
	int sum_del = 0;
	for (int i{ 1 }; i < x; i++) {
		if (x % i == 0) {
			sum_del += i;
		}
	}
	return sum_del;
}

void result(int x, int y, int a, int b) {
	if (x == b && y == a) {
		cout << "Дружественные числа " << a << " и " << b << endl;
	}
	else {
		cout << "Не Дружественные числа" << endl;
	}
}