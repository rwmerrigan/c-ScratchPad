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
		miles = prompt_validate_return_double("\nEnter Miles driven:  ");
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

void trips_open_append_close_file(double miles, double gallons, double mpg) {
	std::ofstream output_file;
	output_file.open("trips.txt", std::ios::out | std::ios::app);
	output_file << std::fixed << std::setprecision(1);
	output_file << std::setw(10) << std::left << miles;
	output_file << std::setw(10) << std::left << gallons;
	output_file << std::setw(10) << mpg << '\n';
	output_file.close();
}

void trips_open_read_close_file() {
	std::ifstream input_file("trips.txt");
	double miles;
	double gallons;
	double mpg;
	std::cout << std::setw(10) << "Miles" << std::setw(10) << "Gallons" << std::setw(10) << "MPG" << '\n';
	if (input_file) {
		std::cout << std::fixed << std::setprecision(1);
		while (input_file >> miles >> gallons >> mpg) {
			std::cout << std::setw(10) << miles << std::setw(10) << gallons << std::setw(10) << mpg << '\n';
		}
	}
}

void miles_per_gallon() {
	std::cout << "Miles Per Gallon\n\n";
	char another_entry = 'y';
	trips_open_read_close_file();
	while (tolower(another_entry) == 'y') {
		double miles = get_miles();
		double gallons = get_gallons();
		double mpg = calculate_mpg(miles, gallons);
		trips_open_append_close_file(miles, gallons, mpg);
		
		std::cout << "\nMiles per gallon:          " << mpg << std::endl << std::endl;
		trips_open_read_close_file();
		std::cout << "\nGet entries for another trip? (y/n): ";
		std::cin >> another_entry;
		std::cout << std::endl;
	}

}