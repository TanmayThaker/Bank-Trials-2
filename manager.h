//! Header guards
#ifndef MANAGER
#define MANAGER
#include "employee.h"

//! Class Manager
/*
 Manger class inherits Employee class
*/
class Manager : public Employee
{
public:
    //! Function to get salary of manager
    int getSalary();
};

#endif