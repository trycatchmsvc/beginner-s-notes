#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// БД Права Пользователя

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

Journal* load_txt(ifstream& ist, size_t& len);

int main() {
    
    ifstream fin;
    fin.open("input.txt");

    if (!fin.is_open()) {
        cout << "Ifstream was not opened" << endl; 
    }
    


    size_t len = 2;
    cout << load_txt(fin, len)[1].themes;


    
    

    
    fin.close();
    if (fin.is_open()) {
        cout << "Ifstream was not closed" << endl;
    }

	return 0;
}

Journal* load_txt(ifstream& ist, size_t& len) {

    

    Journal* array = new Journal[len];

    char token[128]{};
    int pointer_array{ 0 };

    for (int i{ 0 }; i < len; i++) {
        ist.getline(token, 127);
        if (token == "") {
            break;
        }
        else {
        
            bool Flag{ false };
            int pointer_symbol{0};
            int pointer_char{ 0 };
            char tematics[32]{};

            for (int i{ 0 }; token[i] != '\0'; i++) {
                if (token[i] == '\"') {
                    pointer_symbol = i;
                    Flag = true;
                    break;
                }
            }

            if (Flag == true) {
                
                for (int i{ pointer_symbol + 1 }; token[i] != '\"'; i++) {
                    tematics[pointer_char++] = token[i];
                }
                tematics[pointer_char++] = '\0';
                
                if (!strcmp(tematics, "popular science")) {
                    array[pointer_array].themes = JournalTematics::popular_science;
                }

                char* temp = strtok(token, " ");
                strcpy(array[pointer_array].info.name, temp);
                //cout << temp << endl;
                temp = strtok(NULL, " ");
                array[pointer_array].info.price = stof(temp);
                temp = strtok(NULL, " ");
                array[pointer_array].info.exemplar = stoi(temp);
            }
            if (Flag == false){
                char* temp = strtok(token, " ");
                strcpy(array[pointer_array].info.name, temp);
                temp = strtok(NULL, " ");
                array[pointer_array].info.price = stof(temp);
                temp = strtok(NULL, " ");
                array[pointer_array].info.exemplar = stoi(temp);
                temp = strtok(NULL, " ");
                
                if (!strcmp(temp, "children")) {
                    array[pointer_array].themes = JournalTematics::children;
                }
                else if (!strcmp(temp, "popular")) {
                    array[pointer_array].themes = JournalTematics::popular;
                }
                else if (!strcmp(temp, "scientific")) {
                    array[pointer_array].themes = JournalTematics::scientific;
                }
            }
            pointer_array++;
        }
    }
    return array;
}

