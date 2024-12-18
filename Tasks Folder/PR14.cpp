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

	int days = 28;
	int month = 11;
	int year = 2024;
	int plus_days = 4;

	cout << "day: " << days << endl << "month: " << month << endl << "year: " << year << endl;

	int day = days + plus_days;

	while (plus_days != 0) {
		if (year % 4 == 0) { // смотрим четность года для определения високосного года
			if (month <= 7) {
				if (month % 2 != 0 && month != 2) {
					if (day > 31) {
						day = day - 31;
						plus_days = (plus_days - (31 - days)) - day;
						month++;
					}
					else {
						plus_days = 0;
					}
				}
				else if (month == 2) {
					if (day > 29) {
						day = day - 29;
						plus_days = (plus_days - (29 - days)) - day;
						month++;
					}
					else {
						plus_days = 0;
					}
					
				}
				else if (month % 2 == 0 && month != 2) {
					if (day > 30) {
						day = day - 30;
						plus_days = (plus_days - (30 - days)) - day;
						month++; 
					}
					else {
						plus_days = 0;
					}
				}
			}
			else if (month >= 8){
				if (month % 2 == 0) {
					if (day > 31) {
						day = day - 31;
						plus_days = (plus_days - (31 - days)) - day;
						month++;
					}
					else {
						plus_days = 0;
					}
				}
				else {
					if (day > 30) {
						day = day - 30;
						plus_days = (plus_days - (30 - days)) - day;
						month++;
					}
					else {
						plus_days = 0;
					}
				}
			}
		}
	}