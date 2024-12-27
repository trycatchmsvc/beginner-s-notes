//37. Во входном потоке находится последовательность слов, разделённых пробельными символами. 
// Написать функцию void join(const char *sep, std::istream &ist, std::ostream &ost), 
// которая считывает слова из потока ist и выводит их в поток ost в виде последовательности слов, разделённых строкой sep.
#include <iostream>
#include <fstream>
using namespace std;

void join(const char* sep, std::istream& ist, std::ostream& ost);

int main() {

	string inp_path = "input.txt";
	string out_path = "output.txt";
	ifstream ist(inp_path);
	ofstream ost(out_path);

	char sep[255] = ", ";

	join(sep, ist, ost);

	ist.close();
	ost.close();
	return 0;
}

void join(const char* sep, std::istream& ist, std::ostream& ost) {
	char* buffer = new char[255];

	while (ist >> buffer) {
		ost << buffer << sep;
	}
}