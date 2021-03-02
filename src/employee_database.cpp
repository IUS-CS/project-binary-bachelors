#include "user_interface.h"
#include <bits/stdc++.h>
#include <fstream>
#include <vector>

UserInterface interactions = UserInterface();
vector<EmployeeRecord> EmployeeData;
string filename = "employees.txt";

void doInputEmployeeDataFromFile(vector<EmployeeRecord> &A) {
  ifstream infile(filename);
  EmployeeRecord r;
  int dataSize;

  if (!infile) {
    cout << "Unable to open file";
    exit(1); // terminate with error
  }
  if (infile.is_open()) {
    // The first item in the data file is an integer
    // it represents how many records are in the data file.
    infile >> dataSize;
    for (int j = 0; j < dataSize; j++) {
      infile >> r.employeeId;
      infile >> r.firstName;
      infile >> r.lastName;
      infile >> r.jobTitle;
      infile >> r.manager;
      infile >> r.departmentNumber;
      infile >> r.payRate;
      infile >> r.salaried;
      A.push_back(r);
    } // end for
    infile.close();
  } // end if
} // doInputEmployeeDataFromFile>

void doOutputEmployeeDataToFile(vector<EmployeeRecord> &A) {
  ofstream ofile;
  ofile.open(filename);
  ofile << A.size() << endl;
  for (int i = 0; i < A.size(); i++) {
    ofile << A[i].employeeId << " " << A[i].firstName << " " << A[i].lastName
          << " " << A[i].jobTitle << " " << A[i].manager << " "
          << A[i].departmentNumber << " " << A[i].payRate << " "
          << A[i].salaried << endl;
  }
  ofile.close();
}

void AddEmployee(vector<EmployeeRecord> &A) {
  EmployeeRecord new_record;
  string stringWriter;
  int intWriter;

  // EmployeeID is incremented by 1
  new_record.employeeId = A[A.size() - 1].employeeId + 1;

  std::cout << "Enter new employee first name: " << std::endl;
  cin >> stringWriter;
  new_record.firstName = stringWriter;

  std::cout << "Enter new employee last name: " << std::endl;
  cin >> stringWriter;
  new_record.lastName = stringWriter;

  std::cout << "Enter new employee job title: " << std::endl;
  cin >> stringWriter;
  new_record.jobTitle = stringWriter;

  std::cout << "Enter new employee manager: " << std::endl;
  cin >> stringWriter;
  new_record.manager = stringWriter;

  std::cout << "Enter new employee department number: " << std::endl;
  cin >> intWriter;
  new_record.departmentNumber = intWriter;

  std::cout << "Enter new employee pay rate: " << std::endl;
  cin >> intWriter;
  new_record.payRate = intWriter;

  std::cout << "Is new employee salaried?: " << std::endl;
  cin >> stringWriter;
  new_record.salaried = stringWriter;

  A.push_back(new_record);
}

void makeSelection() {
  string user_input;
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

  switch (input_number_as_int) {
  case 1:
    interactions.outputEmployeeData(EmployeeData);
    break;
  case 2:
    AddEmployee(EmployeeData);
    break;
  default:
    std::cout << "Invalid input" << std::endl;
    // return -1;
  }
}

int main() {
  doInputEmployeeDataFromFile(EmployeeData);
  makeSelection();
  doOutputEmployeeDataToFile(EmployeeData);
  return 0;
}
