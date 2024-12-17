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