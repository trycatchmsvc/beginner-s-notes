#include <iostream>
#include <cmath>
using namespace std;

void arrays_in_arr(float* first_arr, float* second_arr, float** output_arr, int len);
void print_array_2d(float** arr, int len);
float search_len(float start_x, float start_y, float x, float y);
void bubble_sort_2d_array(float** arr_c, int len, float x, float y, bool asc);
double acos(float start_x, float start_y, float x, float y);
void search_point(float** arr_c, int len, float start_x, float start_y);

int main() {
	int len;
	float x, y;
	bool asc = false;

	cout << "Ent up or down (1 or 0) "; cin >> asc;
	cout << "Enter start position\nX Y" << endl;
	cin >> x >> y;
	cout << "Enter length: ";
	cin >> len;

	float* arr_a = new float[len];
	float* arr_b = new float[len];
	float** arr_c = new float* [len];

	for (int i = 0; i < len; i++) {
		arr_c[i] = new float[2];
	}

	cout << "X Y" << endl;
	for (int i = 0; i < len; i++) {
		cin >> arr_a[i] >> arr_b[i];
	}

	cout << endl;

	arrays_in_arr(arr_a, arr_b, arr_c, len);

	for (int i = 0; i < len; i++) {
		cout << arr_c[i][0] << " " << arr_c[i][1] << " " << search_len(x, y, arr_c[i][0], arr_c[i][1]) << endl;
	}

	bubble_sort_2d_array(arr_c, len, x, y, asc);

	cout << endl;
	print_array_2d(arr_c, len);

	search_point(arr_c, len, x, y);

	for (int i = 0; i < len; i++) {
		delete[] arr_c[i];
	}

	delete[] arr_c;
	delete[] arr_a;
	delete[] arr_b;

	return 0;
}

void arrays_in_arr(float* first_arr, float* second_arr, float** output_arr, int len) {
	for (int i{ 0 }; i < len; i++) {
		output_arr[i][0] = first_arr[i];
		output_arr[i][1] = second_arr[i];
	}
}

void print_array_2d(float** arr, int len) {
	for (int i = 0; i < len; i++) {
		for (int j = 0; j < 2; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

float search_len(float start_x, float start_y, float x, float y){
	return sqrt(pow((x - start_x), 2) + pow((y - start_y), 2));
}

void bubble_sort_2d_array(float** arr_c, int len, float x, float y, bool asc) {
	for (int i{ 0 }; i < len; i++) {
		float replace_value_1;
		float replace_value_2;

		for (int j{ 0 }; j < len - 1; j++) {
			float first_value = search_len(x, y, arr_c[j][0], arr_c[j][1]);
			float second_value = search_len(x, y, arr_c[j + 1][0], arr_c[j + 1][1]);
			if ((first_value > second_value) and (asc == true)) {
				replace_value_1 = arr_c[j + 1][0];
				replace_value_2 = arr_c[j + 1][1];

				arr_c[j + 1][0] = arr_c[j][0];
				arr_c[j + 1][1] = arr_c[j][1];
				arr_c[j][0] = replace_value_1;
				arr_c[j][1] = replace_value_2;
			}
			else {
				if ((first_value < second_value) and (asc == false)) {
					replace_value_1 = arr_c[j][0];
					replace_value_2 = arr_c[j][1];

					arr_c[j][0] = arr_c[j + 1][0];
					arr_c[j][1] = arr_c[j + 1][1];
					arr_c[j + 1][0] = replace_value_1;
					arr_c[j + 1][1] = replace_value_2;
				}
			}
		}
	}
}

double acos(float start_x, float start_y, float x, float y) {
	double dx = x - start_x;
	double dy = y - start_y;
	return dx / sqrt(dx * dx + dy * dy);
}

void search_point(float** arr_c, int len, float start_x, float start_y) {
	for (int i{ 0 }; i < len; i++) {
		float replace_value_1;
		float replace_value_2;

		for (int j{ 0 }; j < len - 1; j++) {
			float first_value = acos(start_x, start_y, arr_c[j][0], arr_c[j][1]);
			float second_value = acos(start_x, start_y, arr_c[j + 1][0], arr_c[j + 1][1]);
			if (first_value > second_value) {
				replace_value_1 = arr_c[j + 1][0];
				replace_value_2 = arr_c[j + 1][1];

				arr_c[j + 1][0] = arr_c[j][0];
				arr_c[j + 1][1] = arr_c[j][1];
				arr_c[j][0] = replace_value_1;
				arr_c[j][1] = replace_value_2;
			}
		}
	}
	cout << "Point: " << arr_c[0][0] << " " << arr_c[0][1] << endl;
}