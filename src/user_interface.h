#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include "employee_record.h"
#include <vector>

class UserInterface {
public:
  UserInterface();
  ~UserInterface();
  void outputEmployeeData(vector<EmployeeRecord> &A);
};
#endif
