//28. Написать функцию void rstrip(char *s, const char *chars), которая удаляет
// из конца строки s символы, входящие в строку chars.
#include <iostream>
using namespace std;

void rstrip(char* array, const char* del_symbols); // Функция опредялет схожесть символов и использует функцию displacement
void displacement(char* array, const int &index); // Функция смещает всю строку начиная с index

int main() {

	char del_str[] = "));";
	char str[] = "Hello world any )where) hold;";
	
	rstrip(str, del_str);

	cout << str << endl;

	return 0;
}

void rstrip(char* array, const char *del_symbols) {
	for (int j{ 0 }; del_symbols[j] != '\0'; j++) {
		for (int i{ (int)strlen(array) }; i != 0; i--) {
			if (array[i] == del_symbols[j]) {
				displacement(array, i);
				break;
			}
		}
	}
}

void displacement(char* array, const int &index) {
	for (int i{index}; array[i] != '\0'; i++) {
		array[i] = array[i + 1];
	}
}