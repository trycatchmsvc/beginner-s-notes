Datatype C++
=====================
sizeof(type data) - method for showing size of any type data

char - only one symbole OR ASCII numbers | 1 byte -128 до 127 (для signed char) 0 до 255 (для unsigned char)

bool - true (1) или false (0) | it is a logical type of data, 1 byte

string - standart data type but it need import library | #include <string>


Using namespace
=====================
std — это пространство имен (namespace) в стандартной библиотеке C++. 
В C++ пространства имен используются для организации кода и предотвращения конфликтов имен.


"Hello world" different methods
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

Format cout from iostream
=====================

**setw(n)**	n — целое число	Устанавливает минимальную ширину поля для вывода значения. Значение заполняется пробелами слева, если оно короче указанной ширины.

**setfill(c)**	c — символ заполнения	Задает символ, которым будут заполняться пустые места, если выводимое значение меньше указанной ширины (по умолчанию используется пробел).

**left**	Не принимает аргументов	Выравнивает значение по левому краю в поле заданной ширины.

**right**	Не принимает аргументов	Выравнивает значение по правому краю в поле заданной ширины (по умолчанию используется это выравнивание).

**fixed**	Не принимает аргументов	Выводит вещественные числа в фиксированном формате (без научной нотации).

**setprecision(n)**	n — целое число	Устанавливает количество знаков после запятой для вывода вещественных чисел.

**showpoint**	Не принимает аргументов	Гарантирует отображение десятичной точки для вещественных чисел, даже если она не требуется.

**noshowpoint**	Не принимает аргументов	Убирает отображение лишней десятичной точки, если она не нужна.

**scientific**	Не принимает аргументов	Выводит вещественные числа в научной нотации (формат с экспонентой).

Specificator of format FOR printf
=====================														
### Для целых чисел:

%d или %i — вывод целого числа в десятичной системе (тип int)

%u — вывод беззнакового целого числа (тип unsigned int)

%x или %X — вывод числа в шестнадцатеричной системе (малые и заглавные буквы соответственно)

%o — вывод числа в восьмеричной системе

### Для чисел с плавающей точкой:

%f — вывод числа с плавающей точкой (тип float или double)

%e или %E — вывод числа в экспоненциальной форме (например, 1.23e+03)

%g или %G — вывод числа с плавающей точкой в либо обычной, либо экспоненциальной форме, в зависимости от величины числа

### Для символов и строк:

%c — вывод одного символа (тип char)

%s — вывод строки (массив символов, тип char*)

How use russian language?
=====================
```c++
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

Logical operators
=====================

&& | and 

|| | or
																											 
Increment and Decrement
=====================

++ | Увеличивает a на 1. Префиксное и постфиксное различие

-- | Уменьшает a на 1. Префиксное и постфиксное различие

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

Generator random
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

Functions with array plus working with changed adress of pointer
=====================
```c++
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

using namespace std;

void print_array(const int* arr_1, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr_1[i] << "\t";
    }
    cout << endl;
}

void fill_array(int *arr_1, const int size) {
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr_1[i] = rand() % 10;
    }
}

void push_back(int*& arr_1, int &size, const int value) {// передаем ссылку на указатель массива
    int* newArray = new int[size + 1];                   // чтобы сделать переприсвоение
    for (int i{ 0 }; i < size; i++) {
        newArray[i] = arr_1[i];
    }
    
    newArray[size++] = value;
    delete[] arr_1;
    
    arr_1 = newArray; // переприсвоение указателя массива

}

void main() {
    int size = 4;
    int* arr = new int[size];
    
    fill_array(arr, size);
    print_array(arr, size);

    push_back(arr, size, 10);
    print_array(arr, size);

    delete[]arr;
    arr = nullptr;
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

String of arrays and String datatype from library
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

**strlen**	
###
Возвращает длину строки без \0	size_t len = strlen("Hello");	len = 5

**strcpy**	
###
Копирует строку в другую строку	char dest[6]; strcpy(dest, "Hello");	dest = "Hello"

**strncpy**	
###
Копирует строку с ограничением количества символов	char dest[6]; strncpy(dest, "Hello", 4); dest[4] = '\0';	dest = "Hell"

**strcmp**	
###
Сравнивает две строки	int res = strcmp("apple", "banana");	res < 0 (так как "apple" < "banana")

**strcat**	
###
Конкатенирует строки	char dest[12] = "Hello, "; strcat(dest, "world!");	dest = "Hello, world!"

**strncat**	
###
Конкатенирует строки с ограничением символов	char dest[10] = "Hello, "; strncat(dest, "world!", 3);	dest = "Hello, wor"

**strchr**	
###
Находит первое вхождение символа	char *pos = strchr("Hello, world!", 'w');	pos указывает на w в строке "Hello, world!"

**strrchr**	
###
Находит последнее вхождение символа	char *pos = strrchr("Hello, world!", 'o');	pos указывает на второй o в "Hello, world!"

**strstr**	
###
Находит первое вхождение подстроки	char *pos = strstr("Hello, world!", "world");	pos указывает на world в "Hello, world!"

**strspn**	
###
Подсчитывает длину участка, содержащего только символы из заданного набора	size_t len = strspn("123abc", "0123456789");	len = 3 (три цифры подряд в начале строки)

**strcspn**	
###
Подсчитывает длину участка до любого символа из заданного набора	size_t len = strcspn("Hello, world!", ",!");	len = 5 (индекс первого ,)

**strtok**	
###
Разделяет строку на токены, используя разделители	char str[] = "a,b,c"; char *token = strtok(str, ","); while (token) { ... }	token поочередно равен "a", "b", "c"
