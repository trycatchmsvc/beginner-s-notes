//25. Написать функцию void sort(float arr[], int len, bool asc), которая сортирует 
// массив arr длины len по возрастанию, если asc = true, и по убыванию, если asc = false.

#include <iostream>
using namespace std;

void print_array(int arr[], int len);
void bubble_sort(int* arr, int len);
void bubble_sort(int *arr, int len, bool even_greater);
void even_greater_changer(int arr[], int len, bool even_greater);

int main() {
	const int len = 8;
	int arr[len] = { 1, 2, 3, 4, 3, 2, 6, 5 };

	print_array(arr, len); 
	
	bubble_sort(arr, len);
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

void bubble_sort(int* arr, int len) {
	for (int i{ 0 }; i < len; i++) {
		int replace_value;
		bool Flag = true;
		for (int j{ 0 }; j < len - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				replace_value = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = replace_value;
				Flag = false;
			}
		}
		if (Flag == true) break;
	}
}

void bubble_sort(int *arr, int len, bool even_greater) {
	for (int i{ 0 }; i < len; i++) {
		int replace_value;
		bool Flag = true;
		for (int j{ 0 }; j < len - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				replace_value = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = replace_value;
				Flag = false;
			}
		}
		if (Flag == true) break;
	}
	even_greater_changer(arr, len, even_greater);
}

void even_greater_changer(int arr[], int len, bool even_greater) {
	for (int i{ 0 }; i < len; i++) {
		int replace_value;
		bool Flag = true;

		for (int j{ 0 }; j < len - 1; j++) {
			if (even_greater == true) {
				if (arr[j] % 2 == 0) {
					replace_value = arr[j + 1];
					arr[j + 1] = arr[j];
					arr[j] = replace_value;
					Flag = false;
				}
			}
			else {
				if (arr[j] % 2 == 1) {
					replace_value = arr[j + 1];
					arr[j + 1] = arr[j];
					arr[j] = replace_value;
					Flag = false;
				}
			}
		}
	if (Flag == true) break;
	}
}