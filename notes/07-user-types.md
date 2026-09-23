# 7. Пользовательские типы и шаблоны

[← Работа с файлами](06-files.md) · [К оглавлению](README.md) · [Далее: ООП →](08-oop.md)

- [struct — структуры](#struct--структуры)
- [enum — перечисления](#enum--перечисления)
- [union — объединения](#union--объединения)
- [template — шаблоны](#template--шаблоны)

## struct — структуры

Структура — составной тип данных, описывающий конкретную сущность (как и класс).
Поля структуры по умолчанию открыты (`public`).

```cpp
#include <cstring>
#include <iostream>
using namespace std;

enum JournalTheme {
    children,
    popular,
    scientific,
    popular_science
};

struct JournalInfo {
    char name[255];
    float price;
    int copies;
};

struct Journal {
    JournalInfo info;
    JournalTheme theme;
};

int main() {
    Journal kids{{"Kids", 250, 3}, children}; // агрегатная инициализация
    Journal other{};
    strcpy(other.info.name, "Science");      // C-строку нельзя присвоить через =

    size_t len{2};
    Journal* array = new Journal[len];
    for (size_t i = 0; i < len; i++) {
        array[i].info.price = 100;
    }
    delete[] array;

    cout << kids.info.name << " " << kids.info.price << endl;
    return 0;
}
```

## enum — перечисления

Перечисление — набор именованных целочисленных констант. По умолчанию значения идут с `0`.

```cpp
enum JournalTheme {
    children,        // 0
    popular,         // 1
    scientific,      // 2
    popular_science  // 3
};
```

В современном C++ предпочтительнее `enum class` — его значения не «утекают» в окружающую
область видимости и не преобразуются в `int` неявно:

```cpp
enum class Color { red, green, blue };
Color c = Color::red;
```

## union — объединения

Объединение хранит **одно** из своих полей в каждый момент времени: все поля занимают
одну и ту же память. Размер объединения равен размеру самого большого поля.

```cpp
#include <iostream>
using namespace std;

struct PairStruct { // поля лежат в памяти друг за другом
    int a;
    double b;
};

union PairUnion {   // поля занимают одну и ту же память
    int a;
    double b;
};

int main() {
    cout << sizeof(PairStruct) << " " << sizeof(PairUnion) << endl; // 16 8

    PairUnion number;
    number.a = 10;
    cout << number.a << endl; // 10

    number.b = 24;            // теперь активно поле b, значение a испорчено
    cout << number.b << endl; // 24
    return 0;
}
```

## template — шаблоны

Шаблоны позволяют писать обобщённый код, работающий с разными типами данных.
Конкретный тип подставляет компилятор.

```cpp
#include <iostream>

template <typename Type>
void print(const Type& data) {
    std::cout << data << std::endl;
}

int main() {
    print(42);      // Type = int
    print(3.14);    // Type = double
    print("text");  // Type = const char*
    return 0;
}
```
