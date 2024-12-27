//29. Написать функцию void strip(char *s, const char *chars), 
// которая удаляет из начала и конца строки s символы, входящие в строку chars.

#include <iostream>
using namespace std;

void strip(string& s, const string chars);
size_t strLen(string str);

int main() {

	string s = "All work and no play makes Jack a dull boy: g) a)";

	string chars = "All :))";

	strip(s, chars);

	cout << s << endl;

	return 0;
}

void strip(string& s, const string chars) {
	int size_s = (int)strLen(s);
	int size_chars = (int)strLen(chars);

	for (int i = 0; i < size_chars; i++) {
		for (int j = 0; j < strLen(s); j--) {
			if (s[j] == chars[i] and chars[i] != ' ') {
				s.erase(j, 1);
			}
		}
	}

	for (int i = 0; i < size_chars; i++) {
		for (int j = strLen(s) - 1; j >= 0; j--) {
			if (s[j] == chars[i] and chars[i] != ' ') {
				s.erase(j, 1);
			}
		}
	}

	while (s[0] == ' ') {
		s.erase(0, 1);
	}

}

size_t strLen(const string str) {
	size_t len = 0;

	for (int i{ 0 }; str[i] != '\0'; i++) {
		len++;
	}

	return len;
}