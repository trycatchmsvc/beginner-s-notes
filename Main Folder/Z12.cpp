//12. Даны целые числа x, y, sx, sy. Вывести прямоугольник из символов «@» с размерами sx 
// по горизонтали, sy по вертикали, левый верхний угол которого находится в точке с 
// координатами (x, y). Ось X направлена вправо, ось Y — вниз. Начало координат находится
// в левом верхнем углу в точке (0,0). Вывод прямоугольника оформить 
// как функцию void print_rect(int x, int y, int sx, int sy).
#include <iostream>
#include <string>
using namespace std;

void print_rect(int x, int y, int sx, int sy);

int main() {
	int x, y, sx, sy;
	cout << "x y sx sy" << endl;
	cin >> x >> y >> sx >> sy;

	print_rect(x, y, sx, sy);
	return 0;
}

void print_rect(int x, int y, int sx, int sy) {
	int i{0}, i2, i3, i4 = 0;
	string space = "";
	string str = "";

	for (i; i != x; i++) {
		cout << endl;
	}

	for (i2 = 0; i2 != y; i2++) {
		space = " " + space;
	}
	
	for (i3 = 0; i3 != sx; i3++) {
		str = str + "@";
	}

	while (i4 != sy) {
		cout << space << str << endl;
		i4++;
	}
}