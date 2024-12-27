// 3. Вывести первую цифру d из дробной части действительного десятичного числа x,
// не используя преобразование числа в строку.

#include <iostream>
#include <math.h>

int main() {
    float x = -0.131;
    float d = fabs(x - (int)x);
    int i = (int)floor(10 * d) % 10;
    std::cout << i << std::endl;
    return 0;
}
