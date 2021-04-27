#include <string>
#include <iostream>
#include <limits>

bool validate_int_greater_then_zero(int x) {
	bool isXGreaterThen0;
	x > 0 ? isXGreaterThen0 = true : isXGreaterThen0 = false;
	return isXGreaterThen0;
}

bool validate_double_greater_then_zero(double x) {
	bool isXGreaterThen0;
	x > 0.0 ? isXGreaterThen0 = true : isXGreaterThen0 = false;
	return isXGreaterThen0;
}

double prompt_validate_return_double(std::string prompt) {
	double num;
	while (true) {
		std::cout << prompt;
		std::cin >> num;

		if (std::cin.fail()) {
			std::cout << "Thats not a valid number, try again.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else {
			break;
		}
	}
	return num;
}

int prompt_validate_return_int(std::string prompt) {
	int num;
	while (true) {
		std::cout << prompt;
		std::cin >> num;

		if (std::cin.fail()) {
			std::cout << "Thats not a valid number, try again.\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			continue;
		}
		else {
			break;
		}
	}
	return num;
}