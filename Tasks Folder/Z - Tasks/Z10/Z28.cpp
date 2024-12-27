//28. Написать функцию void rstrip(char *s, const char *chars), которая удаляет
// из конца строки s символы, входящие в строку chars.

#include <iostream>
using namespace std;

void rstrip(string &s, const string chars);
size_t strLen(string str);

int main() {

	string s = "All work and no play makes Jack a dull boy: g) a)";

	string chars = ":))";

	rstrip(s, chars);

	cout << s << endl;

	return 0;
}

void rstrip(string& s, const string chars) {
	int size_s = (int)strLen(s);
	int size_chars = (int)strLen(chars);

	for (int i = 0; i < size_chars; i++) {
		for (int j = strLen(s) - 1; j >= 0; j--) {
			if (s[j] == chars[i]) {
				s.erase(j, 1);
			}
		}
	}
}

size_t strLen(const string str) {
	size_t len = 0;

	for (int i{ 0 }; str[i] != '\0'; i++) {
		len++;
	}

	return len;
}