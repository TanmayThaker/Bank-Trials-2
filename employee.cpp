/*!
    Including necessary libraries and header files
*/
#include <bits/stdc++.h>
#include <fstream>
#include <mutex>
#include <thread>
#include <unistd.h>
using namespace std;
#include "employee.h"
//#include "logger.h"

//! managerSalary to store salary of manager
float managerSalary;
//! cashierSalary to store salary of cashier
float cashierSalary;

//! Employee class default constructor
Employee ::Employee()
{
    Salary = 0;
}
list<int> li;

//! Function to set Salary of employee
/*!
    \param integer argument
 */
void Employee ::setSalary(int sal)
{
    // Logger::Info("Setting Salary Of Employee");
    cout << "Salary of the employee has been updated" << endl;
    Salary = sal;
}
//! A Virtual Member Function to get salary of Employee.
/*!
    \param returns Salary of employee.
 */
int Employee::getSalary()
{
    // Logger::Info("Getting Salary Of Employee");
    cout << "Salary is: " << Salary;
    return Salary;
}
//! Function to set data about Employee
void Employee ::setData()
{
    // Logger::Info("Writing data about Employee");
    string name;
    cout << "Employee ID: ";
    cin >> EmpID;
    cin.ignore();
    li.push_back(EmpID);
    cout << "Employee Name: ";
    cin >> name;
    EmpName.push_back(name);
    cin.ignore();
    string post;
    cout << "Employee's Post: ";
    cin >> post;
    Post.push_back(post);
    cin.ignore();

    if (post == "Manager")
    {
        cout << "Manager's Salary: ";
        cin >> managerSalary;
        while (managerSalary < 0)
        {
            // Logger::Error("Invalid manager salary entered");
            cout << "Please enter a valid number!" << endl;
            cin >> managerSalary;
        }
        // cout << "Manager Salary input: " << managerSalary << endl;
    }
    else if (post == "Cashier")
    {
        cout << "Cashier's Salary: ";
        cin >> cashierSalary;
        while (cashierSalary < 0)
        {
            // Logger::Error("Invalid cashier salary entered");
            cout << "Please enter a valid number!" << endl;
            cin >> cashierSalary;
        }
        // cout << "Cashier Salary input: " << cashierSalary << endl;
    }
    else
    {
        cout << "Salary: ";
        cin >> Salary;
        while (Salary < 0)
        {
            // Logger::Error("Invalid salary entered");
            cout << "Please enter a valid number" << endl;
            cin >> Salary;
        }
    }
    cin.ignore();
    string department;
    cout << "Employee's Department:";
    cin >> department;
    Department.push_back(department);
    cin.ignore();
    /*
    cout << "Current Size is: " << EmpName.size() << "\n";
    cout << "Current Size is: " << Department.size() << "\n";
    cout << "Current Size is: " << Post.size() << "\n";*/
    exportDataAsCSV();
}

// !Function to export data of employee
void Employee ::exportDataAsTxt()
{
    // Logger::Info("Exporting Data of Employee in txt format");
    ofstream MyFile("employeeData.txt", ios::out | ios::app);
    // MyFile << GetID();
    int empNameSize = EmpName.size() - 1;
    int empPostSize = Post.size() - 1;
    if (Post[empPostSize] == "Cashier")
    {
        MyFile << "Employee ID: " << EmpID << "\nEmployee Name: " << EmpName[empNameSize] << "\nDepartment: " << Department[empNameSize] << "\nSalary: " << cashierSalary << "\n";
    }
    else if (Post[empPostSize] == "Manager")
    {
        MyFile << "Employee ID: " << EmpID << "\nEmployee Name: " << EmpName[empNameSize] << "\nDepartment: " << Department[empNameSize] << "\nSalary: " << managerSalary << "\n";
    }
    else
    {
        MyFile << "Employee ID: " << EmpID << "\nEmployee Name: " << EmpName[empNameSize] << "\nDepartment: " << Department[empNameSize] << "\nSalary: " << Salary << "\n";
    }
    MyFile.close();
    /*
    for (int i = 0; i < EmpName.size(); i++)
    {
        cout << EmpName[i] << " " << Department[i] << " ";
    }*/
}

