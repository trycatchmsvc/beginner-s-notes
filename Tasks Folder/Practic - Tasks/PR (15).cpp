#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void read_array(int** &array, int const &lines, int const &columns);
void text2bin(ifstream &fin, ofstream &fout);

int main(){

    string input_path = "input.txt";
    string ouput_path = "output.bin";

    ifstream fin; 
    ofstream fout;
    
    fin.open(input_path);
    fout.open(ouput_path, ios_base::binary);
    if (fin.is_open() && fout.is_open()){
        cout << "File was opened in all streams" << endl;
    }

    text2bin(fin, fout);

    fin.close();
    fout.close();

    if (!fin.is_open() && !fout.is_open()){
        cout << "File was closed in all streams" << endl;
    }
    

    //задание 



    return 0;
}

void read_array(int** &array, int const &lines, int const &columns){
    for(int i{0}; i < lines; i++){
        for (int j{0}; j <= columns - 1; j++){
            cout << array[i][j] << ' ';
        }
        cout << endl;
    }
}

void text2bin(ifstream &fin, ofstream &fout){

    char* temp = new char[255]; // для гетлайна
    int lines, columns;
    fin.getline(temp, 255); // получаем строку с lines и columns

    //записываем параметры матрицы
    int parametrs_matrix[2]{atoi(strtok(temp, " ")), atoi(strtok(nullptr, " "))};
    lines = parametrs_matrix[0];
    columns = parametrs_matrix[1];
    
    //выводим параметры матрицы
    cout << lines << " " << columns << endl;

    //создание массива указателей
    int ** array = new int *[lines];

    // создание массивов в указателях
    for (int i{0}; i < lines; i++){
        array[i] = new int[columns];
    }

    // запись в массив чисел
    for (int i{0}; i < lines; i++){
        fin.getline(temp, 255);
        array[i][0] = atoi(strtok(temp, " "));
        for (int j{0}; j < columns - 1; j++){
            array[i][j + 1] = atoi(strtok(nullptr, " "));
        }
    }

    // переворачиваем массив
    for (int i{ 0 }; i < lines; i++) {
		for (int j(0); j < columns / 2; j++) {
			swap(array[i][j], array[i][columns - j - 1]);
		}
	}
    
    //чтение массива
    read_array(array, lines, columns);

    //запись массива в бинарный файл
    fout.write((char *)&parametrs_matrix, sizeof(int) * 2);
    for (int i{lines - 1}; i >= 0; i--){
        fout.write((char *)array[i], sizeof(int) * columns);
    }

    for (int i{0}; i < lines; i++){
        delete []array[i];
        array[i] = nullptr;
    }

    delete []array;
    array = nullptr;

}