//34. Написать функцию void print2d(const int * const *arr, size_t nrows, size_t ncols, std::ostream &ost), 
//которая выводит двумерный массив целых чисел arr из nrows строк и ncols столбцов в поток ost.
#include <iostream>
#include <fstream>
using namespace std;

void print2d(const int* const* arr, size_t nrows, size_t ncols, std::ostream& ost);

int main() {
    // Создаем объект потока для записи в файл
    ofstream ost("output.txt");

    int rows = 2; // Строки
    int cols = 2; // Колонки

    int** arr = new int * [rows];

    for (int i{ 0 }; i < rows; i++) {
        arr[i] = new int[cols];
    }

    int a = 1;

    for (int i{ 0 }; i < rows; i++) {
        for (int j{ 0 }; j < cols; j++) {
            arr[i][j] = a++;
        }
    }

    print2d(arr, rows, cols, ost);

    ost.close();

    for (int i{ 0 }; i < rows; i++) {
        delete[]arr[i];
    }

    delete[]arr;
    return 0;
}


void print2d(const int* const* arr, size_t nrows, size_t ncols, std::ostream& ost) {
    for (int i{ 0 }; i < nrows; i++) {
        for (int j{ 0 }; j < ncols; j++) {
            ost << arr[i][j];
            ost << ' ';
        }
        ost << '\n';
    }
}