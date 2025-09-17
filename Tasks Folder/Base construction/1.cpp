#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <map>

using namespace std;


enum class Color :int {		
	red = 0,
	green,
	blue
};
static const std::map<std::string, Color> ColorMap = {
	{"red",Color::red},
	{"green",Color::red},
};

class Point2D {
public:
	float pos_x;
	float pos_y;
};

class Object {
private:
	Color color;
	Point2D position;
	bool xField{false};

public:
	void parse_string(char* _str) {
		char *str = strtok(_str, " ");
		
		while (str != NULL) {
			for (int i{ 0 }; str[i] != '\0'; i++) {
				str[i] = tolower(str[i]);
				if (str[i] == ',') {
					str[i] = '.';
				}
			}

			this->color = ColorMap.at(str);



			if (strcmp(str, "red") == 0 or strcmp(str, "green") == 0 or strcmp(str, "blue") == 0) {
				if (strcmp(str, "red") == 0) {
					this->color = Color::red;
				}
				else if (strcmp(str, "green") == 0) {
					this->color = Color::green;
				}
				else {
					this->color = Color::blue;
				}
			}

			else {
				if (xField == false) {
					this->position.pos_x = stof(str);
					this->xField = true;
				}
				else {
					this->position.pos_y = stof(str);
				}
			}
			str = strtok(NULL, " ");
		}
	}

	
	void print_object() {

		if (this->color == Color::red) {
			cout << "Color: red";
		}

		else if (this->color == Color::green) {
			cout << "Color: green";
		}

		else {
			cout << "Color: blue";
		}

		cout << "\nPosition x: " << this -> position.pos_x 
			<< "\nPosition y: " << this -> position.pos_y << endl;
	}

};


int main() {

	Object obj;

	char a[] = "\"green\" 12.3  3.0";
	obj.parse_string(a);

	std::cout << obj;
	//obj.print_object();

	return 0;
}