#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>

void futurevalue() {
    std::cout << "The Future Value Calculator\n\n";
    std::vector<double> monthly_investments;
    std::vector<double> yearly_rates;
    std::vector<double> years_vector;
    std::vector<double> future_values;
    char choice = 'y';
    while (choice == 'y' || choice == 'Y') {
        double monthly_investment;
        std::cout << "Enter monthly investment:   ";
        std::cin >> monthly_investment;
        monthly_investments.push_back(monthly_investment);

        double yearly_rate;
        std::cout << "Enter yearly interest rate: ";
        std::cin >> yearly_rate;
        yearly_rates.push_back(yearly_rate);

        int years;
        std::cout << "Enter number of years:      ";
        std::cin >> years;
        years_vector.push_back(years);

        // convert yearly values to monthly values
        double monthly_rate = yearly_rate / 12 / 100;
        int months = years * 12;

        // calculate future value
        double future_value = 0;
        for (int i = 1; i <= months; i++) {
            future_value = (future_value + monthly_investment) *
                (1 + monthly_rate);
        }

        // round to 2 decimal places and display
        future_value = round(future_value * 100) / 100;
        std::cout << "Future Values: " << future_value << std::endl;
        future_values.push_back(future_value);

        // see if the user wants to continue
        std::cout << "Continue? (y/n): ";
        std::cin >> choice;
        std::cout << std::endl;
    }
    std::cout << std::setprecision(2) << std::fixed;
    std::cout << std::setw(20) << std::left << "Monthly Investment"
        << std::setw(20) << std::left << "Yearly rate"
        << std::setw(20) << std::left << "Years"
        << std::setw(20) << std::left << "Future Value\n";

    for (int index = 0; index < monthly_investments.size(); index++) {
        std::cout << std::setw(20) << std::left << monthly_investments[index]
            << std::setw(20) << std::left << yearly_rates[index]
            << std::setw(20) << std::left << years_vector[index]
            << std::setw(20) << std::left << future_values[index] << std::endl;
    }

}