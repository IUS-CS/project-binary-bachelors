// This program shows an example of Open Record, all content are public!
// compiled with g++ -std=c++1z EmployeeRecord.h

#pragma once
#include <iostream>
#include <string>
using namespace std;

// Create EmployeeRecord
//
class EmployeeRecord {
public:
  int employeeId;
  string firstName;
  string lastName;
  string jobTitle;
  string manager;
  int departmentNumber;
  double payRate;
  string salaried;

  EmployeeRecord() {}
  ~EmployeeRecord() {}

  void clear(void) {
    employeeId = 0;
    firstName = "";
    lastName = "";
    jobTitle = "";
    manager = "";
    departmentNumber = 0;
    payRate = 0.0;
    salaried = "false";
  } // clear

  void transferFrom(EmployeeRecord &source) {
    employeeId = source.employeeId;
    firstName = source.firstName;
    lastName = source.lastName;
    jobTitle = source.jobTitle;
    manager = source.manager;
    departmentNumber = source.departmentNumber;
    payRate = source.payRate;
    salaried = source.salaried;
  } // transferFrom

  // overloading the output operator.The outputSequence function will make use
  // of this. Must be friend becuse EmployeeRecord is not primitive type.

  friend ostream &operator<<(ostream &os, EmployeeRecord &r) {
    os << "(" << r.employeeId << "," << r.firstName << "," << r.lastName << ","
       << r.jobTitle << "," << r.manager << "," << r.departmentNumber << ","
       << r.payRate << "," << r.salaried << ")";
    return os;
  } // operator <<
};
