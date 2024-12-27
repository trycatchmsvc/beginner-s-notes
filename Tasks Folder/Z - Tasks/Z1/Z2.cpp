//2. Дано количество людей num_people и количество мест в одном автобусе num_seats. 
// Определить, сколько понадобится автобусов для перевозки людей num_buses
//и сколько свободных мест в них останется num_free_seats.

#include <iostream>
#include <locale>
#include <cmath>
using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");
	double num_people, num_seats, ceil_result, result, num_free_seats;
	cout << "Введите колличество людей, а затем колличество мест в автобусе ";
	cin >> num_people >> num_seats;
	ceil_result = ceil((num_people / num_seats));
	num_free_seats = ceil_result * num_seats - num_people;
	cout << "Для перевозки людей понадобится " << ceil_result << " автобусa(ов)" << endl;
	cout << "Колличество свободных мест " << num_free_seats << endl;
	return 0;
}
