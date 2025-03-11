#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

struct JournalInfo {
    char name[255];
    float price;
    int exemplar;
};

enum JournalTematics {
    children,
    popular,
    scientific,
    popular_science
};

struct Journal {
    JournalInfo info;
    JournalTematics themes;
};

Journal* load_txt(istream& ist, std::size_t& len);
char* return_char(char* array, int pointer);
void print_structure(Journal* array, size_t& len);
void save_bin(const Journal * data, std::size_t len, fstream& ost);

void mode_1(fstream& fbin, fstream& fin, std::size_t len_array );
void mode_2(fstream& fbin, std::size_t len_array);

int main() {

    fstream fin;
    fstream fbin;

    fin.open("input.txt", ios_base::in);
    fbin.open("output.bin", ios_base::binary | ios_base::in | ios_base::out);
    
    if (!fin.is_open() || !fbin.is_open()) {
        cout << "Error" << endl;
    }

    size_t len_array{ 2 };
    
    mode_1(fbin, fin, len_array);
       


    
    

    fin.close();
    fbin.close();
    return 0;
}

void mode_1(fstream& fbin, fstream& fin, std::size_t len_array) {

    Journal* array = new Journal[len_array];
    array = load_txt(fin, len_array);

    print_structure(array, len_array);

    save_bin(array, len_array, fbin);
}

void mode_2(fstream& fbin, std::size_t len_array) {

}

void save_bin(const Journal* data, std::size_t len, fstream& ost) {
    ost.write((char*)data, sizeof(Journal) * len);
}

Journal* load_txt(istream& ist, std::size_t& len) {

    Journal* array = new Journal[len];


    for (int i{ 0 }; i < len; i++) {
        char token[128];
        ist.getline(token, 127);

        char* temp;
        int pointer{ 0 };

        if (token[0] == '\"') {
            char* arr = return_char(token, 1);
            strcpy(array[i].info.name, arr);
            temp = strtok(token, " ");
            temp = strtok(NULL, " ");
        }

        else if (token[0] != '\"') {
            temp = strtok(token, " ");
            strcpy(array[i].info.name, temp);
        }

        temp = strtok(NULL, " ");
        array[i].info.price = atof(temp);
        temp = strtok(NULL, " ");
        array[i].info.exemplar = atoi(temp);

        temp = strtok(NULL, " ");

        if (temp[0] == '\"') {
            char* arr = return_char(temp, 1);
            temp = strtok(NULL, " ");

            strcat(arr, " ");
            strcat(arr, return_char(temp, 0));

            if (!strcmp(arr, "popular science")) {
                array[i].themes = popular_science;
            }
        }

        else if (temp[0] != '\"') {
            if (!strcmp(temp, "children")) {
                array[i].themes = JournalTematics::children;
            }
            else if (!strcmp(temp, "popular")) {
                array[i].themes = JournalTematics::popular;
            }
            else if (!strcmp(temp, "scientific")) {
                array[i].themes = JournalTematics::scientific;
            }
        }
    }
    return array;
}

char* return_char(char* array, int pointer) {
    char* out_arr = new char[128];
    int pointer_array = 0;

    for (int i = pointer; array[i] != '\"' and array[i] != '\0'; i++) {
        out_arr[pointer_array++] = array[i];
    }
    out_arr[pointer_array] = '\0';

    return out_arr;
}

void print_structure(Journal* array, size_t& len) {

    cout << setw(20) << left << "Name" << setw(10) << left << "Price" << setw(10) << left << "Exemplars" << setw(10) << right << "Tematics" << endl;
    for (int i{ 0 }; i < len; i++) {
        cout << setw(20) << left << array[i].info.name << right << array[i].info.price << setw(10) << right << array[i].info.exemplar << setw(10) << right << array[i].themes << endl;
    }
}

