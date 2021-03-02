#include "user_interface.h"
#include <bits/stdc++.h>
#include <fstream>
#include <vector>

UserInterface interactions = UserInterface();
vector<EmployeeRecord> EmployeeData;
string filename = "employees.txt";

// Inputs all employee data from the employees.txt file to the EmployeeData
// vector.
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

// Outputs all employee data from the EmployeeData vector back to employees.txt
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

// Adds a new employee to the database.
void AddEmployee(vector<EmployeeRecord> &A) {
  EmployeeRecord new_record;
  string stringWriter;
  int intWriter;
  // Opening id.txt to get new employee Id.
  string id_file = "id.txt";
  ifstream infile(id_file);
  ofstream ofile;
  // Creates a temp file to move the unused ids into.
  ofile.open("temp.txt");
  // Sets the first id in the list to be the new employee's id.
  infile >> new_record.employeeId;

  // Puts the rest of the ids into temp file.
  while (std::getline(infile, stringWriter)) {
    infile >> stringWriter;
    ofile << stringWriter << std::endl;
  }
  infile.close();
  ofile.close();
  remove("id.txt");
  // Renames the temp file to replace old id.txt.
  rename("temp.txt", "id.txt");

  // Loads all information from the user into the new employee's information.
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

  // Adds record to the back of the list.
  A.push_back(new_record);
}

// Deletes an employee from the database.
void DeleteEmployee(vector<EmployeeRecord> &A) {
  int intWriter;
  std::cout << "Enter the id number of the employee to be removed: "
            << std::endl;
  cin >> intWriter;
  interactions.DeleteEmployee(A, intWriter);
}

// Lets the user choose what they want to do.
void makeSelection() {
  int user_input;
  std::cout << "Welcome admin! What would you like to do?" << std::endl;
  std::cout << std::endl;
  std::cout << "Choose an option:" << std::endl;
  std::cout << "  1. List employees" << std::endl;
  std::cout << "  2. Add employee" << std::endl;
  std::cout << "  3. Delete employee" << std::endl;
  std::cin >> user_input;
  std::cout << std::endl;

  switch (user_input) {
  case 1:
    interactions.outputEmployeeData(EmployeeData);
    break;
  case 2:
    AddEmployee(EmployeeData);
    break;
  case 3:
    DeleteEmployee(EmployeeData);
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
