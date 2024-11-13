//24. Написать функцию int splice_array(int arr1[], int arr2[], int len, int arr_out[]), которая соединяет массивы
// arr1[], arr2[] размера len путём чередования элементов (arr1[0], arr2[0], arr1[1], arr2[1], ...) и 
// помещает результат в arr_out[]. Функция должна возвращать размер получившегося массива.

#include <iostream>
using namespace std;

int splice_array(int *arr_1, int *arr_2, int size, int* arr_out);

int main() {
    const int len = 3;
    int arr_1[len] = { 1, 2, 3 };
    int arr_2[len] = { 4, 5, 6 };
    int* arr_out = new int[len * 2];
    
    int* pArr_1 = arr_1;
    int* pArr_2 = arr_2;

    int result_size = splice_array(pArr_1, pArr_2, len, arr_out);

    for (int i = 0; i < result_size; i++) {
        cout << *(arr_out + i) << " ";
    }
    cout << endl;

    delete[] arr_out;
    return 0;
}

int splice_array(int *arr_1, int *arr_2, int len, int* arr_out) {
    int sum_len = 0;
    for (int i = 0; i < len; i++) {
        *(arr_out + sum_len++) = *(arr_1+i);
        *(arr_out + sum_len++) = *(arr_2+i);
    }
    return sum_len;
}
