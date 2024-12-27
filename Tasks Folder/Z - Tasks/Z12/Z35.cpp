//35. Написать функцию void print_fliplr(const int* const* arr, size_t nrows, size_t ncols, std::ostream & ost), 
// которая выводит в поток ost перевёрнутый слева направо двумерный массив целых чисел arr из nrows строк и ncols столбцов.
#include <iostream>
#include <fstream>
using namespace std;

void print_fliplr(const int* const* arr, size_t nrows, size_t ncols, std::ostream& ost);

int main() {
	// consts
	size_t nrows = 4;
	size_t ncols = 3;
	int val = 1;
	int** arr = new int* [nrows];

	ofstream ost("output.txt");

	//create 2Dd array
	for (int i{ 0 }; i < nrows; i++) {
		arr[i] = new int[ncols];
	}

	int a = 1;

	for (int i{ 0 }; i < nrows; i++) {
		for (int j{ 0 }; j < ncols; j++) {
			arr[i][j] = a++;
		}
	}

	print_fliplr(arr, nrows, ncols, ost);

	//Delete arr
	for (int i{ 0 }; i < nrows; i++) {
		delete[]arr[i];
	}
	delete[]arr;
	arr = nullptr;
}

void print_fliplr(const int* const* arr, size_t nrows, size_t ncols, std::ostream& ost) {
	ost << "Before\n";
	for (int i{ 0 }; i < nrows; i++) {
		for (int j{ 0 }; j < ncols; j++) {
			ost << arr[i][j];
			ost << ' ';
		}
		ost << '\n';
	}

	ost << "After\n";

	for (int i{ 0 }; i < nrows; i++) {
		for(int j{ (int)ncols }; j > 0; j--) {
			ost << arr[i][j - 1];
			ost << ' ';
		}
		ost << '\n';
	}
}
