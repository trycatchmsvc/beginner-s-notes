//25. Написать функцию void sort(float arr[], int len, bool asc), которая сортирует массив 
// arr длины len по возрастанию, если asc = true, и по убыванию, если asc = false.

#include <iostream>
using namespace std;

int check_arr(float arr[], int len, bool asc);
void print_array(float arr[], int len);
void sort(float arr[], int len, bool asc);

int main() {
	const int len = 8;
	float arr[len] = { 1, 2, 3.5, 4, 3, 2, 2.9, 1 };
	sort(arr, len, true);
	print_array(arr, len);
	cout << endl;
	sort(arr, len, false);
	print_array(arr, len);

	return 0;
}

int check_arr(float arr[], int len, bool asc) {
	if (asc == true) {
		for (int i{ 0 }; i < (len - 1); i++) {
			if (arr[i] > arr[i + 1]) {
				return 0;
			}
		}
	}
	else if (asc == false) {
		for (int i{ 0 }; i < (len - 1); i++) {
			if (arr[i] < arr[i + 1]) {
				return 0;
			}
		}
	}
	return 1;
}

void print_array(float arr[], int len) {
	for (int i{ 0 }; i < len; i++) {
		cout << arr[i] << " ";
	}
}

void sort(float arr[], int len, bool asc) {
	float replace_value;

	if (asc == true) {
		while (check_arr(arr, len, asc) == 0) {
			for (int i{ 0 }; i < (len - 1); i++) {
				if (arr[i] > arr[i + 1]) {
					replace_value = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = replace_value;
				}

			}
		}
	}
	else {
		while (check_arr(arr, len, asc) == 0) {
			for (int i{ 0 }; i < (len - 1); i++) {
				if (arr[i] < arr[i + 1]) {
					replace_value = arr[i];
					arr[i] = arr[i + 1];
					arr[i + 1] = replace_value;
				}

			}
		}
	}
}