//Разработать программу, использующую динамическое выделение памяти под массив, которая вводит 
// одномерный массив A[N], формирует из элементов массива A новый массив B[N] по правилам, 
//указанным в табл. 2, и выводит его.

#include <iostream>
using namespace std;

int* read_array(int len);
void print_array(int arr[], int len);
int my_task(int A[], int lenA, int B[], int lenB);

int main() {
	int n = 5, len;
	cout << "Enter length of your array: ";
	cin >> len;
	
	if (len >= 0) {
		int* A = read_array(len);
		int* B = new int[len];

		cout << "Array A: ";
		print_array(A, len);
		cout << endl;

		cout << "Value of changes: " << my_task(A, len, B, len) << endl;

		cout << "Array B: ";
		print_array(B, len);

		delete[]A;
		delete[]B;

		return 0;
	}
	else {
		cout << "Array can not it is size" << endl;
		return 0;
	}
}

int* read_array(int len) {
	int* arr = new int[len];

	for (int i{ 0 }; i < len; i++) {
		cin >> arr[i];
	}
	
	return arr;
}

void print_array(int arr[], int len) {
	for (int i{ 0 }; i < len; i++) {
		cout << arr[i] << " ";
	}
}

int my_task(int A[], int lenA, int B[], int lenB) {
	int index_minus = 0;
	int counter = 0;

	for (int i{ 1 }; i < lenA; i++) {
		if (A[i] < 0) {
			index_minus = i;
			break;
		}
	}
	
	for (int i = 0; i < lenA; i++) {
		if (i < index_minus && A[i] == 0) {
			B[i] = 1;
			counter++;
		}
		else {
			B[i] = A[i];
		}
	}
	return counter;
}
