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

	for (int i = strlen(str); i > strlen(str_2) - 1; i--) { // проходимся по 1 строке назад

		string str_check = ""; // записываем временную строку для сравнения

		for (int j = strlen(str_2); j > 0; j--) { // составляем строку
			str_check += str[i - j]; // добавляем значение в временную строку
		}

		if (str_2 == str_check) { // проверяем схожесть строки
			str[strlen(str) - strlen(str_2)] = '\0'; // заменяем на детерминирующий ноль
		}
	}
}