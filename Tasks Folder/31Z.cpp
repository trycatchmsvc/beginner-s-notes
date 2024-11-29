//31. Написать функцию int **make2d(size_t nrows, size_t ncols, int val), которая возвращает 
// динамический двумерный массив целых чисел из nrows строк и ncols столбцов, элементы которого равны val.
#include <iostream>
using namespace std;

int** make2d(const size_t nrows, const size_t ncols, const int val);

int main() {

	int nrows = 2;
	int ncols = 2;
	int val = 1;

	for (int i{ 0 }; i < nrows; i++) {
		for (int j{0}; j < ncols; j++) {
			cout << make2d(nrows, ncols, val)[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

int** make2d(const size_t nrows, const size_t ncols, const int val) {
	int** arr = new int* [nrows];
	
	for (int i{ 0 }; i < nrows; i++) {
		arr[i] = new int[ncols];
	}

	for (int i{0}; i < nrows; i++)
		for (int j{ 0 }; j < ncols; j++) {
			arr[i][j] = val;
		}

	return arr;
}