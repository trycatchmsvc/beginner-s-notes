#include <iostream>
#include <cstring>
#include <fstream>
#include <random>
#include <string>
#include <vector>
#include <chrono>
using namespace std;

struct node {
    int value{0};
    bool active{false};
};

class XorMap {
private:
    node* arr;
    int constant;
    const int size;

    int FreeIndex(int index) {
        int forward = index;
        int backward = index;

        while (true) {
            forward = (forward + 1) % this->size;
            if (!this->arr[forward].active) {
                return forward;
            }
            backward = (backward - 1 + this->size) % this->size;
            if (!this->arr[backward].active) {
                return backward;
            }
        }
    }

public:
    XorMap(int size_arr) : size(size_arr) {
        this->arr = new node[size_arr];
        srand(time(NULL));
        this->constant = rand() % size_arr + 1;
    };

    int Size() {
        return this->size;
    }

    void add(int value) {
        int hash = (value + this->constant) ^ value;
        int index = hash % this->size;

        if (!this->arr[index].active) {
            this->arr[index].value = value;
            this->arr[index].active = true;
            return;
        }

        index = FreeIndex(index);
        this->arr[index].value = value;
        this->arr[index].active = true;
    }
    
    void del(int key) {
        int hash = (key + this->constant) ^ key;
        int index = hash % this->size;

        int forward = index;
        int backward = index;

        do {
            if (this->arr[forward].active && this->arr[forward].value == key) {
                this->arr[forward].active = false;
                return;
            }
            if (this->arr[backward].active && this->arr[backward].value == key) {
                this->arr[backward].active = false;
                return;
            }

            forward = (forward + 1) % this->size;
            backward = (backward - 1 + this->size) % this->size;
        } while (forward != index);
    }
    
    void print_xor_map(int key) {
        int hash = (key + this->constant) ^ key;
        int index = hash % this->size;

        int forward = index;
        int backward = index;

        do {
            if (this->arr[forward].active && this->arr[forward].value == key) {
                cout << "Key: " << key << " | Value: " << this->arr[forward].value
                    << " | Active: " << this->arr[forward].active
                    << " | Index: " << forward << endl;
                return;
            }

            if (this->arr[backward].active && this->arr[backward].value == key) {
                cout << "Key: " << key << " | Value: " << this->arr[backward].value
                    << " | Active: " << this->arr[backward].active
                    << " | Index: " << backward << endl;
                return;
            }

            forward = (forward + 1) % this->size;
            backward = (backward - 1 + this->size) % this->size;

        } while (forward != index);
    }

    int find(int key) {
        int hash = (key + this->constant) ^ key;
        int index = hash % this->size;

        int forward = index;
        int backward = index;

        do {
            if (this->arr[forward].active && this->arr[forward].value == key) {
                return this->arr[forward].value;
            }
            if (this->arr[backward].active && this->arr[backward].value == key) {
                return this->arr[backward].value;
            }

            forward = (forward + 1) % this->size;
            backward = (backward - 1 + this->size) % this->size;
        } while (forward != index);
    }
};


int main()
{
    ifstream fout;
    fout.open("test.txt");
    char buff[255];
    vector<int> vec;
    
    fout.getline(buff, 254); 
    XorMap test(std::stoi(buff));


    
    while (fout.getline(buff, 254)) {
        if (strlen(buff) != 0) {
            vec.push_back(std::stoi(buff));
        }
    }


    auto begin = std::chrono::steady_clock::now();
    for (int i : vec) {
        test.add(i);
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);


    for (int i{ 0 }; i <= test.Size(); i++) {
        test.print_xor_map(i);
    }
    
    cout << test.find(4);
    
    
}

