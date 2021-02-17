#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include <vector>
#include <sstream>

int main() {
  const std::string employees_file = "employees.txt";
  const std::string admin = "admin";

  std::ifstream employees_file_stream(employees_file);

  // Employee names.
  std::string employee;
  std::vector<std::string> employees;

  // Read in the employee names.
  while (std::getline(employees_file_stream, employee)) {
    employees.push_back(employee);
  }

  std::string user_input;
  std::cout
      << "Welcome to the employee database. Please log in with your username"
      << std::endl;
  std::cin >> user_input;
  std::cout << std::endl;

  // Only valid login at this time is admin.
  if (user_input != admin) {
    std::cout << "Unknown user: " << user_input << std::endl;
    return -1;
  }

  std::cout << "Welcome admin! What would you like to do?" << std::endl;
  std::cout << std::endl;
  std::cout << "Choose an option:" << std::endl;
  std::cout << "  1. List employees" << std::endl;
  std::cout << "  2. Add employee" << std::endl;
  std::cin >> user_input;
  std::cout << std::endl;
  
  std::stringstream input_number(user_input);
  int input_number_as_int;
  
  input_number >> input_number_as_int;

  switch(input_number_as_int){
	case 1: 
  for (const auto &e : employees) {
    std::cout << e << std::endl;
  }break;
	case 2:
  std::cout << "Enter new employee name." << std::endl; 
  std::cin >> user_input;  
  employees.push_back(user_input);
  break;
	default:
  std::cout << "Invalid input" << std::endl;
  return -1;
  }
  	
  std::ofstream employees_file_ostream;
  employees_file_ostream.open(employees_file);
  for (const auto &e : employees) {
    	employees_file_ostream << e << std::endl;
  }
  employees_file_ostream.close();


  return 0;
}

