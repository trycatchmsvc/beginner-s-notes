//29. Написать функцию void strip(char *s, const char *chars), 
// которая удаляет из начала и конца строки s символы, входящие в строку chars.
#include <iostream>
using namespace std;

void displacement(char* array, const int& index);
void strip(char* s, const char* chars);

int main() {

	char string_array[] = "All work and no play makes Jack a dull boy: g) a)";
	char del_arr[] = "All :))";

	strip(string_array, del_arr);
	cout << string_array;

	return 0;
}


void displacement(char* array, const int& index) {
	for (int i{ index }; array[i] != '\0'; i++) {
		array[i] = array[i + 1];
	}
}

void strip(char* s, const char* chars) {
	for (int del_point{ 0 }; chars[del_point] != ' '; del_point++) { // Удаление из начала строки
		for (int i{ 0 }; i < strlen(chars); i++) {
			if (s[i] == chars[del_point]) {
				displacement(s, i);
				break;
			}
		}
	}
	while (s[0] == ' ') {
		displacement(s, 0);
	}
	for (int del_point{ (int)strlen(chars)}; chars[del_point] != ' '; del_point--) { //Удаление с конца строки
		for (int i{ (int)strlen(s) }; i > 0; i--) {
			if (s[i] == chars[del_point]) {
				displacement(s, i);
				break;
			}
		}
	}
}