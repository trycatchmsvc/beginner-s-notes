# Задачи

Решения учебных задач. Каждый `.cpp`-файл (кроме Qt-проекта) — самостоятельная программа
со своей функцией `main`; условие задачи записано в комментарии в начале файла.

Собрать и запустить одну задачу:

```bash
g++ -std=c++17 -Wall tasks/z-tasks/block-01/z01.cpp -o z01 && ./z01
```

Проверить, что компилируются все задачи: `make check` из корня репозитория.

## Структура

```
tasks/
├── z-tasks/      # задачи Z1–Z39, сгруппированные в блоки по 3
├── practice/     # практические работы PR1–PR21
├── algorithms/   # алгоритмы и структуры данных
└── projects/     # небольшие самостоятельные программы
```

## z-tasks — задачи Z1–Z39

| Блок | Задачи | Тема |
|------|--------|------|
| [block-01](z-tasks/block-01) | [z01](z-tasks/block-01/z01.cpp), [z02](z-tasks/block-01/z02.cpp), [z03](z-tasks/block-01/z03.cpp) | Арифметика: обмен значений, деление с остатком, дробная часть |
| [block-02](z-tasks/block-02) | [z04](z-tasks/block-02/z04.cpp), [z05](z-tasks/block-02/z05.cpp), [z06](z-tasks/block-02/z06.cpp) | Ветвления: отрезки на прямой, квадратное уравнение |
| [block-03](z-tasks/block-03) | [z07](z-tasks/block-03/z07.cpp), [z08](z-tasks/block-03/z08.cpp), [z09](z-tasks/block-03/z09.cpp) | Функции: частое значение, расстояние между точками, min/max |
| [block-04](z-tasks/block-04) | [z10](z-tasks/block-04/z10.cpp), [z11](z-tasks/block-04/z11.cpp), [z12](z-tasks/block-04/z12.cpp) | Циклы: ввод последовательности, рисование символами |
| [block-05](z-tasks/block-05) | [z13](z-tasks/block-05/z13.cpp), [z14](z-tasks/block-05/z14.cpp), [z15](z-tasks/block-05/z15.cpp) | Суммы и произведения рядов |
| [block-06](z-tasks/block-06) | [z16](z-tasks/block-06/z16.cpp), [z17](z-tasks/block-06/z17.cpp), [z18](z-tasks/block-06/z18.cpp) | Табулирование функций, псевдографика |
| [block-07](z-tasks/block-07) | [z19](z-tasks/block-07/z19.cpp), [z20](z-tasks/block-07/z20.cpp), [z21](z-tasks/block-07/z21.cpp) | Массивы: вывод, подсчёт, чередование |
| [block-08](z-tasks/block-08) | [z22](z-tasks/block-08/z22.cpp), [z23](z-tasks/block-08/z23.cpp), [z24](z-tasks/block-08/z24.cpp) | То же, что block-07, но через указатели |
| [block-09](z-tasks/block-09) | [z25](z-tasks/block-09/z25.cpp), [z25-updated](z-tasks/block-09/z25-updated.cpp), [z26](z-tasks/block-09/z26.cpp), [z27](z-tasks/block-09/z27.cpp) | Сортировки массивов |
| [block-10](z-tasks/block-10) | [z28](z-tasks/block-10/z28.cpp), [z29](z-tasks/block-10/z29.cpp), [z30](z-tasks/block-10/z30.cpp) | C-строки: `rstrip`, `strip`, `join` |
| [block-11](z-tasks/block-11) | [z31](z-tasks/block-11/z31.cpp), [z32](z-tasks/block-11/z32.cpp), [z33](z-tasks/block-11/z33.cpp) | Динамические 2D-массивы: создание, отражение, транспонирование |
| [block-12](z-tasks/block-12) | [z34](z-tasks/block-12/z34.cpp), [z35](z-tasks/block-12/z35.cpp), [z36](z-tasks/block-12/z36.cpp) | Вывод 2D-массивов в поток |
| [block-13](z-tasks/block-13) | [z37](z-tasks/block-13/z37.cpp), [z38](z-tasks/block-13/z38.cpp), [z39](z-tasks/block-13/z39.cpp) | Потоки: склейка слов, обратный порядок строк, перенос текста |

## practice — практические работы

| Файл | Тема |
|------|------|
| [pr01](practice/pr01.cpp), [pr02](practice/pr02.cpp) | Заполнение матрицы относительно побочной диагонали (вывод в файл / на экран) |
| [pr03](practice/pr03.cpp) | Разбиение слитной строки на слова по заглавным буквам |
| [pr04](practice/pr04.cpp) | Динамический массив: формирование массива B из массива A |
| [pr05](practice/pr05.cpp) | Табулирование функции на интервале |
| [pr06](practice/pr06.cpp) | Сумма ряда с заданной точностью |
| [pr07](practice/pr07.cpp) | Сортировка точек по расстоянию до заданной |
| [pr08](practice/pr08.cpp) | Вычисление кусочно-заданной функции |
| [pr09](practice/pr09.cpp) | Возраст человека по дате рождения |
| [pr10](practice/pr10) | `printf` / `scanf`: арифметика двух чисел ([task1](practice/pr10/task1.cpp), [task2](practice/pr10/task2.cpp), [task4](practice/pr10/task4.cpp)) |
| [pr11](practice/pr11.cpp) | Дружественные числа |
| [pr12](practice/pr12.cpp) | Динамический массив: формирование массива B из массива A |
| [pr13](practice/pr13.cpp) | Смешивание жидкостей: объём и температура смеси |
| [pr14](practice/pr14.cpp) | Дата через n дней (`dd.mm.yy`) |
| [pr15](practice/pr15.cpp) | Матрица: текстовый файл → бинарный файл |
| [pr16](practice/pr16.cpp) | Журналы (`struct`): текстовые и бинарные файлы, сортировка |
| [pr17](practice/pr17.cpp) | Односвязный список |
| [pr18](practice/pr18.cpp) | Двусвязный список |
| [pr19](practice/pr19.cpp) | Бинарный поиск (рекурсия) |
| [pr20](practice/pr20.cpp) | Класс `journal`: разбор строк из файла |
| [pr21-qt-journal](practice/pr21-qt-journal) | Qt-приложение «Журналы» (qmake, `TestQ.pro`) |

## algorithms

| Файл | Тема |
|------|------|
| [xor-hash-map.cpp](algorithms/xor-hash-map.cpp) | Хеш-таблица с открытой адресацией и XOR-хешированием, замер времени |

## projects

| Файл | Тема |
|------|------|
| [color-objects-regex.cpp](projects/color-objects-regex.cpp) | Разбор объектов из файла с помощью `std::regex`, `enum` + `std::map` для цветов |
