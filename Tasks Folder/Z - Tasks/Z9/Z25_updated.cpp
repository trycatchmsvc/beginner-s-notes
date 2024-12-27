//25. Написать функцию void sort(float arr[], int len, bool asc), которая сортирует 
// массив arr длины len по возрастанию, если asc = true, и по убыванию, если asc = false.

#include <iostream>
using namespace std;

void print_array(int arr[], int len);
void bubble_sort(int arr[], int len, bool asc);

int main() {
	const int len = 6;
	int arr[len] = { 4, 3, 2, 1, 5, 3 };

	print_array(arr, len);
	bubble_sort(arr, len, true);
	print_array(arr, len);
	bubble_sort(arr, len, false);
	print_array(arr, len);
	return 0;
}

void print_array(int arr[], int len) {
	cout << endl;
	for (int i{ 0 }; i < len; i++) {
		cout << arr[i] << " ";
	}
}

void bubble_sort(int arr[], int len, bool asc) {
	for (int i{ 0 }; i < len; i++) {
		int replace_value;
		bool Flag = true;
		if (asc == true) {
			for (int j{ 0 }; j < len - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					replace_value = arr[j + 1];
					arr[j + 1] = arr[j];
					arr[j] = replace_value;
					Flag = false;
				}
			}
		}
		else {
			for (int j{ 0 }; j < len - 1; j++) {
				if (arr[j] < arr[j + 1]) {
					replace_value = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = replace_value;
					Flag = false;
				}
			}
		}
		if (Flag == true) break;
	}
}