#include "user_interface.h"
#include <fstream>

UserInterface::UserInterface() {}

UserInterface::~UserInterface() {}

void UserInterface::outputEmployeeData(vector<EmployeeRecord> &A) {
  for (int i = 0; i < A.size(); i++) {
    cout << '\t' << A[i] << endl;
  } // for
  cout << endl;
} // outputEmployeeSequence

EmployeeRecord UserInterface::DeleteEmployee(vector<EmployeeRecord> &A,
                                             int id) {
  EmployeeRecord deleted_employee;
  for (int i = 0; i < A.size(); i++) {
    if (A[i].employeeId == id) {
      deleted_employee = A[i];
      ofstream ofile("id.txt", std::ios::app);
      ofile << A[i].employeeId << std::endl;
      ofile.close();
      A.erase(A.begin() + i);
      return deleted_employee;
    }
  }
  std::cout << "Not a valid input." << std::endl;
  return deleted_employee;
}
