#include <iostream>
#include <fstream>
using namespace std;

struct node {
    char info;
    node* link;
    
    void push_back(node*& top, node*& k, const char& symbol) {
        k = new node;
        k->link = top;
        k->info = symbol;
        top = k;
    }
};

int main() {
    
    fstream ist;
    ist.open("input.txt", ios_base::in);

    if (!ist.is_open()) {
        cout << "Error" << endl;
    }

    node* top, * k;

    top = NULL;

    for (int i{ 0 }; i < 2; i++) {
        k = new node;
        k->link = top;
        k->info = (char)i;
        top = k;
    }

    k->push_back(top, k, '3');

    ist.close();
    return 0;
}
