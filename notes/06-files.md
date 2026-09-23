# 6. Работа с файлами — fstream

[← Строки](05-strings.md) · [К оглавлению](README.md) · [Далее: пользовательские типы →](07-user-types.md)

- [Режимы открытия](#режимы-открытия)
- [Запись в текстовый файл](#запись-в-текстовый-файл)
- [Чтение текстового файла](#чтение-текстового-файла)
- [Чтение по словам и построчно](#чтение-по-словам-и-построчно)
- [Бинарные файлы](#бинарные-файлы)

Классы для работы с файлами подключаются через `#include <fstream>`:

- `ofstream` — запись в файл;
- `ifstream` — чтение из файла;
- `fstream` — чтение и запись.

## Режимы открытия

| Флаг               | Значение                                           |
|--------------------|----------------------------------------------------|
| `ios_base::in`     | Чтение                                             |
| `ios_base::out`    | Запись                                             |
| `ios_base::binary` | Двоичный режим                                     |
| `ios_base::ate`    | После открытия указатель стоит в конце файла       |
| `ios_base::app`    | Запись всегда в конец файла (дозапись)             |
| `ios_base::trunc`  | Содержимое файла стирается при открытии            |

Флаги комбинируются через `|`: `ios_base::out | ios_base::app`.

## Запись в текстовый файл

```cpp
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    string path = "test.txt";
    ofstream fout;
    fout.open(path);                  // файл создаётся заново
    // fout.open(path, ofstream::app); // дозапись в конец файла

    if (!fout.is_open()) {
        cout << "Error: file was not opened" << endl;
        return 1;
    }

    fout << "Hello, file!" << endl;
    fout.close();
    return 0;
}
```

## Чтение текстового файла

```cpp
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ifstream fin("test.txt"); // открыть можно сразу в конструкторе

    if (!fin.is_open()) {
        cout << "Error: file was not opened" << endl;
        return 1;
    }

    char symbol;
    while (fin.get(symbol)) { // посимвольное чтение
        cout << symbol;
    }
    return 0; // файл закроется автоматически в деструкторе
}
```

## Чтение по словам и построчно

```cpp
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ifstream ist("input.txt");

    string word;
    while (ist >> word) { // оператор >> читает до пробельного символа
        cout << word << endl;
    }

    ist.clear();          // сбрасываем флаг конца файла
    ist.seekg(0);         // и возвращаемся в начало

    string line;
    while (getline(ist, line)) { // чтение целой строки
        cout << line << endl;
    }
    return 0;
}
```

## Бинарные файлы

Перемещение по файлу:

- `seekg` / `seekp` — переместить указатель чтения / записи;
- `tellg` / `tellp` — узнать текущую позицию указателя.

**Запись**

```cpp
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ofstream fout("test.bin", ios_base::binary);
    if (!fout) {
        cout << "Error: file was not opened" << endl;
        return 1;
    }

    int arr[3]{1, 2, 3};
    fout.write(reinterpret_cast<const char*>(arr), sizeof(arr));
    return 0;
}
```

**Чтение**

```cpp
#include <fstream>
#include <iostream>
using namespace std;

int main() {
    ifstream fin("test.bin", ios_base::binary);

    int value;
    while (fin.read(reinterpret_cast<char*>(&value), sizeof(value))) {
        cout << value << endl;
    }
    return 0;
}
```
