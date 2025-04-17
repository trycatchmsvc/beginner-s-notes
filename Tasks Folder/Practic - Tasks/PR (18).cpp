#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <ctime>
#include <random>
using namespace std;

struct node {
	char info[64]{};
	node* next{ nullptr };
	node* prev{ nullptr };
};

struct list {
	node* head{nullptr};
	node* last{nullptr};
};

void push_back(list& my_list, const char* symbol) {
	node* new_node = new node;
	strcpy(new_node->info, symbol);
	
	if (my_list.head == nullptr) {
		my_list.head = new_node;
		my_list.last = new_node;
		return;
	}
	else {
		my_list.last->next = new_node;
		new_node->prev = my_list.last;
		my_list.last = new_node;
	}
}

void push_front(list& my_list, const char* symbol) {
	if (my_list.head == nullptr) {
		push_back(my_list, symbol);
	 }
	else {
		node *new_node = new node;
		strcpy(new_node->info, symbol);

		my_list.head->prev = new_node;
		new_node->next = my_list.head;
		my_list.head = new_node;
	}
}

void insert_node(list &List, node *next, node *n) {
	if (next == 0) {
		push_back(List, n->info);
		return;
	}

	if (next->prev == nullptr) {
		push_front(List, n->info);
	}

	else {
		next->prev->next = n;
		next->prev = n;
		n->next = next;
	}
}

void remove_node(list& lst, node* n) {
	if (n->prev == nullptr) {
		lst.head = n->next;
		n->next->prev = nullptr;
		delete n;
		return;
	}

	if (n->next == nullptr) {
		lst.last = n->prev;
		n->prev->next = nullptr;
		delete n;
		return;
	}

	else {
		n->prev->next = n->next;
		n->next->prev = n->prev;
		delete n;
	}
}

void print_list(list &top, fstream& ost) { //Переписать на ost поток
	for (node* current = top.head; current != nullptr; current = current->next) {
		ost << current -> info << " ";
	}
}

void print_list_rev(list& lst, fstream ost) { //Переписать на ost поток
	for (node* current = lst.last; current != nullptr; current = current->prev) {
		ost << current->info << " ";
	}
}

bool is_even_digit(node *nod) {
	bool Flag{ false };
	int temp{ 0 };

	for (int i{ 0 }; i < strlen(nod->info); i++) {
		const char* tmp = nod->info;
		temp = temp + (int)tmp[i] - 48;
	}

	if (temp % 2 == 0) {
		Flag = true;
	}

	return Flag;
}

int digit_sum(node* nod) {
	int temp{ 0 };

	for (int i{ 0 }; i < strlen(nod->info); i++) {
		const char* tmp = nod->info;
		temp = temp + (int)tmp[i] - 48;
	}
	return temp;
}

int generate_random_int(int min, int max) {
	return rand() % (max - min + 1) + min;
}

void process_list(fstream& ost, list& lst) {
	srand(time(NULL));

	node* current = lst.head;
	while (current != nullptr) {
		if (is_even_digit(current)) {
			for (int i = 0; i < 3; i++) {
				node* temp = new node;
				char tmp[255];
				int digit = generate_random_int(0, digit_sum(current));
				_itoa(digit, tmp, 10);
				strcpy(temp->info, tmp);
				insert_node(lst, current, temp);
			}
		}
		current = current->next;
	}
}


int main() {
	fstream ist;
	fstream ost;

	ist.open("input.txt");
	ost.open("output.txt");

	list my_list;
	list& lst = my_list;

	char temp[255];

	while (ist >> temp) {
		push_back(my_list, temp);
	}

	process_list(ost, lst);
	print_list(my_list, ost);


	ist.close();
	ost.close();

	return 0;
}