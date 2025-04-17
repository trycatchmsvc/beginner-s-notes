#define _CRT_SECURE_NO_WARNINGS
#define _OPEN_SYS_ITOA_EXT
#define _CRT_NONSTDC_NO_DEPRECATE
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype>

using namespace std;

struct node_ {
    char info[255]{};
    node_* link{ nullptr };
};

typedef node_ node;

// own
void push_back(node*& top, const char* symbol);
void print_list_own(node* head_list, fstream& ost);
void push_forward(node*& top, const char* symbol);
void fill_list(fstream& ist, node*& head);
node* lstchr(node* head, const char* symbol);

// task
node* insert_node(node* head, node* prev, node* n);
void print_list(const node* first, fstream& ost);
int is_even_digit_sum(const char* str);
int generate_random_int(int min, int max);
void process_list(node*& head);


int main() {
    node* top = nullptr;
    fstream ist, ost;
    ist.open("input.txt", ios_base::in);
    ost.open("output.txt", ios_base::out);

    fill_list(ist, top);


    process_list(top);
    print_list(top, ost);

    ist.close();
    ost.close();
    return 0;
}

int is_even_digit_sum(const char* str) {
    int sum = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i])) {
            sum += str[i] - '0';
        }
    }
    return (sum % 2 == 0);
}

int generate_random_int(int min, int max) {
    return rand() % (max - min + 1) + min;
}

void process_list(node*& head) {
    srand(time(NULL));

    node* prev = nullptr;
    node* current = head;

    while (current != nullptr) {
        if (is_even_digit_sum(current->info)) {
            for (int i = 0; i < 3; i++) {
                node* insert_nod = new node;

                int rand_int = generate_random_int(1, 9);

                char buff[255];
                itoa(rand_int, buff, 10);
                strcpy(insert_nod->info, buff);

                if (prev == nullptr) {
                    insert_nod->link = head;
                    head = insert_nod;
                }
                else {
                    insert_nod->link = prev->link;
                    prev->link = insert_nod;
                }
            }
        }

        prev = current;
        current = current->link;
    }
}

void print_list(const node* first, fstream& ost) {
    while (first != nullptr) {
        ost << first->info << " ";
        first = first->link;
    }
    ost << endl; 
}

void push_back(node*& top, const char* symbol) {
    if (top == nullptr) {
        top = new node;
        strcpy(top->info, symbol);
        top->link = nullptr;
    }
    else {
        node* k = top;
        while (k->link != nullptr) {
            k = k->link;
        }
        node* new_node = new node;
        strcpy(new_node->info, symbol);
        new_node->link = nullptr;
        k->link = new_node;
    }
}

void print_list_own(node* head_list, fstream& ost) { 
    while (head_list != nullptr) {
        if (head_list->link != nullptr) {
            ost << head_list->info << " ";
        }
        else {
            ost << head_list->info << endl;
        }
        head_list = head_list->link;
    }
}

void push_forward(node*& top, const char* symbol) {
    node* k = new node;
    strcpy(k->info, symbol);
    k->link = top;
    top = k;
}

node* insert_node(node* head, node* prev, node* n) {
    if (prev == nullptr) {р
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
        push_back(head, str_tmp);
        while (str_tmp = strtok(NULL, " ")) {
            push_back(head, str_tmp);
        }
    }
}

node* lstchr(node* head, const char* symbol) { // Аналог strchr
    while (head != nullptr) {
        if (!strcmp(head->info, symbol)) {
            return head;
        }
        head = head->link;
    }
    return nullptr;
}
