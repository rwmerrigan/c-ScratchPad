#include <iostream>
#include <fstream>
#include <string>

void rickCreateFile(std::string filename) {
	std::ofstream create_file(filename);
}
void rickOpenFile(std::string filename) {
	std::ofstream create_file(filename);
}
void rickCloseFile(std::string filename) {
	std::ofstream create_file(filename);
}
void rickOutputFileContents(std::string filename) {
	std::ifstream input_file(filename);
	if (input_file) {
		std::string line;
		while (getline(input_file, line))
			std::cout << line << '\n';
	}
	input_file.close();
}
