#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include <vector>

int main() {
  const std::string employees_file = "employees.txt";
  const std::string admin = "admin";

  std::ifstream employees_file_stream(employees_file);

  // Employee names
  std::string employee;
  std::vector<std::string> employees;

  // Read in the employee names
  while (std::getline(employees_file_stream, employee)) {
    employees.push_back(employee);
  }

  std::string user_input;
  std::cout
      << "Welcome to the employee database. Please log in with your username"
      << std::endl;
  std::cin >> user_input;
  std::cout << std::endl;

  if (user_input != admin) {
    std::cout << "Unknown user: " << user_input << std::endl;
    return -1;
  }

  std::cout << "Welcome admin! What would you like to do?" << std::endl;
  std::cout << std::endl;
  std::cout << "Choose an option:" << std::endl;
  std::cout << "  1. List employees" << std::endl;
  std::cin >> user_input;
  std::cout << std::endl;

  if (user_input != "1") {
    std::cout << "Unrecognized input!" << std::endl;
    return -1;
  }

  for (const auto &e : employees) {
    std::cout << e << std::endl;
  }

  return 0;
}
