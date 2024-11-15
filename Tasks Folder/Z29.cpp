#include <iostream>
#include <string>
using namespace std;

void strip(char* s, const char* chars);

int main() {
    char str[] = "All work and no play makes Jack a dull boy :))";
    char str_del[] = "All :))";

    strip(str, str_del);
    cout << str;

    return 0;
}

void strip(char* s, const char* chars) {
    string str2[100] = {};
    string del_str[100] = {};

    int size = 0;
    int swap_val = 0;
    string str_adder = "";

    for (int i = 0; i <= strlen(s); i++) {
        if (s[i] != ' ' && s[i] != '\0') {
            str_adder += s[i];
        }
        else {
            str2[swap_val++] = str_adder;
            str_adder = "";
        }
    }
    size = swap_val;

    swap_val = 0;
    str_adder = "";

    for (int i = 0; i <= strlen(chars); i++) {
        if (chars[i] != ' ' && chars[i] != '\0') {
            str_adder += chars[i];
        }
        else {
            del_str[swap_val++] = str_adder;
            str_adder = "";
        }
    }

    
    if (str2[0] == del_str[0]) {
        str2[0] = "";
        size--;
    }

    if (str2[3] == del_str[1]) {
        str2[size - 1] = "";
        size--;
    }

    int pos = 0;
    for (int i = 0; i < size; i++) {
        if (!str2[i].empty()) {
            if (pos > 0) {
                s[pos++] = ' ';
            }
            for (char c : str2[i]) {
                s[pos++] = c;
            }
        }
    }
    s[pos] = '\0';
}
