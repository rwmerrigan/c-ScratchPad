#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>

#include "rickvalidatedata.h"

double calculate_mpg(double miles, double gallons) {
	double mpg = miles / gallons;
	return mpg = round(mpg * 100) / 100;
}

double get_miles() {
	double miles = 0;
	do {
		miles = prompt_validate_return_double("Enter Miles driven:  ");
		validate_double_greater_then_zero(miles) ? std::cout << "Thanks\n" : std::cout << "Miles driven must be greater than zero. Please try again.\n";
	} while (!validate_double_greater_then_zero(miles));
	return miles;
}

double get_gallons() {
	double gallons = 0;
	do {
		gallons = prompt_validate_return_double("Enter gallons used:  ");
		validate_double_greater_then_zero(gallons) ? std::cout << "Thanks\n" : std::cout << "Gallons driven must be greater than zero. Please try again.\n";
	} while (!validate_double_greater_then_zero(gallons));
	return gallons;
}

void open_append_close_file(double miles, double gallons) {
	std::ofstream output_file;
	output_file.open("trips.txt", std::ios::out | std::ios::app);
	output_file << std::fixed << std::setprecision(1);
	output_file << std::setw(10) << std::left << miles;
	output_file << std::setw(10) << gallons << '\n';
	output_file.close();
}

void miles_per_gallon() {
	std::cout << "Miles Per Gallon\n\n";
	char another_entry = 'y';
	while (tolower(another_entry) == 'y') {

		double miles = get_miles();
		double gallons = get_gallons();
		open_append_close_file(miles, gallons);
		
		std::cout << "Miles per gallon:          " << calculate_mpg(miles, gallons) << std::endl << std::endl;

		std::cout << "Get entries for another trip? (y/n): ";
		std::cin >> another_entry;
		std::cout << std::endl;
	}

}