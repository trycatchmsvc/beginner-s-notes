#include "journal.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

journal::journal()
{
    this->name = "";
    this->price = 0;
    this->exemplars = 0;
    tematic = JournalTematics::default_value;
}

void journal::load_txt(std::istream& ist)
{
    char buffer[255]; // для первоначального получения строки
    int pointer = 0; // указатель для массива
    std::string buf = ""; // хранит строку buffer
    std::string curr = "";  // сохраняет временные данные

    ist.getline(buffer, 254);

    buf = static_cast<std::string>(buffer);

    if (buf[pointer] == '\"') {
        pointer++;
        while (buf[pointer] != '\"') {
            curr = curr + buf[pointer++];
        }
        pointer = pointer + 2;
        this->name = curr;
        curr = "";
    }

    else{
        while (buf[pointer] != ' ') {
            curr = curr + buf[pointer++];
        }
        pointer++;
        this->name = curr;
        curr = "";
    }

    while (buf[pointer] != ' ') {
        curr = curr + buf[pointer++];
    }
    this -> price = stof(curr, 0);
    curr = "";
    pointer++;

    while (buf[pointer] != ' ') {
        curr = curr + buf[pointer++];
    }
    this-> exemplars = stoi(curr, 0);
    curr = "";
    pointer++;

    if (buf[pointer] == '\"') {
        pointer++;
        while (pointer != static_cast<int>(buf.length()) - 1) {
            curr = curr + buf[pointer++];
        }
    }

    else {
        while (pointer != static_cast<int>(buf.length())) {
            curr = curr + buf[pointer++];
        }
    }

    if (curr == "children") {
        this->tematic = JournalTematics::children;
    }

    else if (curr == "popular") {
        this->tematic = JournalTematics::popular;
    }
    else if (curr == "scientific") {
        this->tematic = JournalTematics::scientific;
    }
    else if (curr == "popular science") {
        this->tematic = JournalTematics::popular_science;
    }

    else {
        std::cout << "Error - Not Found tematic value\n Was set value - children" << std::endl;
        this->tematic = JournalTematics::children;
    }

}

void journal::save_bin(std::ostream& ost)
{
     this->start_point = ost.tellp();

     int len_str = static_cast<int>(this->name.length());

     ost.write((char*)&len_str, sizeof(int));

     for (int i{ 0 }; i < len_str; i++) {
         ost.write((char*)&this->name[i], sizeof(char));
     }

     ost.write((char*)&this->price, sizeof(float));

     ost.write((char*)&this->exemplars, sizeof(int));

     ost.write((char*)&this->tematic, sizeof(int));

     this->end_point = ost.tellp();
}

void journal::load_bin(std::istream& ist) {

    std::string curr = "";
    char temp;
    int len{0};
    float price{0};

    ist.read((char*)&len, sizeof(int));

    for (int i{ 0 }; i < len; i++) {
        ist.read((char*)&temp, sizeof(char));
        curr = curr + static_cast<char>(temp);
    }

    this->name = curr;

    ist.read((char*)&price, sizeof(float));

    this->price = price;

    ist.read((char*)&len, sizeof(int));

    this->exemplars = len;

    ist.read((char*)&len, sizeof(int));

    this->tematic = JournalTematics(len);

}

void journal::print_table_head(std::ostream& ost) {
    ost << "Name\t\tPrice\tExemplars\tTematic\n";
}

void journal::print_table_row(std::ostream& ost) {
    std::string theme = get_tematic();
    ost << this->name << " \t" << this->price <<
        " \t" << this->exemplars << " \t" << theme << "\n";
}

std::string journal::get_name() {
    return this->name;
}

float journal::get_price() {
    return this->price;
}

int journal::get_exemplars() {
    return this->exemplars;
}

std::string journal::get_tematic() {
    if (this->tematic == JournalTematics::children) {
        return "children";
    }
    else if (this->tematic == JournalTematics::scientific) {
        return "scientific";
    }
    else if (this->tematic == JournalTematics::popular_science) {
        return "popular_science";
    }
    else if (this->tematic == JournalTematics::popular) {
        return "popular";
    }
    else {
        return "default_value";
    }
}

journal::~journal() {
    //cout << "Destructor" << endl;
}

void sort_array(std::vector<journal>& array) {
    for (std::size_t i = 0; i < array.size(); i++) {
        bool Flag = true;
        for (std::size_t j = 0; j < array.size() - 1; j++) {
            if (!array[j].get_name().empty() && !array[j + 1].get_name().empty()) {
                if (tolower(array[j].get_name()[0]) > tolower(array[j + 1].get_name()[0])) {
                    std::swap(array[j], array[j + 1]);
                    Flag = false;
                }
            }
        }
        if (Flag) break;
    }
}

std::size_t load_txt(std::vector<journal>& data, std::istream& ist) {
    std::size_t start_size = data.size();
    journal obj;

    while (true) {
        if (ist.peek() == EOF) break;

        obj.load_txt(ist);

        if (!ist) break;

        if (obj.get_name().empty()) continue;

        data.push_back(obj);
    }

    return data.size() - start_size;
}

std::size_t load_bin(std::vector<journal>& data, std::istream& ist) {
    std::size_t start_size = data.size();
    journal obj;

    ist.clear();
    ist.seekg(0);

    while (true) {
        std::streampos current_pos = ist.tellg();

        obj.load_bin(ist);

        if (ist.fail() || ist.eof() || ist.tellg() == current_pos) {
            break;
        }

        if (obj.get_name().empty()) continue;

        data.push_back(obj);
    }

    return data.size() - start_size;
}

std::size_t save_bin(std::vector<journal>& data, std::ostream& ost) {
    std::size_t start_size = data.size();
    for (int i{ 0 }; i < static_cast<int>(start_size); i++) {
        data[i].save_bin(ost);
    }
    return start_size;
}

std::size_t print_table(std::vector<journal>& data, std::ostream& ost) {
    std::size_t start_size = data.size();

    data[0].print_table_head(ost);

    for (int i{ 0 }; i < static_cast<int>(start_size); i++) {
        data[i].print_table_row(ost);
        std::cout << std::endl;
    }

    return start_size;
}
