#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

using namespace std;

void print_array(const int* arr_1, int size) { //выводит массив
    for (int i = 0; i < size; i++) {
        cout << arr_1[i] << "\t";
    }
    cout << endl;
}

void fill_array(int *arr_1, const int size) { // заполняет массив
    srand(time(NULL));
    for (int i = 0; i < size; i++) {
        arr_1[i] = rand() % 10;
    }
}
// добавление элемента в массив
void push_back(int*& arr_1, int &size, const int value) {// передаем ссылку на указатель массива
    int* newArray = new int[size + 1];                   // чтобы сделать переприсвоение
    for (int i{ 0 }; i < size; i++) {
        newArray[i] = arr_1[i];
    }
    
    newArray[size++] = value;
    delete[] arr_1;
    
    arr_1 = newArray; // переприсвоение указателя массива

}

void main() {
    int size = 4;
    int* arr = new int[size];
    
    fill_array(arr, size);
    print_array(arr, size);

    push_back(arr, size, 10);
    print_array(arr, size);

    delete[]arr;
    arr = nullptr;
}