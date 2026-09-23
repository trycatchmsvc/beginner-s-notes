//19. Написать функцию void print_array(int arr[], int len), которая выводит на 
// экран первые len элементов массива arr.
#include <iostream>
#include <ctime>
using namespace std;

void print_array(int arr[], int len);

int main() {
	int size = 10, len = 5;
	int* arr = new int[size];
	srand(time(NULL));
	
	for (int i{ 0 }; i < size; i++) {
		arr[i] = rand() % 10;
	}

	print_array(arr, len);

	delete [] arr;
	return 0;
}

void print_array(int arr[], int len) {

	for (int i{ 0 }; i < len; i++) {
		cout << arr[i] << " ";
	}

}