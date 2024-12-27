//30. Написать функцию std::size_t join(char *s_out, std::size_t len, 
// const char * const *s_in, std::size_t n_in, const char *sep)

#include <iostream>
#include <string>
using namespace std;

size_t join(char* s_out, std::size_t len, const char* const* s_in, std::size_t n_in, const char* sep);
size_t strLen(const string arr);

int main() {

	int n_in = 4; // Количество элементов массива
	int len = 40; // Максимальная длина строки
	const char* sep = ","; // Разделитель между строк
	char s_out[255] = ""; // Итоговая строка

	const char* arr[] = { "Vasya", "Petya", "Masha", "Ivan Ivanovich" }; // s_in массив

	cout << "Length string: " << join(s_out, len, arr, n_in, sep) << endl; // Выводим длину строки
	
	cout << "String - " << s_out << endl; //Выводим готовый массив


	return 0;
}

size_t join(char* s_out, size_t len, const char* const* s_in, size_t n_in, const char* sep) {
	
	int point = 0; // Указатель добавления в массив s_out
	
	for (int i{ 0 }; i < n_in; i++){ // Проходимся по элементам массива

		for (int j{ 0 }; j < strlen(s_in[i]); j++) { //Проходимся по буквам из элемента массива
			s_out[point++] = s_in[i][j];
		}
		if (i != n_in - 1) { // Проверка чтобы не ставить после последнего элемента пробел с запятой
			s_out[point++] = *sep;
			s_out[point++] = ' ';
		}
		else {
			s_out[++point] = '\0';
		}
	}

	s_out[len] = '\0';
	
	return strLen(s_out);
}

size_t strLen(const string str) { //Realise func strlen
	size_t len = 0;

	for (int i{ 0 }; str[i] != '\0'; i++) {
		len++;
	}

	return len;
}