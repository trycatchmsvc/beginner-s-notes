//32. Написать функцию void fliplr(int **arr, size_t nrows, size_t ncols), которая переворачивает 
// двумерный массив целых чисел из nrows строк и ncols столбцов слева направо.
#include <iostream>
using namespace std;

int** make2d(const size_t nrows, const size_t ncols, const int val);
void fliplr(int** arr, size_t nrows, size_t ncols);
void print_nD_array(int** arr, const size_t nrows, const size_t ncols);

int main() {
	// consts
	size_t nrows = 2;
	size_t ncols = 2;
	int val = 1;
	int** arr = new int* [nrows];
	
	//create nDd array
	for (int i{ 0 }; i < nrows; i++) {
		arr[i] = new int[ncols];
	}

	//fill nD array
	for (int i{ 0 }; i < nrows; i++) {
		for (int j{ 0 }; j < ncols; j++) {
			arr[i][j] = make2d(nrows, ncols, val)[i][j];
		}
	}

	cout << "Array before swap\n" << endl;
	print_nD_array(arr, nrows, ncols);
	cout << "\nArray after swap" << endl;
	fliplr(arr, nrows, ncols);
	print_nD_array(arr, nrows, ncols);

	return 0;

	//Delete arr
	for (int i{ 0 }; i < nrows; i++) {
		delete[]arr[i];
	}
	delete[]arr;
	arr = nullptr;
}

void print_nD_array(int** arr, const size_t nrows, const size_t ncols) {
	for (int i{ 0 }; i < nrows; i++) {
		for (int j{ 0 }; j < ncols; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

int** make2d(const size_t nrows, const size_t ncols, int val) {
	int** arr = new int* [nrows];
	
	for (int i{ 0 }; i < nrows; i++) {
		arr[i] = new int[ncols];
	}

	for (int i{0}; i < nrows; i++)
		for (int j{ 0 }; j < ncols; j++) {
			arr[i][j] = val++;
		}

	return arr;
}

void fliplr(int** arr, size_t nrows, size_t ncols) {
	size_t index_val = ncols - 1;
	for (int i{ 0 }; i < nrows; i++) {
		for (int j(0); j < ncols; j++) {
			swap(arr[i][j], arr[i][index_val]);
		}
	}
}

