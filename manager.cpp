//! Including necessary libraries and header files
#include <iostream>
using namespace std;
#include "manager.h"
//#include "logger.h"

//! Overriden function to get salary of Manager
/*!
    \return managerSalary of float type
*/
int Manager ::getSalary()
{
    // Logger::Info("Getting salary of Manager");
    cout << "Manager salary is: " << managerSalary;
    return managerSalary;
}