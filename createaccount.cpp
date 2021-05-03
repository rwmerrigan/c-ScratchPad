#include <string>
#include <iostream>

#include "rickvalidatedata.h"

void create_account() {
	std::cout << "Create Account\n\n";
	std::string full_name = prompt_validate_return_full_name();
	std::string password = prompt_validate_return_password();
	char letter = full_name[0];
	full_name[0] = toupper(letter);
	for (int i = 1; i < full_name.length(); ++i) {
		letter = full_name[i];
		full_name[i] = tolower(letter);
	}

	std::cout << "Hi " << full_name << ",\n"
		<< "Thanks for creating an account!\n\n";
}
