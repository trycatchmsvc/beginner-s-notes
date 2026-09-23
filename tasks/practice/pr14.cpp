//В каждой строке исходного текста содержится корректно заданная дата в формате «dd.mm.yy», где dd — день, mm — месяц, 
// yy — год. Получить строку с датой, отстоящей от заданной на n дней вперёд, в том же формате
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int* get_date(const string &date);
void my_task(std::istream& ist, std::ostream& ost);

int main() {

	string inp_path = "input.txt";
	string out_path = "output.txt";
	ifstream ist(inp_path);
	ofstream ost(out_path);

	my_task(ist, ost);

	ist.close();
	ost.close();
	return 0;
}

int* get_date(const string &date) {
	int day, month, year;
	int pointer_date = 0;
	string buffer = "";

	for (int i{ 0 }; i != date.length(); i++) {
		if (i == date.length() - 1) {
			buffer = buffer + date[i];
			year = stoi(buffer);
		}
		if (date[i] != '.') {
			buffer = buffer + date[i];
		}
		else {
			if (pointer_date == 0) {
				day = stoi(buffer);
			}
			if (pointer_date == 1) {
				month = stoi(buffer);
			}
			pointer_date++;
			buffer = "";
		}
	}
	int arr[3] = { day, month, year };
	return arr;
}

void my_task(std::istream& ist, std::ostream& ost) {
	char buffer[100] = "";
	
	while (ist.getline(buffer, 100)) {
		
		string date = string(buffer);
		
		int days = get_date(date)[0];
		int month = get_date(date)[1];
		int year = get_date(date)[2];
		
		int plus_days = 3;

		cout << "day: " << days << endl << "month: " << month << endl << "year: " << year << endl;

		int day = days + plus_days;

		while (plus_days != 0) {

			if (month <= 7) {
				if (month % 2 != 0 && month != 2) {
					if (day > 31) {
						day = day - 31;
						plus_days = plus_days - (31 - days);
						month++;
					}
					else {
						plus_days = 0;
					}
				}
				else if (month == 2 and (year % 4 == 0 and (year % 100 != 0 or year % 400 == 0))) {
					if (day > 29) {
						day = day - 29;
						plus_days = plus_days - (29 - days);
						month++;
					}
					else {
						plus_days = 0;
					}

				}
				else if (month == 2 and year % 4 != 0) {
					if (day > 28) {
						day = day - 28;
						plus_days = plus_days - (29 - days);
						month++;
					}
					else {
						plus_days = 0;
					}

				}
				else if (month % 2 == 0 && month != 2) {
					if (day > 30) {
						day = day - 30;
						plus_days = plus_days - (30 - days);
						month++;
					}
					else {
						plus_days = 0;
					}
				}
			}
			else if (month >= 8) {
				if (month % 2 == 0) {
					if (day > 31) {
						day = day - 31;
						plus_days = plus_days - (31 - days);
						month++;
					}
					else {
						plus_days = 0;
					}
				}
				else {
					if (day > 30) {
						day = day - 30;
						plus_days = plus_days - (30 - days);
						month++;
					}
					else {
						plus_days = 0;
					}
				}
			}
			if (month > 12) {
				year++;
				month = 1;
			}
		}
		ost << day << '.' << month << '.' << year << endl;
	}
}