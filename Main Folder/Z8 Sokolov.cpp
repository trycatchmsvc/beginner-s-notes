//8. Определить расстояние d между двумя точками на числовой плоскости с координатами
// (x1, y1), (x2, y2). Вычисление расстояния оформить как функцию 
// float dist(float x1, float y1, float x2, float y2).

#include <iostream>
#include <cmath>
using namespace std;

float dist(float x1, float y1, float x2, float y2);

int main() {
	float x1, y1, x2, y2, res_dist;
	cout << "x1 y1 x2 y2" << endl;
	cin >> x1 >> y1 >> x2 >> y2;
	res_dist = dist(x1, y1, x2, y2);
	cout << res_dist << endl;

	return 0;
}

float dist(float x1, float y1, float x2, float y2) {
	float res;
	res = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
	return res;
}
