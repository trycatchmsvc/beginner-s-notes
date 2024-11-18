//28. Написать функцию void rstrip(char *s, const char *chars), которая удаляет
// из конца строки s символы, входящие в строку chars.

#include <iostream>
using namespace std;

void rstrip(char* str, const char* str_2);
size_t strLen(string str);

int main() {

	string s = "All work and no play makes Jack a dull boy: g) a)";

	string chars = ":))";

	int size_s = (int)strLen(s);
	int size_chars = (int)strLen(chars);
	
	//cout << size_chars;

	int pointer = 0;
	string str_val = "";
	string str_arr[255] = {};
	
	for (int i = 0; i < size_chars; i++) { 
		for (int j = (int)s.length() - 1; j >= 0; j--) { 
			if (s[j] == chars[i]) {             
				s.erase(j, 1);                    
			}
		}
	}

	cout << s << endl;

	return 0;
}

void rstrip(char* str, const char* str_2) {
	for (int i{ (int)strlen(str) }; i >= strlen(str) - strlen(str_2); i--) {
		for (int j{ 0 }; j < strlen(str_2); j++) {
			if (str[i] == str_2[j]) {
				str[i] = ' ';
			}
		}

	}
}

size_t strLen(const string str) { //Realise func strlen
	size_t len = 0;

	for (int i{ 0 }; str[i] != '\0'; i++) {
		len++;
	}

	return len;
}