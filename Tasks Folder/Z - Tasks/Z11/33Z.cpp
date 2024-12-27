//33.Написать функцию void transpose(int **arr, size_t size), которая транспонирует 
// квадратную матрицу целых чисел порядка size.
#include <iostream>
using namespace std;

int** make2d(const size_t nrows, const size_t ncols, const int val);
void transpose(int** arr, size_t size);
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

	cout << "Array before\n" << endl;
	print_nD_array(arr, nrows, ncols);
	cout << "\nArray after" << endl;
	transpose(arr, nrows);
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

void transpose(int** arr, size_t size) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			swap(arr[i][j], arr[j][i]);
		}
	}
}



