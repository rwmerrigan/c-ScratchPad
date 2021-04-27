#include <iostream>
#include <fstream>
#include <string>

void rickCreateFile(std::string filename) {
	std::ofstream create_file(filename);
	create_file.close();
}

void rickOpenFile(std::string filename) {
	std::ofstream create_file(filename);
}

void rickCloseFile(std::string filename) {
	std::ofstream create_file(filename);
	create_file.close();
}

void rickOutputFileContents(std::string filename) {
	std::fstream input_file(filename, std::ios::in);
	if (input_file) {
		std::string line;
		while (getline(input_file, line))
			std::cout << line << '\n';
	}
	input_file.close();
}

void rickRemoveFileContents(std::string filename) {
	std::fstream file(filename, std::ios::out);
}

void rickOpenFileAndAppend(std::string filename) {

}
