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
Journal* load_bin(istream& ist, std::size_t& len);
Journal* sort_structure_array(Journal* array, std::size_t& len);

void mode_1(fstream& fbin, fstream& fin, std::size_t len_array );
void mode_2(fstream& fbin, std::size_t len_array);
void mode_9(fstream& ist, std::size_t len, fstream& ist_2); // Own variant of work

int main() {

    fstream fin;
    fstream fbin;
    fstream fbin_2;

    fin.open("input.txt", ios_base::in);
    fbin.open("output.bin", ios_base::binary | ios_base::in | ios_base::out);
    fbin_2.open("output_2.bin", ios_base::binary | ios_base::in | ios_base::out);

    if (!fin.is_open() || !fbin.is_open() || !fbin_2.is_open()) {
        cout << "Error" << endl;
    }

    size_t len_array{ 2 };
    
    mode_1(fbin, fin, len_array);
    cout << endl;
    mode_2(fbin, len_array);

    mode_9(fbin, len_array, fbin_2);
    

    fin.close();
    fbin.close();
    fbin_2.close();
    return 0;
}

void mode_9(fstream& ist, std::size_t len, fstream& ist_2) {
    
    Journal* array = new Journal[len];
    array = load_bin(ist, len);



}

Journal* sort_structure_array(Journal* array, std::size_t& len) {

    Journal* array = new Journal[len];



    return array;
    delete[]array;

}

Journal* load_bin(istream& ist, std::size_t& len) {
    
    Journal* array = new Journal[len];
    Journal tmp;

    ist.seekg(ios_base::beg);

    for (int i{ 0 }; i < len; i++) {
        ist.read((char*)&tmp, sizeof(Journal));
        array[i] = tmp;
    }

    return array;
    delete[]array;
}

void mode_1(fstream& fbin, fstream& fin, std::size_t len_array) {

    Journal* array = new Journal[len_array];
    array = load_txt(fin, len_array);

    print_structure(array, len_array);
    
    save_bin(array, len_array, fbin);

    delete[]array;
}

void mode_2(fstream& ost, std::size_t len) {
    Journal* array = new Journal[len];
    
    array = load_bin(ost, len);
    print_structure(array, len);

    delete[]array;
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
    delete[]array;
}

char* return_char(char* array, int pointer) {
    char* out_arr = new char[128];
    int pointer_array = 0;

    for (int i = pointer; array[i] != '\"' and array[i] != '\0'; i++) {
        out_arr[pointer_array++] = array[i];
    }
    
    out_arr[pointer_array] = '\0';

    return out_arr;
    delete[]out_arr;
}

void print_structure(Journal* array, size_t& len) {

    cout << setw(20) << left << "Name" << setw(10) << left << "Price" \
         << setw(10) << left << "Exemplars" << setw(10) << right << "Tematics" << endl;
    
    for (int i{ 0 }; i < len; i++) {
        cout << setw(20) << left << array[i].info.name << right << array[i].info.price << \
            setw(10) << right << array[i].info.exemplar;
        
        switch (array[i].themes) {
            case 0:
                cout << setw(20) << right << "children" << endl;
                break;
            case 1:
                cout << setw(20) << right << "popular" << endl;
                break;
            case 2:
                cout << setw(20) << right << "scientific" << endl;
                break;
            case 3:
                cout << setw(20) << right << "popular_science" << endl;
                break;

        }
    }
}

