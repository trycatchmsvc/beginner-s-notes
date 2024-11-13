//Написать функцию int count_equal(int arr[], int len, int x), которая возвращает 
// число элементов массива arr[] размера len, равных x.
//Проверочные значения : arr[] = { 1, 2, 3, 4, 3, 2, 2, 1 }, x = 2 ⇨ 3.
#include <iostream>
using namespace std;

int count_equal(int arr[], int len, int x);

int main() {
	const int size = 9;
	int len = size;
	int x;
	int arr[size] = { 1, 2, 3, 4, 3, 2, 2, 1 };

	cout << "Enter X: " << endl;
	cin >> x;
	
	cout << count_equal(arr, len, x) << endl;
	
	return 0;
}

int count_equal(int arr[], int len, int x) {
	int sum_equal = 0;
	
	for (int i{ 0 }; i < len; i++) {
		if (arr[i] == x) {
			sum_equal++;
		}
	}
	return sum_equal;
}