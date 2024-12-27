//9. Дано натуральное число n. Сформировать двумерный массив A[n][n], заполнив его таким образом, 
//чтобы на побочной диагонали были расположены числа от n до 1, над побочной диагональю нули, а подпобочной
//диагональю по строкам числа в порядке возрастания от заданного на побочной диагонали.
#include <iostream>
using namespace std;

/*
0 0 0 4     
0 0 3 4
0 2 3 4 
1 2 3 4
*/

int main() {
	int n = 5;
	int** arr = new int* [n];

	for (int i{ 0 }; i < n; i++) {
		arr[i] = new int[n];
	}

	

	for (int i{ 0 }; i < n; i++) {
		for (int j{ 0 }; j < n; j++) {
			arr[i][j] = 0;
		}
	}

	int n_copy = n - 1;
	for (int i{ 0 }; i < n; i++) {
		int pointer = -1;
		for (int j{ 0 }; j < n; j++) {
			if (j == n_copy) {
				arr[i][j] = 1 + n_copy;
				pointer = j;
				while (pointer < n - 1) {
					arr[i][++pointer] = pointer + 1;
				}
				n_copy--;
			}
		}
	}

	for (int i{ 0 }; i < n; i++) {
		for (int j{ 0 }; j < n; j++) {
			cout << arr[i][j] << ' ';
		}
		cout << endl;
	}



	for (int i{ 0 }; i < n; i++) {
		delete[]arr[i];
	}
	delete[]arr;
	arr = nullptr;
	return 0;
}