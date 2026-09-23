//38. Во входном потоке находятся текстовые данные. Написать функцию 
// void rev_lines(std::istream &ist, std::ostream &ost), 
// которая выводит строки из потока ist в поток ost в обратном порядке.
#include <iostream>
#include <fstream>
using namespace std;

void rev_lines(std::istream& ist, std::ostream& ost);

int main() {

	string inp_path = "input.txt";
	string out_path = "output.txt";
	ifstream ist(inp_path);
	ofstream ost(out_path);

	rev_lines(ist, ost);

	ist.close();
	ost.close();
	return 0;
}

void rev_lines(std::istream& ist, std::ostream& ost) {
	string arr[255] = {};
	int pointer = 0;

	string str_buffer = "";

	char buffer[255]{};
	while (ist.getline(buffer, 100)) {
		arr[pointer++] = string(buffer);
	}

	pointer--;

	for (pointer; pointer >= 0; pointer--) {
		ost << arr[pointer] << endl;
	}
}