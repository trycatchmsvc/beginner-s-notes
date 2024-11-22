#include <iostream>
using namespace std;

void str_change(char *arr);

int main() {

	char arr[255] = "HappyNewYear";
	
	str_change(arr);

	cout << arr;

	return 0;
	strlen
}

void str_change(char *arr) {
	char check[] = "QWERTYUIOPASDFGHJKLZXCVBNM";
	char swap_value = ' ';
	char arr_2[255] = "";
	int pointer = 0;

	int len = strlen(arr);

	for (int i{ 0 }; i < len; i++) {
		for (int j{ 0 }; j < strlen(check); j++) {
			if (arr[i] == check[j] and i != 0) {
				arr_2[pointer++] = ' ';
			}
			arr_2[pointer] = arr[i];
		}
		pointer++;
	}
	
	for (int i{ 0 }; i < strlen(arr_2); i++) {
		arr[i] = arr_2[i];
	}
}