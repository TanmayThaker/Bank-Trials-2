//! header guard
#ifndef EMPLOYEE
#define EMPLOYEE

//! Including necessary libraries and header files
//#include "logger.h"
#include <vector>
extern float managerSalary;
extern float cashierSalary;

//! Employee class
class Employee
{

private:
    //! EmpID variable
    /*!
        EmpID integer type
        It stores the employee id
    */
    int EmpID;
    //! EmpName variable
    /*!
        EmpName is vector of string
        It stores the employee name
    */
    vector<string> EmpName;
    //! Department variable
    /*!
        Department is vector of string
        It stores the employee department
    */
    vector<string> Department;
    //! EmpID variable
    /*!
        Post vector of string
        It stores the employee Post
    */
    vector<string> Post;
    //! Salary variable
    /*!
        Salary float type
        It stores the employee salary
    */
    float Salary;

public:
    //! Employee class default constructor
    Employee();
    //! Function to set the Salary of the employee
    /*!
     \param sal of integer type
    */
    void setSalary(int sal);
    //! A Virtual Member Function to get salary of Employee.
    /*!
        \param returns Salary of employee.
     */
    virtual int getSalary();
    /*
    {
        // Logger::Info("Getting Salary Of Employee");
        cout << "Salary is: " << Salary;
        return Salary;
    }*/
    //! Function to take data of the employee
    void setData();
    //! Function to export data of the employee in txt file
    void exportDataAsTxt();
    //! Function to export data of the employee in csv file
    void exportDataAsCSV();
    //! Function to get the details of employee from file
    /*!
       \param id an integer type
    */
    void getEmployeeDetails(int id);
    //! Function to get Salary of manager
    int getManagerSalary();
    //! Function tom get Employee count
    int getEmployeeCount();
    //! Function to get Employee details using threads
    void getEmployeeData(int, int);
};

#endif