//28. Написать функцию void rstrip(char *s, const char *chars), которая удаляет
// из конца строки s символы, входящие в строку chars.

#include <iostream>
using namespace std;

void rstrip(char* str, const char* str_2);

int main() {

	char s[] = "All work and no play makes Jack a dull boy :))";

	char chars[] = ":))";

	rstrip(s, chars);

	cout << s << endl;

	return 0;
}

void rstrip(char* str, const char* str_2) {
	for (int i{(int)strlen(str) }; i >= strlen(str) - strlen(str_2); i--) {
		for (int j{ 0 }; j < strlen(str_2); j++) {
			if (str[i] == str_2[j]) {
				str[i] = ' ';
			}
		}

	}
}