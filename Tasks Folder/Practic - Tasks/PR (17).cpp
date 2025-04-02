#define _CRT_SECURE_NO_WARNINGS
#define _OPEN_SYS_ITOA_EXT
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

using namespace std;

struct node_ {
    char info[255]{};
    node_* link{ nullptr };
};

typedef node_ node;

//own
void push_back(node*& top, const char* symbol);
void print_list_own(node* head_list);
void push_forward(node*& top, const char* symbol);
void fill_list(fstream& ist, node*& head);
node* lstchr(node* head, const char* symbol);

//task
node* insert_node(node* head, node* prev, node* n);
void print_list(const node* first, fstream& ost);
bool is_even_digit_sum(const char* str);
int generate_random_int(int min, int max);
void process_list(node* head);


int main() {

    node* top = nullptr; //create head of list
    fstream ist, ost;
    ist.open("input.txt", ios_base::in);
    ost.open("output.txt", ios_base::out);


    fill_list(ist, top);   

    print_list(top, ost);
    print_list_own(top);
    process_list(top);
    print_list_own(top);
    


    ist.close();
    ost.close();
    return 0;
}

bool is_even_digit_sum(const char* str) {
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        sum += (int)str[i] - 48;
    }
    return (sum % 2 == 0);
}

// Генерация случайного числа в заданном диапазоне [min, max]
int generate_random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Поиск и вставка чисел в список, если узел соответствует условию
void process_list(node* head) {
    srand(time(NULL));

    node* prev = nullptr;
    while (head != nullptr) {
        if (is_even_digit_sum(head->info)) {
            for (int i = 0; i < 3; i++) {
                node* insert_nod = new node;

                int rand_int = generate_random_int(1, 10);

                char buff[255];
                itoa(rand_int, buff, 10);
                strcpy(insert_nod->info, buff);

                head = insert_node(head, prev, insert_nod);
            }
        }

        prev = head;
        head = head->link;
    }
}


void print_list(const node* first, fstream& ost) {
    while (first != 0x0) {
        char temp[255];
        strcpy(temp, first->info);
        ost << temp << " ";
        first = first->link;
    }
}

void push_back(node*& top, const char* symbol) {
    char temp[255] = "";
    strcpy(temp, symbol);
    if (top == nullptr) {
        top = new node;

        strcpy(top->info, temp);
        top->link = nullptr;
    }

    else {
        node* k = top;
        while (k->link != nullptr) {
            k = k->link;
        }
        k->link = new node;
        strcpy(k->link->info, symbol);
        k->link->link = nullptr;
    }
}

void print_list_own(node* head_list) {
    while (head_list != 0x0) {
        if (head_list->link != nullptr) {
            cout << head_list->info << " -> ";
        }
        else {
            cout << head_list->info << endl;
        }
        head_list = head_list->link;
    }
}

void push_forward(node*& top, const char* symbol) {
    char temp[255];
    strcpy(temp, symbol);
    if (top == nullptr) {
        push_back(top, symbol);
    }
    else {
        node* k = new node;
        k->link = top;
        strcpy(k->info, temp);
        top = k;
    }
}

node* insert_node(node* head, node* prev, node* n) {
    if (prev == nullptr) {
        push_forward(head, n->info);
    }

    else {
        n->link = prev->link;
        prev->link = n;
    }
    return head;
}

void fill_list(fstream& ist, node*& head) {
    char temp[255]{};
    char* str_tmp;

    while (ist.getline(temp, 244)) {
        str_tmp = strtok(temp, " ");
        //cout << str_tmp << endl;
        push_back(head, str_tmp);
        while (str_tmp = strtok(NULL, " ")) {
            push_back(head, str_tmp);
        }
    }
}

node* lstchr(node* head, const char* symbol) { // Analog of strchr
    bool Flag{ false };
    while (head->link != nullptr) {
        if (!strcmp(head->info, symbol)) {
            Flag = true;
            return head;
            break;
        }
        head = head->link;
    }
    if (!strcmp(head->info, symbol)) { // Костыль   
        Flag = true;
        return head;
    }
    if (Flag == false) {
        return 0x0;
    }
}


