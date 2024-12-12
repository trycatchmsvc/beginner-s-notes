//36. Написать функцию void print_transposed(const int * const *arr, size_t size, std::ostream &ost), 
// которая выводит в поток ost транспонированную квадратную матрицу целых чисел arr порядка size.
#include <iostream>
#include <fstream>
using namespace std;

void print_transposed(const int* const* arr, size_t size, std::ostream& ost);

int main() {
	// consts
	size_t nrows = 4;
	size_t ncols = 4;
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

	print_transposed(arr, nrows, ost);

	//Delete arr
	for (int i{ 0 }; i < nrows; i++) {
		delete[]arr[i];
	}
	delete[]arr;
	arr = nullptr;
}

void print_transposed(const int* const* arr, size_t size, std::ostream& ost) {
	ost << "Before\n";
	for (int i{ 0 }; i < size; i++) {
		for (int j{ 0 }; j < size; j++) {
			ost << arr[i][j];
			ost << ' ';
		}
		ost << '\n';
	}

	ost << "After\n";

	for (int i{ 0 }; i < size; i++) {
		for (int j{ 0 }; j < size; j++) {
			ost << arr[j][i];
			ost << ' ';
		}
		ost << '\n';
	}
}
