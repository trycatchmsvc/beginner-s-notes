//Написать функцию void print_array(int arr[], int len), которая выводит на экран 
//первые len элементов массива arr. используя для работы с массивами указатели (оператор индекса [] не использовать).

#include <iostream>
#include <ctime>
using namespace std;

void add_random_values(int* arr, int len);
void print_array(int* arr, int len);

int main() {
	int len;
	
	cout << "ent len: ";
	cin >> len;
	
	int* arr = new int[len];
	int* parr = arr;
	
	add_random_values(parr, len);
	print_array(parr, len);
	
	delete[]arr;
	return 0;
}

void add_random_values(int* arr, int len) {
	srand(time(NULL));
	for (int i{ 0 }; i < len; i++) {
		*(arr + i) = rand() % 10;
	}
}

void print_array(int* arr, int len) {
	for (int i{ 0 }; i < len; i++) {
		cout << *(arr + i) << " ";
	}
}
