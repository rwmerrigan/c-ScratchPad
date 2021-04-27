#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>


void wages_open_read_close_file() {
	std::ifstream input_file("trips.txt");
	if (input_file) {
		std::string name, line;
		std::stringstream ss;
		double hourly_wage, hours, total_wages;
		int lines_read = 0;
		int lines_processed = 0;
		std::cout << std::fixed << std::setprecision(1);

		while (getline(input_file, line)) {
			++lines_read;
			ss.str(line);
			ss.clear();
			if (ss >> name >> hourly_wage >> hours) {
				++lines_processed;
				std::cout << std::setw(15) << std::left << name
					<< std::setw(12) << std::right << hourly_wage
					<< std::setw(12) << std::right << hours
					<< std::setw(12) << std::right << hourly_wage * hours << std::endl;
			}
		}
		std::cout << std::endl << lines_processed << " lines processed.";
		//std::cout << std::endl << lines_read - lines_processed << " lines not read.";
		input_file.close();
	}
}

void employee_wage() {

	std::cout << std::setw(15) << std::left << "Name"
		<< std::setw(12) << std::right << "Hourly Wage"
		<< std::setw(12) << std::right << "Hours"
		<< std::setw(12) << std::right << "Total\n";
	std::cout << std::setw(15) << std::left << "--------------"
		<< std::setw(12) << std::right << "----------"
		<< std::setw(12) << std::right << "----------"
		<< std::setw(12) << std::right << "----------\n";
	wages_open_read_close_file();
}
