#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

enum JournalTematics {
	default_value,
	children,
	popular,
	scientific,
	popular_science
};

class journal {
private:
	string name;
	float price;
	int exemplars;
	JournalTematics tematic;
	int start_point{ 0 };
	int end_point{ 0 };

public:

	//Default constructor
	journal()
	{
		this->name = "";
		this->price = 0;
		this->exemplars = 0;
		tematic = JournalTematics::default_value;
	}

	void load_txt(std::istream& ist) 
	{
		char buffer[255]; // для первоначального получения строки
		int pointer = 0; // указатель для массива
		string buf = ""; // хранит строку buffer
		string curr = "";  // сохраняет временные данные

		ist.getline(buffer, 254);

		buf = static_cast<string>(buffer);

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
			while (pointer != buf.length() - 1) {
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
			cout << "Error - Not Found tematic value\n Was set value - children" << endl;
			this->tematic = JournalTematics::children;
		}

	}

	void save_bin(std::ostream& ost) 
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

	void load_bin(std::istream& ist) {
		//ist.seekg(this->start_point, ios_base::beg);

		string curr = "";
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

	static void print_table_head(std::ostream& ost) {
		ost << "Name\t\tPrice\tExemplars\tTematic\n";
	}

	void print_table_row(std::ostream& ost) {
		string theme = get_tematic();
		ost << this->name << " \t" << this->price <<
			" \t" << this->exemplars << " \t" << theme;
	}

	string get_name() {
		return this->name;
	}

	float get_price() {
		return this->price;
	}

	int get_exemplars() {
		return this->exemplars;
	}

	string get_tematic() {
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

	~journal() {
		//cout << "Destructor" << endl;
	}
};

void sort_array(std::vector<journal>& array) {
	for (std::size_t i = 0; i < array.size(); i++) {
		bool Flag = true;
		for (std::size_t j = 0; j < array.size() - 1; j++) {
			if (!array[j].get_name().empty() && !array[j + 1].get_name().empty()) {
				if (tolower(array[j].get_name()[0]) > tolower(array[j + 1].get_name()[0])) {
					swap(array[j], array[j + 1]);
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

	ist.clear();       // на всякий случай сбрасываем флаги ошибок
	ist.seekg(0);      // возвращаемся в начало файла

	while (true) {
		std::streampos current_pos = ist.tellg(); // сохраняем позицию

		obj.load_bin(ist);

		// если позиция не изменилась — значит чтение не прошло, выходим
		if (ist.fail() || ist.eof() || ist.tellg() == current_pos) {
			break;
		}

		// можно также дополнительно проверить, не пустой ли объект
		if (obj.get_name().empty()) continue;

		data.push_back(obj);
	}

	return data.size() - start_size;
}

std::size_t save_bin(std::vector<journal>& data, std::ostream& ost) {
	std::size_t start_size = data.size();
	for (int i{ 0 }; i < start_size; i++) {
		data[i].save_bin(ost);
	}
	return start_size;
}


std::size_t print_table(vector<journal>& data, std::ostream& ost) {
	std::size_t start_size = data.size();

	data[0].print_table_head(ost);
	
	for (int i{ 0 }; i < start_size; i++) {
		data[i].print_table_row(ost);
		cout << endl;
	}

	return start_size;
}



int main() {

	fstream ist; //Поток чтения обычного файла
	fstream ost; // Поток чтения и записи бинарного файла
	fstream ost_2; //Поток на запись в обычный файл
	ist.open("input.txt", ios_base::in|ios_base::out);
	ost.open("output.bin", ios_base::binary|ios_base::in|ios_base::out);
	ost_2.open("output.txt", ios_base::out);

	std::size_t size_arr = 0;
	int case_value;
	std::vector<journal> array = {};

	cout << "Enter mode(1, 2)" << endl;
	cin >> case_value; cout << endl;

	switch (case_value) {
	case 1:
		load_txt(array, ist);
		sort_array(array);
		print_table(array, std::cout);
		save_bin(array, ost);
		break;
	case 2:
		load_bin(array, ost);
		sort_array(array);
		print_table(array, std::cout);
		break;
	}

	ist.close();
	ost.close();
	ost_2.close();
	
	return 0;
}