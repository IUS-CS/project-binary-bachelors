#include <bits/stdc++.h>
#include <fstream>
#include <iostream>
#include <vector>
#include "EmployeeRecord.h"

vector<EmployeeRecord> EmployeeData;

void doInputEmployeeDataFromFile(vector<EmployeeRecord>& A) {
	string filename = "employees.txt";
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
} // doInputAirportDataFromFile>

void outputEmployeeSequence(vector<EmployeeRecord>& A){
    for (int i=0; i<A.size(); i++) { 
        cout << '\t' << A[i] << endl;
    } // for
    cout << endl;
} // outputAirportSequence

void AddEmployee(vector<EmployeeRecord>& A) {
  EmployeeRecord newRecord;
  string stringWriter;
  int intWriter; 

  // EmployeeID is incremented by 1
  newRecord.employeeId = A[A.size()-1].employeeId + 1;

  std::cout << "Enter new employee first name: " << std::endl;
  cin >> stringWriter;
  newRecord.firstName = stringWriter;

  std::cout << "Enter new employee last name: " << std::endl;
  cin >> stringWriter;
  newRecord.lastName = stringWriter;

  std::cout << "Enter new employee job title: " << std::endl;
  cin >> stringWriter;
  newRecord.jobTitle = stringWriter;

  std::cout << "Enter new employee manager: " << std::endl;
  cin >> stringWriter;
  newRecord.manager = stringWriter;

  std::cout << "Enter new employee department number: " << std::endl;
  cin >> intWriter;
  newRecord.departmentNumber = intWriter; 

  std::cout << "Enter new employee pay rate: " << std::endl;
  cin >> intWriter;
  newRecord.payRate = intWriter; 

  std::cout << "Is new employee salaried?: " << std::endl;
  cin >> stringWriter;
  newRecord.salaried = stringWriter;
  
  A.push_back(newRecord);
}

void makeSelection(){
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
    outputEmployeeSequence(EmployeeData);
    break;
  case 2:
    AddEmployee(EmployeeData);
    break;
  default:
    std::cout << "Invalid input" << std::endl;
    //return -1;
  }
}

int main() {
  doInputEmployeeDataFromFile(EmployeeData);
  makeSelection();
  return 0;
}