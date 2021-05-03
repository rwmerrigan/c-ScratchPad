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

std::string prompt_validate_return_full_name() {
	std::string full_name;
	std::string first_name;
	bool valid_name = false;
	while (!valid_name) {
		std::cout << "Enter full name: ";
		getline(std::cin, full_name);

		//strip whitespace from front
		auto i = full_name.find_first_not_of(" \n\t");
		if (i > -1) {
			full_name = full_name.substr(i);
		}

		//get first name
		auto space_index = full_name.find(' ');
		if (space_index == -1) {
			std::cout << "You must enter your full name. Please try again.\n";
		}
		else {
			first_name = full_name.substr(0, space_index);
			valid_name = true;
		}
	}
	std::cout << std::endl;
	return full_name;
}

std::string prompt_validate_return_password() {
	//get the password
	std::string password;
	bool valid_password = false;
	while (!valid_password) {
		//set valid flag
		valid_password = true;

		//get password
		std::cout << "Enter password: ";
		getline(std::cin, password);

		//make sure password has at least 8 characters
		if (password.length() < 8) {
			std::cout << "Password must be at least 8 characters.\n";
			valid_password = false;
		}

		//make sure password includes a number
		auto index = password.find_first_of("0123456789");
		if (index == -1) {
			std::cout << "Password must include a number.\n";
			valid_password = false;
		}

		//make sure password includes a special character
		bool special_character = false;
		for (char c : password) {
			if (ispunct(c)) {
				special_character = true;
				break;
			}
		}

		if(!special_character){
			std::cout << "Password must include a special character.\n";
			valid_password = false;
		}

		//display message if password is not valid
		if (!valid_password) {
			std::cout << "Please try again";
		}
	}
	std::cout << std::endl;
	return password;
}