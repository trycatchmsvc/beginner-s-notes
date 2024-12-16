//39. Во входном потоке находятся текстовые данные.Написать функцию 
// void wrap_text(std::istream & ist, std::ostream & ost, int max_line_len),
// которая выводит текст из потока ist в поток ost, перенося строки длиной 
// более max_line_len символов.
#include <iostream>
#include <fstream>
using namespace std;

void wrap_text(std::istream& ist, std::ostream& ost, int max_line_len);

int main() {

	string inp_path = "input.txt";
	string out_path = "output.txt";
	ifstream ist(inp_path);
	ofstream ost(out_path);

	int max_line_len = 10;

	wrap_text(ist, ost, max_line_len);

	ist.close();
	ost.close();
	return 0;
}

void wrap_text(std::istream& ist, std::ostream& ost, int max_line_len) {
	int len_prt = 0;
	char buffer[255];
	string memory = "";
	int pointer = 0;

	while (ist.getline(buffer, 100)) {
		memory = memory + string(buffer) + "\n";
	}

	for (int i{ 0 }; memory[i] != '\0'; i++) {
		if (len_prt != max_line_len) {
			if (memory[i] != '\n') {
				cout << memory[i];
				len_prt++;
			}
			else {
				cout << endl;
				len_prt = 0;
			}
		}
		else {
			cout << endl;
			i--;
			len_prt = 0;
		}
	}
}