#include "user_interface.h"

UserInterface::UserInterface() {}

UserInterface::~UserInterface() {}

void UserInterface::outputEmployeeData(vector<EmployeeRecord> &A) {
  for (int i = 0; i < A.size(); i++) {
    cout << '\t' << A[i] << endl;
  } // for
  cout << endl;
} // outputEmployeeSequence

