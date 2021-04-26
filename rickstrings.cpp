#include <string>
#include <iostream>

std::string rickToUpper(std::string str) {
	std::string name_upper = "";
	for (char c : str) {
		name_upper += toupper(c);
	}
	return name_upper;
}

std::string rickToLower(std::string str) {
	std::string name_lower = "";
	for (char c : str) {
		name_lower += tolower(c);
	}
	return name_lower;
}

void rickStringStats(std::string str) {
	std::cout << "String size: " << str.size() << '\n';
	int counter = 0;
	for (char c : str) {
		std::cout << "index[" << counter << "] - " << c << std::endl;
		counter++;
	}

}