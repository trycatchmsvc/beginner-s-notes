Оглавление
=====================

[Datatype C++](https://github.com/beginningpythonist/Study-C-Plus-Plus?tab=readme-ov-file#datatype-c)
###

[Using namespace](https://github.com/beginningpythonist/Study-C-Plus-Plus?tab=readme-ov-file#using-namespace)
###

["Hello world" - streaming output method - iostream library](https://github.com/beginningpythonist/Study-C-Plus-Plus?tab=readme-ov-file#hello-world---streaming-output-method---iostream-library)
###

[COUT + PRINTF](https://github.com/beginningpythonist/Study-C-Plus-Plus?tab=readme-ov-file#cout--printf)
###

[Формат вывода в библиотеке - iostream](https://github.com/beginningpythonist/Study-C-Plus-Plus?tab=readme-ov-file#%D1%84%D0%BE%D1%80%D0%BC%D0%B0%D1%82-%D0%B2%D1%8B%D0%B2%D0%BE%D0%B4%D0%B0-%D0%B2-%D0%B1%D0%B8%D0%B1%D0%BB%D0%B8%D0%BE%D1%82%D0%B5%D0%BA%D0%B5---iostream)

[Спецификация вывода чисел функцией printf](https://github.com/beginningpythonist/Study-C-Plus-Plus?tab=readme-ov-file#specificator-of-format-for-printf)

[Как использовать Русский язык?](https://github.com/beginningpythonist/Study-C-Plus-Plus?tab=readme-ov-file#%D0%BA%D0%B0%D0%BA-%D0%B8%D1%81%D0%BF%D0%BE%D0%BB%D1%8C%D0%B7%D0%BE%D0%B2%D0%B0%D1%82%D1%8C-%D1%80%D1%83%D1%81%D1%81%D0%BA%D0%B8%D0%B9-%D1%8F%D0%B7%D1%8B%D0%BA)

[Логические операторы]

[Инкремент и Декремент]

[Switch - case]

[Scanf]

[Указатели и ссылки || Pointer and Reference]

[Генератор рандома]

[]

[]

[]

[]

[]

[]

[]

## Datatype C++

**Функция получения размера типа данных:** `sizeof()`

- `char`: only one symbole OR ASCII numbers | 1 byte -128 до 127 (для signed char) 0 до 255 (для unsigned char)

- `bool`: true (1) или false (0) | it is a logical type of data, 1 byte

- `string`: standart data type but it need import library | #include <string>


Using namespace
=====================
В C++ пространства имен используются для организации кода и предотвращения конфликтов имен
###

- `std` **это пространство имен (namespace) в стандартной библиотеке C++**


"Hello world" - streaming output method - iostream library
=====================
Without namespace
```c++
#include <iostream>  // Этот заголовочный файл содержит определения для 
// стандартных потоков ввода и вывода, таких как std::cin, std::cout, std::cerr, и std::clog.

int main() {
	std::cout << "Hello World" << std::endl;
	return 0;
}
```
With namespace
```c++
#include <iostream>
using namespace std; // позволяет использовать пространство имен 

int main() {
	cout << "Hello World" << endl;
	return 0;
}
```

COUT + PRINTF
=====================
```c++
#include <iostream>
#include <string>
using namespace std;

char text_char_ascii = 68;
char text_char = 'D';
string text_string = "Hello World 4;3%!";

void main() {
	cout << text_char_ascii  << endl;
	cout << text_char << endl;
	cout << text_char << " " << text_string << endl;
	printf("Hello World\n");
	printf("%s\n", text_string.c_str());
}

//Если строка содержит символы, которые printf интерпретирует как форматные 
//спецификаторы, это может привести к ошибкам //выполнения или некорректному выводу.

printf("%s\n", text_string.c_str());

//Этот способ гарантирует, что printf правильно интерпретирует строку как текст 
```

Формат вывода в библиотеке - **iostream**
=====================

- `setw(n)`	n — целое число	Устанавливает минимальную ширину поля для вывода значения. Значение заполняется пробелами слева, если оно короче указанной ширины.

- `setfill(c)`	c — символ заполнения	Задает символ, которым будут заполняться пустые места, если выводимое значение меньше указанной ширины (по умолчанию используется пробел).

- `left`	Не принимает аргументов	Выравнивает значение по левому краю в поле заданной ширины.

- `right`	Не принимает аргументов	Выравнивает значение по правому краю в поле заданной ширины (по умолчанию используется это выравнивание).

- `fixed`	Не принимает аргументов	Выводит вещественные числа в фиксированном формате (без научной нотации).

- `setprecision(n)`	n — целое число	Устанавливает количество знаков после запятой для вывода вещественных чисел.

- `showpoint`	Не принимает аргументов	Гарантирует отображение десятичной точки для вещественных чисел, даже если она не требуется.

- `noshowpoint`	Не принимает аргументов	Убирает отображение лишней десятичной точки, если она не нужна.

- `scientific`	Не принимает аргументов	Выводит вещественные числа в научной нотации (формат с экспонентой).

Спецификация вывода чисел функцией **printf**
=====================														
### Для целых чисел:

- `%d или %i` вывод целого числа в десятичной системе (тип int)

- `%u` вывод беззнакового целого числа (тип unsigned int)

- `%x или %X` — вывод числа в шестнадцатеричной системе (малые и заглавные буквы соответственно)

- `%o` — вывод числа в восьмеричной системе

### Для чисел с плавающей точкой:

- `%f` — вывод числа с плавающей точкой (тип float или double)

- `%e или %E` — вывод числа в экспоненциальной форме (например, 1.23e+03)

- `%g или %G` — вывод числа с плавающей точкой в либо обычной, либо экспоненциальной форме, в зависимости от величины числа

### Для символов и строк:

- `%c` — вывод одного символа (тип char)

- `%s` — вывод строки (массив символов, тип char*)

Как использовать Русский язык?
=====================
```C++
#include <iostream>
#include <locale> // library for set locale language
using namespace std;

int input_number_1;

int main() {
	setlocale(LC_ALL, "Russian"); // set ASCII Ru
	int input_number_1, result;
	cout << "Lets use keyboard! Tap numbers! " << endl;
	cin >> input_number_1;
	result = input_number_1 * 2;
	cout << "Число " << input_number_1 << " умноженное на 2 = " << result << endl;
	return 0;
}
```

Логические операторы
=====================

`&& | and` 

`|| | or`
																											 
Инкремент и Декремент 
=====================

- `++` | Увеличивает на 1

- `--` | Уменьшает a на 1

**`++x, --y`** - Префиксное - Увеличивает либо Уменьшает сразу же

**`x++, y--`** - Постфиксное - Увеличивает либо Уменьшает после выполнения цикла

Switch - case
=====================
```c++
#include <iostream>

using namespace std;

int main() {
	int age;
	bool isbool = true;
	
	cin >> age;
	
	if (age < 3) {
		switch (age) {
		case 3:
			printf("age = 3\n");
			break;
		case 2:
			cout << "age = 22222";
			break;
		default:
			cout << "numb is smallest" << endl;
			break;
		}
	}
	else if (age < 18) {
		cout << "Your age is " << age << endl;
	}

	return 0;
}
```
Scanf
=====================

USING SCANF IS NOT GOOD BUT YOU CAN IT USE

it is need use #define _CRT_SECURE_NO_WARNINGS because it is calling warning

```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

int main() {
	int a;
	scanf_s("%d", &a);
	printf("int а = %d",a);
	return 0;
}
```
Указатели и ссылки || Pointer and Reference
=====================

```c++
#include <iostream>
using namespace std;

// 
int main() {
	int a = 10;
	cout << &a << endl;
	int *link_a = &a; //pointer
	int &ref_a = a; //link or reference
	a = 5;
	cout << &a << " " << *link_a << " " << ref_a << endl;


	return 0;
}
```

Генератор рандома
=====================
```c++
#include <iostream>
#include <ctime> //import library for point of calculate
using namespace std;

int main() {
	srand(time(NULL)); //inicilise point calculate of time point
	int a = rand(); // random number
	int b = rand() % 10 + 5; // random number of 5:15
	cout << a << "\t" << b << endl;
	return 0;
}
```

Array
=====================
How use array?
```c++
#include <iostream>

int main() {
	int array[3];
	int arr[3] = { 1, 2, 3 }; //1D Array
	int arr2[3][2] = { {1, 2}, {3, 4}, {5, 6} }; //2D Array
 
	array[0] = 1; //Pointer
	array[1] = 2;
	array[2] = 3;

	std::cout << array[0] << " " << arr[1] << " " << arr2[1][0] << std::endl;

	return 0;
}

```
2D Array
###
```c++
#include <iostream>
using namespace std;

int main() {

	int arr[3][2] = { {1,2}, {3,4}, {5, 6} };
	int arr2[3];
	
	cout << "1 array" << endl;
	
	for (int i = 0; i < 3; i++) {
		for (int i1 = 0; i1 < 2; i1++) {
			cout << arr[i][i1] << " ";
		}
		cout << endl;
	}
	
	for (int i = 0; i < 3; i++) {
		cin >> arr2[i];
	}

	for (int i = 0; i < sizeof(arr2) / sizeof(arr2[0]); i++) {
		cout << arr2[i] << " ";
	}
	
	return 0;
}
```

Dynamic array
=====================
```c++
#include <iostream>
#include <ctime> // point for random
using namespace std;

int main() {
	int size = 0;
	
	cout << "Enter size of array\t";
	cin >> size;
	
	int* arr = new int[size];
	srand(time(NULL)); //srand for rand
	
	//add numbers at array
	for (int i = 0; i < size; i++) {
		arr[i] = rand() % 10; // add in index(i) random numb
	}

	//print of array
	for (int i{ 0 }; i < size; i++) {
		cout << arr[i] << " ";
	}

	delete[]arr; // while use dynamic array you need delete it is cache in |heap| memory(stack\heap)
	return 0;
}
```

Dynamic 2D Array
=====================
```c++
#include <iostream>
using namespace std;

int main() {
    int Variable = 0; // Данные для заполнения массива

    int rows = 3; // Строки
    int cols = 4; // Колонки

    int** arr = new int* [rows]; 

    for (int i{ 0 }; i < rows; i++) { //Создаем в массиве указателей еще масив
        arr[i] = new int[cols];
    }

    for (int i{ 0 }; i < rows; i++) { //Заполнение массива
        for (int j{ 0 }; j < cols; j++) {
            Variable++;
            arr[i][j] = Variable;
        }
    }

    for (int i{ 0 }; i < rows; i++) { //Вывод массива
        for (int j{ 0 }; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // Освобождение памяти
    for (int i{ 0 }; i < rows; i++) {
        delete[] arr[i]; // Освобождаем память для каждой строки
    }
    
    delete[] arr; // Освобождаем память для массива указателей

    return 0;
}
```

String of Symbols
=====================
```c++
#include <iostream>
using namespace std;

int main(){

	char str_arr[] = "string"; // "" - string
							   // '' - ASCII
	cout << str_arr;

	return 0;

}
```

Строка в массиве \ Строка тип данных
=====================
```c++
#include <iostream>
#include <string>
using namespace std;

int main(){
	string str_1 = "Hell";
	char arr[] = "Hell";
	
	cout << arr << endl;
	cout << str_1 << endl;

	return 0;
}
```

String Methods
=====================

- `strlen` - Возвращает длину строки

- `strcpy` - Копирует строку в другую строку

- `strncpy` - Копирует строку с ограничением количества символов

- `strcmp` - Сравнивает две строки

- `strcat` - Конкатенирует строки

- `strncat`	- Конкатенирует строки с ограничением символов

- `strchr` - Находит первое вхождение символа char 

- `strrchr` - Находит последнее вхождение символа	char 

- `strstr` - Находит первое вхождение подстроки	

- `strspn` - Подсчитывает длину участка, содержащего только символы из заданного набора

- `strcspn` - Подсчитывает длину участка до любого символа из заданного набора

- `strtok` - Разделяет строку на токены, используя разделители

Fstream - Работа с файлами
=====================

Работа с записью в файлы:
###
```C++
#include <iostream>
#include <fstream> //Library that use stream work with files 
using namespace std;

int main() {
	
	string path = "test.txt"; //Путь к нашему файлу
 	ofstream fout; //Создаем обьект класса
	fout.open(path); //Используем метод к обьекту, файлы создаются заново
	//fout.open(path, ofstream::app); Если файл не найден он создается, иначе просто дописываются данные
	
	//Проверка 
	if (!fout.is_open()) {
		cout << "Error - File was not opened!";
	}
	else {
		cout << "File was opened";
	}

	fout << "o"; // Запись в файл
	

	fout.close(); // Закрытие файла

	return 0;
}
```

Если мы хотим прочесть файл, то:
###
```C++
#include <iostream>
#include <fstream>
using namespace std;

int main() {

	string path = "test.txt"; //Путь к файлу и его название
	
	ifstream fin; //Создаем обьект класса ifstream

	fin.open(path); //Открываем файл

	if (!fin.is_open()) {
		cout << "File was not opened" << endl;
	}
	else {
		cout << "File was opened" << endl;
	}

	char symb;

	while (fin.get(symb)) { // Метод fin вносит в char символ из текста, мы его выводим
		cout << symb;
	}

	fin.close(); //Закрываем файл

	return 0;
}
```
Пример использование потока ввода <ost>
###
```C++
#include <iostream>
#include <fstream>
using namespace std;

int main() {

	string out_path = "output.txt";
	ofstream ost(out_path);

	char a[] = "123\n456\0";

	for (int i{ 0 }; i < strlen(a); i++) {
		ost << a[i];
	}

	return 0;
}
```

Пример использования потока вывода <ist>
###
```C++
#include <iostream>
#include <fstream>
using namespace std;

int main() {

	string inp_path = "input.txt";
	ifstream ist(inp_path);

	char* buffer = new char[255]; //Буфер для записи строк из файла(строка считается по пробелам)

	while (ist >> buffer) {
		cout << buffer;
	}

	return 0;
}
```