//! Function to export data as csv
void Employee ::exportDataAsCSV()
{
    // Logger::Info("Exporting data in csv format");
    fstream fout;
    fout.open("employeedata.csv", ios::out | ios::app);
    int n = EmpName.size();
    int m = Department.size();
    // cout << "Size of EmpName vector is: " << n;
    // cout << EmpID << EmpName[n - 1] << Department[m - 1] << Salary << endl;
    if (Post[n - 1] == "Manager")
    {
        fout << EmpID << "," << EmpName[n - 1] << "," << Post[n - 1] << "," << Department[m - 1] << "," << managerSalary << "\n";
        //
    }
    else if (Post[n - 1] == "Cashier")
    {
        fout << EmpID << "," << EmpName[n - 1] << "," << Post[n - 1] << "," << Department[m - 1] << "," << cashierSalary << "\n";
    }
    else
    {
        fout << EmpID << "," << EmpName[n - 1] << "," << Post[n - 1] << "," << Department[m - 1] << "," << Salary << "\n";
        //
    }
}

//! Function to display employment details
/*!
    \param id an integer argument
 */
void Employee ::getEmployeeDetails(int id)
{
    // Logger::Info("Getting Employee Details From CSV");
    fstream fin;
    fin.open("employeeData.csv", ios::in);
    int ID, sal;
    int count = 0;
    string name, department, word, line;
    vector<string> row;
    while (fin.good())
    {
        row.clear();

        // read an entire row and
        // store it in a string variable 'line'
        getline(fin, line);

        // used for breaking words
        stringstream s(line);

        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ','))
        {

            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }
        /*
        for (int i = 0; i > row.size(); i++)
        {
            cout << row[i] << endl;
        }*/
        // convert string to integer for comparision
        ID = stoi(row[0]);

        // Compare the with the present ID
        if (ID == id)
        {

            // Print the found data
            count = 1;
            cout << "Details of Employment ID: " << row[0] << " : \n";
            cout << "Name: " << row[1] << "\n";
            cout << "Post: " << row[2] << "\n";
            cout << "Department: " << row[3] << "\n";
            cout << "Salary: " << row[4] << "\n";
            break;
        }
    }

    if (count == 0)
        cout << "Record not found\n";
}
//! Function to get Employee data
/*!
    \param id of integer type
    \param counter of integer type
*/
void Employee::getEmployeeData(int id, int counter)
{
    if (counter == 2)
    {
        sleep(1);
    }
    if (counter == 3)
    {
        sleep(2);
    }
    // sleep(4);
    fstream fin;
    fin.open("employeeData.csv", ios::in);
    int ID, sal;
    int count = 0;
    string name, department, word, line;
    vector<string> row;
    while (fin.good())
    {
        row.clear();

        // read an entire row and
        // store it in a string variable 'line'
        getline(fin, line);

        // used for breaking words
        stringstream s(line);

        // read every column data of a row and
        // store it in a string variable, 'word'
        while (getline(s, word, ','))
        {

            // add all the column data
            // of a row to a vector
            row.push_back(word);
        }

        // convert string to integer for comparision
        ID = stoi(row[0]);

        // Compare the with the present ID
        if (ID == id)
        {

            // Print the found data
            count = 1;
            cout << "Details of Employment ID: " << row[0] << " : \n";
            cout << "Name: " << row[1] << "\n";
            cout << "Post: " << row[2] << "\n";
            cout << "Department: " << row[3] << "\n";
            cout << "Salary: " << row[4] << "\n";
            break;
        }
    }

    if (count == 0)
        cout
            << "Record not found\n";
}
//! Function to get Salary of Manager
int Employee ::getManagerSalary()
{
    // Logger::Info("Getting Salary Of Manager");
    return managerSalary;
}

//! Function to get Total number of Employees
/*!
  \return list size(i.e. total number of employees present currently).
*/
int Employee ::getEmployeeCount()
{
    return li.size();
}
