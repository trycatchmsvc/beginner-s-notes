# 8. ООП и std::map

[← Пользовательские типы](07-user-types.md) · [К оглавлению](README.md)

- [std::map](#stdmap)
- [Классы](#классы)

## std::map

`std::map` (`#include <map>`) — ассоциативный контейнер «ключ → значение», отсортированный
по ключу.

| Операция          | Поведение                                                            |
|-------------------|----------------------------------------------------------------------|
| `m[key]`          | Возвращает значение; если ключа нет — **создаёт** его                |
| `m.at(key)`       | Возвращает значение; если ключа нет — бросает `std::out_of_range`    |
| `m.count(key)`    | `1`, если ключ есть, иначе `0`                                       |
| `m.find(key)`     | Итератор на элемент или `m.end()`                                    |

## Классы

Пример класса с конструктором, деструктором, геттером, сеттером и дружественным оператором
вывода. Цвет хранится как `enum`, а для перевода в строку и обратно используются два `map`.

```cpp
#include <iostream>
#include <map>
#include <string>

enum class Color {
    red,
    green,
};

const std::map<std::string, Color> ColorMap = {
    {"red", Color::red},
    {"green", Color::green},
};

const std::map<Color, std::string> ReverseColorMap = {
    {Color::red, "red"},
    {Color::green, "green"},
};

class Object {
private:   // доступ только внутри класса
    int numb;
    Color object_color;
    int* pos;

protected: // доступ внутри класса и его наследников
    int value;

public:    // доступ отовсюду
    Object() // конструктор: список инициализации
        : numb(1), object_color(Color::green), pos(new int[1]), value(10) {}

    ~Object() { // деструктор: освобождаем ресурсы
        delete[] pos;
    }

    // Класс владеет динамической памятью, поэтому запрещаем копирование,
    // иначе две копии удалят один и тот же указатель (правило трёх).
    Object(const Object&) = delete;
    Object& operator=(const Object&) = delete;

    int get_numb() const { // геттер
        return numb;
    }

    void set_color(const std::string& color) { // сеттер с проверкой значения
        object_color = ColorMap.at(color);      // бросит исключение для неизвестного цвета
    }

    // дружественная функция имеет доступ к private-полям
    friend std::ostream& operator<<(std::ostream& os, const Object& obj);
};

// перегрузка оператора << для вывода объекта в поток
std::ostream& operator<<(std::ostream& os, const Object& obj) {
    return os << "Object numb: " << obj.numb
              << " Color: " << ReverseColorMap.at(obj.object_color);
}

int main() {
    Object obj;
    obj.set_color("red");
    std::cout << obj << std::endl; // Object numb: 1 Color: red
    return 0;
}
```
