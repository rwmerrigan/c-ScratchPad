#pragma once
#include <string>

bool validate_int_greater_then_zero(int x);
bool validate_double_greater_then_zero(double x);
double prompt_validate_return_double(std::string prompt);
int prompt_validate_return_int(std::string prompt);
std::string prompt_validate_return_full_name();
std::string prompt_validate_return_password();
std::string prompt_validate_return_email();
