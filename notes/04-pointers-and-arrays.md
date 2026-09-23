# 4. Указатели и массивы

[← Операторы и управление](03-operators-and-control.md) · [К оглавлению](README.md) · [Далее: строки →](05-strings.md)

- [Указатели и ссылки](#указатели-и-ссылки)
- [Статические массивы](#статические-массивы)
- [Двумерные массивы](#двумерные-массивы)
- [Динамический массив](#динамический-массив)
- [Динамический двумерный массив](#динамический-двумерный-массив)

## Указатели и ссылки

- **Указатель** (`int*`) хранит адрес переменной. Получить значение по адресу — `*ptr`.
- **Ссылка** (`int&`) — другое имя для той же переменной.
- `&a` — взятие адреса переменной `a`.

```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int* ptr_a = &a; // указатель на a
    int& ref_a = a;  // ссылка на a

    a = 5;
    cout << &a << " " << *ptr_a << " " << ref_a << endl; // адрес, 5, 5
    return 0;
}
```

## Статические массивы

Размер статического массива известен на этапе компиляции. Индексация начинается с `0`.

```cpp
#include <iostream>

int main() {
    int array[3];
    int arr[3] = {1, 2, 3};                     // одномерный массив
    int arr2[3][2] = {{1, 2}, {3, 4}, {5, 6}}; // двумерный массив

    array[0] = 1; // обращение по индексу
    array[1] = 2;
    array[2] = 3;

    std::cout << array[0] << " " << arr[1] << " " << arr2[1][0] << std::endl; // 1 2 3
    return 0;
}
```

Количество элементов статического массива: `sizeof(arr) / sizeof(arr[0])`.

## Двумерные массивы

```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[3][2] = {{1, 2}, {3, 4}, {5, 6}};

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
```

## Динамический массив

Память под динамический массив выделяется во время работы программы (в куче) с помощью `new`
и **обязательно** освобождается через `delete[]`. Размер массива нужно хранить самостоятельно.

```cpp
#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main() {
    int size = 0;
    cout << "Enter size of array: ";
    cin >> size;

    int* arr = new int[size];
    srand(time(nullptr));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 10;
    }
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr; // освобождаем память в куче
    return 0;
}
```

> В реальном коде вместо ручного `new[]`/`delete[]` используют `std::vector`.

## Динамический двумерный массив

Двумерный динамический массив — это массив указателей, каждый из которых указывает на строку.

```cpp
#include <iostream>
using namespace std;

int main() {
    int rows = 3;
    int cols = 4;

    int** arr = new int*[rows]; // массив указателей на строки
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols]; // выделяем каждую строку
    }

    int value = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr[i][j] = ++value;
        }
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // освобождение памяти — в обратном порядке
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    return 0;
}
```
