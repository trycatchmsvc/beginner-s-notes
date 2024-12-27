//Разработать программу, решающую следующую задачу: вычислить функцию, заданную как 
// сумму ряда с заданной точностью δ>0 (δ, х — вещественные числа, вводятся с клавиатуры). 
//Программа должна выводить : 1) сумму ряда; 2) значение соответствующей математической функции, 
// подсчитанное с помощью стандартных функций из стандартной библиотеки(#include <cmath>); 
// 3) разность этих величин.
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
using namespace std;

double sigma(double x, double delta);
double arc_x(double x, int n);

int main() {
    double x, delta;
    cout << "x delta: " << endl;
    cin >> x >> delta;

    double arcctg = M_PI / 2 - atan(x);

    cout << sigma(x, delta) << endl;
    cout <<  arcctg << endl;
    cout << fabs(sigma(x, delta) - arcctg) << endl;

    return 0;
}

double sigma(double x, double delta) {
    double sum_sigma = 0;
    int n = 0;
    double term = arc_x(x, n);

    while (fabs(term) >= delta) {
        if (n % 2 == 0) {
            sum_sigma += term;
        }
        else {
            sum_sigma -= term;
        }
        n++;
        term = arc_x(x, n);
    }

    return sum_sigma;
}

double arc_x(double x, int n) {
    return 1 / ((2 * n + 1) * pow(x, 2 * n + 1));
}
