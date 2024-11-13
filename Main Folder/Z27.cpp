//27. Написать функцию void sort(float arr[], int len, float x), которая сортирует массив arr длины len по 
// возрастанию модуля разности между числом x и элементом массива. После сортировки в функции main() 
// сформировать массив dist[] из модулей разности (dist[i] = |arr[i] - x|) и вывести его.

#include <iostream>
#include <cmath>
using namespace std;

void print_array(float arr[], int len);
void bubble_sort(float arr[], int len);
void sort(float arr[], int len, float x);

int main() {
	const int len = 8;
	float x; 
	
	cout << "x "; cin >> x;
	
	float dist[len];
	float arr[len] = { 1, 2, 3.5, 4, 3, 2, 2.9, 1 };
	
	sort(arr, len, x);
	
	for (int i{ 0 }; i < len; i++) {
		dist[i] = abs(arr[i] - x);
	}

	print_array(dist, len);

	return 0;
}

void print_array(float arr[], int len) {
	cout << endl;
	for (int i{ 0 }; i < len; i++) {
		cout << arr[i] << " ";
	}
}

void bubble_sort(float arr[], int len) {
	for (int i{ 0 }; i < len; i++) {
		float replace_value;
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

void sort(float arr[], int len, float x) {
	for (int i{ 0 }; i < len; i++) {
		arr[i] = abs(arr[i] - x);
	}
	
	bubble_sort(arr, len);
	
	for (int i{ 0 }; i < len; i++) {
		arr[i] = arr[i] + x;
	}
}