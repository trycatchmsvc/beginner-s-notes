#include <iostream>
using namespace std;

int search(int* arr, int start_point, int end_point, int key) {

	int middle = (start_point + end_point) / 2;

	if (key > arr[end_point] || key < arr[start_point]) {
		return -1;
	}

	if (middle != 0 && key == arr[middle - 1]) {
		return search(arr, start_point, middle - 1, key);
	}

	if (arr[middle] == key) {
		return middle;
	}

	if (arr[middle] < key) {
		return search(arr, middle + 1, end_point, key);
	}

	if (arr[middle] > key) {
		return search(arr, start_point, middle - 1, key);
	}
}




int main() {

	int array[] = { 1, 2, 3, 3, 3, 3, 3 };

	int key = 3;

	int amount_array = sizeof(array) / sizeof(array[0]) - 1;

	cout << search(array, 0, amount_array, key);
	

	return 0;
}