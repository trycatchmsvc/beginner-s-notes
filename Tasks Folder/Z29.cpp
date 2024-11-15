//29. Написать функцию void strip(char *s, const char *chars), которая удаляет из начала 
//и конца строки s символы, входящие в строку chars.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

void rstrip(char* str, const char* str_2);

int main() {

	char s[] = "All work and no play makes Jack a dull boy :))";

	char chars[] = "All :))";

	rstrip(s, chars);

	cout << s << endl;

	return 0;
}

void rstrip(char* str, const char* str_2) {

	int pos = 0;
	for (int i{ 0 }; i < strlen(str_2); i++) {
		for (int j{ (int)strlen(str_2) - 1 }; str_2[j] != '\0'; j--) {
			if (str[i] == str_2[j]) {
				str[i] = ' ';
				pos++;
			}
		}
	}

	for (int i{ 0 }; i < (int)strlen(str); i++) {
		str[i] = str[i + pos];
	}

	for (int i{(int)strlen(str) }; i >= strlen(str) - strlen(str_2); i--) {
		for (int j{(int)strlen(str_2)-1}; str_2[j] != '\0'; j--) {
			if (str[i] == str_2[j]) {
				str[i] = ' ';
			}
		}
	}
}