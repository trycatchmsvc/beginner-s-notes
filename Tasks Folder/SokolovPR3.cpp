//Дополнительное упражнение № 2 (по вариантам, 100% — отл.) 9. Дано три целых числа, 
// определяющих календарную дату (день, месяц и год) – день рождения человека. 
// Определить возраст человека в годах относительно текущей календарной даты.

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

using namespace std;

int main()
{
	int input_day, input_month, input_year, years_old;
	
	setlocale(LC_ALL, "Russian");
	
	time_t seconds = time(NULL);
	struct tm *now = localtime(&seconds);
	
	int day_now = now->tm_mday;
	int month_now = now->tm_mon;
	int year_now = now->tm_year + 1900;
	
	cout << "дд:мм::год\n";
	cin >> input_day >> input_month >> input_year;
	
	years_old = year_now - input_year;
	
	if (years_old > 1) {
		
		if (input_day > day_now && input_month > month_now) {
			cout << years_old;
		}

		else {
			years_old -= 1;
			cout << years_old--;
		}
	}
	
	else {
		cout << "Возраст меньше года // Некорректно введены данные";
	}

	return 0;
}