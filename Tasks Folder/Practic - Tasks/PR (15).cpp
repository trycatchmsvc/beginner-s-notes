#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

void read_array(int** &array, int const &lines, int const &columns);
void text2bin(istream &ist, ostream &ost);

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

    char* temp = new char[255]; // для гетлайна
    int lines, columns;
    fin.getline(temp, 255); // получаем строку с lines и columns

    lines = atoi(strtok(temp, " ")); // получаем первое число с строки
    columns = atoi(strtok(nullptr, " ")); // получаем второе число с strtok

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

    //чтение массива
    read_array(array, lines, columns);






    fin.close();
    fout.close();


    for (int i{0}; i < lines; i++){
        delete []array[i];
        array[i] = nullptr;
    }

    delete []array;
    array = nullptr;

    return 0;
}


void read_array(int** &array, int const &lines, int const &columns){
    for(int i{lines - 1}; i >= 0; i--){
        for (int j{columns - 1}; j >= 0; j--){
            cout << array[i][j] << ' ';
        }
        cout << endl;
    }
}