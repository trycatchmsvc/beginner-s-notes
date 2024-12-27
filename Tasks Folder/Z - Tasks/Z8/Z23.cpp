//Написать функцию int count_equal(int arr[], int len, int x), которая возвращает число
// элементов массива arr[] размера len, равных x.используя для работы с массивами
// указатели (оператор индекса [] не использовать).
#include <iostream>
using namespace std;

int count_equal(int* arr, int len, int x);

int main() {
	const int len = 6;
	int x;
	int arr[len] = {1, 2, 2, 4, 1, 1};
	int* pArr = arr;

	cout << "ent x: "; cin >> x;
	cout << count_equal(pArr, len, x);
	return 0;
}

int count_equal(int* arr, int len, int x) {
	int counter{ 0 };

	for (int i{ 0 }; i < len; i++) {
		if (*(arr + i) == x) {
			counter++;
		}
	}
	return counter;
}