//11. Дано целое число s. Вывести диагональную линию из символов «*» из левого верхнего угла 
// в области из s строк и s столбцов. Вывод линии оформить как функцию void print_diag(int s).
#include <iostream>
#include <string>
using namespace std;

void print_diag(int s);

int main() {
	int s;
	cin >> s;
	print_diag(s);
	return 0;
}

void print_diag(int s) {
	string ls = "*";
	int a = 0;
	cout << "*" << endl;
	while (a != s - 1) {
		ls = " " + ls;
		cout << ls << endl;
		a++;
	}
}