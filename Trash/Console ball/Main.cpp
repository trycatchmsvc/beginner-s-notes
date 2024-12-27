#include <iostream>
using namespace std;

void print_array(char arr[4][4], int size);
void change_position(char arr[4][4], int size, int x_pl, int y_pl);

int main() {
	const int size = 4;
	char map[size][size] = { {'*', ' ', ' ', ' '},
							 {' ', ' ', ' ', ' '},
							 {' ', ' ', ' ', ' '},
							 {' ', ' ', ' ', ' '}};

	print_array(map, size);
	change_position(map, size, 1, 1);
	cout << endl;
	print_array(map, size);

	return 0;
}

void print_array(char arr[4][4], int size) {
	for (int i{ 0 }; i < size; i++) {
		for (int j{ 0 }; j < size; j++) {
			cout << arr[i][j];
		}
		cout << endl;
	}
}

void change_position(char arr[4][4], int size, int x_pl, int y_pl) {
	int x_pos{};
	int y_pos{};
	
	for (int i{ 0 }; i < size; i++) {
		for (int j{ 0 }; j < size; j++) {
			if (arr[i][j] == '*') {
				x_pos = i;
				y_pos = j;
			}
		}
	}

	arr[x_pos][y_pos] = ' ';
	arr[x_pos + x_pl][y_pos + y_pl] = '*';
}

