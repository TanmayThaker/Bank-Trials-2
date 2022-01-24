//! Including necessary libraries and header files
#include <iostream>
using namespace std;
#include "cashier.h"
//#include "logger.h"

//! Overriden function to get salary of Cashier
/*!
    \return cashierSalary of float type
*/
int Cashier ::getSalary()
{
    // Logger::Info("Getting salary of Cashier");
    cout << "Cashier salary is: " << cashierSalary;
    return cashierSalary;
}