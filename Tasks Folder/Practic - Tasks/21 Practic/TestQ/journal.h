#ifndef JOURNAL_H
#define JOURNAL_H
#include <string>
#include <vector>
#include <iostream> //Для fstream и isdream

enum JournalTematics {
    default_value,
    children,
    popular,
    scientific,
    popular_science
};

class journal
{
private:
    std::string name;
    float price;
    int exemplars;
    JournalTematics tematic;
    int start_point{ 0 };
    int end_point{ 0 };

public:
    journal();

    void load_txt(std::istream& ist);
    void save_bin(std::ostream& ost);
    void load_bin(std::istream& ist);

    static void print_table_head(std::ostream& ost);
    void print_table_row(std::ostream& ost);

    std::string get_name();
    float get_price();
    int get_exemplars();
    std::string get_tematic();

    ~journal();
};

void sort_array(std::vector<journal>& array);
std::size_t load_txt(std::vector<journal>& data, std::istream& ist);
std::size_t load_bin(std::vector<journal>& data, std::istream& ist);
std::size_t save_bin(std::vector<journal>& data, std::ostream& ost);
std::size_t print_table(std::vector<journal>& data, std::ostream& ost);


#endif // JOURNAL_H
