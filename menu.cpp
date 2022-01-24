#include <mutex>
#include <thread>
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;

#include "bank.h"
#include "helper.h"
#include "employee.h"
#include "manager.h"
#include "menu.h"
#include "cashier.h"
#include "logger.h"
//! mutex for acquiring lock
mutex m1;
//! Function to display atm menu
/*!
    \param userCount an interger type
*/

void atmMenu(int userCount)
{
    Logger::Info("Atm menu function called");
    lock_guard<mutex> lock(m1);
    cout << "\n\nUser: " << userCount << endl;
    Bank bank;
    int x;
    char uname[30];
    int pass, found = 0;
    char choice2;
    cout << "\nEnter details to login as User\n ";
    cin.ignore();
    cout << "\nEnter username: ";
    cin.getline(uname, 30);
    cout << "\nEnter password: ";
    cin >> pass;

    found = bank.searchUser(uname, pass);
    if (found)
    {
        do
        {
            cout << "\nWelcome " << uname;
            cout << "\nWelcome to user Menu";
            cout << "\n 1. Deposit\n 2. Withdraw\n 3. View Account\n 4. Exit";
            cout << "\nEnter your choice:";
            cin >> choice2;
            while (isalpha(choice2))
            {
                cout << "Please enter a valid option" << endl;
                cin >> choice2;
            }
            switch (choice2)
            {
            case '1':
                bank.depositMoney(uname);
                break;

            case '2':
                bank.withdrawMoney(uname);
                break;

            case '3':
                bank.searchUserByUsername(uname);
                break;

            case '4':
                cout << "Thank you";
                break;
            default:
                cout << "Please enter a valid choice" << endl;
            }
            if (choice2 == '4')
            {
                break;
            }
            cout << "\nDo you want to continue with ATM menu? ::Y\n";
            cout << "If you want to exit then please press::N ";
            x = getch();
            if (x == 'n' || x == 'N')
                cout << "exit";
        } while (x == 'y' || x == 'Y');
    }
    else
    {
        cout << "\nNo account found with username " << uname;
    }
}

//! Function to display employee menu
void empMenu()
{
    Bank bank;
    Manager mg;
    Cashier cash;
    Employee emp;
    Employee *emp1;
    int x, y, pass, choice2;
    char uname[30];
    thread t1;
    thread t2;
    thread t3;
    while (1)
    {
        cout << "\nEnter details to login as Admin\n";
        cout << "\nEnter password:";
        cin >> pass;

        while (countDigits(pass) > 4 || countDigits(pass) < 4)
        {
            cout << "ERROR: Invalid Pin: " << endl;
            cout << "Enter your 4 digit pin please: ";
            cin >> pass;
        }
        if (pass == 1234)
        {
            do
            {
                cout << "\nWelcome to Admin/Manager Menu";
                cout << "\n 1. Add User\n 2. Delete User\n 3. View All User\n 4. Enter new record about Employee\n 5. Set Employee 's Salary \n 6. Get Employee' s Salary\n 7. Get Employment Details \n 8. Get Manager's Salary\n 9. Get Cashier's Salary\n 10. Export Data in Text Format \n 11. Get top 3 Employee Details using threads \n 12. Exit";
                cout << "\nSelect one : ";
                cin >> choice2;
                cin.clear();
                cin.ignore(100, '\n');
                switch (choice2)
                {
                case 1:
                    bank.addUser();
                    break;

                case 2:
                    cout << "\nEnter the username to be deleted : ";
                    cin.ignore();
                    cin.getline(uname, 30);
                    bank.deleteUser(uname);
                    break;

                case 3:
                    bank.ViewAllUsers();
                    break;

                case 4:
                    emp.setData();
                    break;

                case 5:
                    cout << "Enter the salary of Employee: ";
                    int sal;
                    cin >> sal;
                    while (sal < 0)
                    {
                        // Logger::Error("Invalid salary is entered");
                        cout << "Salary cannot be negative" << endl;
                        cout << "Please enter a valid salary" << endl;
                        cin >> sal;
                    }
                    emp.setSalary(sal);
                    break;

                case 6:
                    emp.getSalary();
                    break;

                case 7:
                    int id;
                    cout << "Welcome to Employee Search\n";
                    cout << "Please enter employment ID: ";
                    cin >> id;
                    emp.getEmployeeDetails(id);
                    break;

                case 8:
                    emp1 = &mg;
                    emp1->getSalary();
                    break;

                case 9:
                    emp1 = &cash;
                    emp1->getSalary();
                    break;

                case 10:
                    emp.exportDataAsTxt();
                    break;
                case 11:
                    t1 = thread(&Employee::getEmployeeData, &emp, 1, 1);
                    t2 = thread(&Employee::getEmployeeData, &emp, 2, 2);
                    t3 = thread(&Employee::getEmployeeData, &emp, 3, 3);
                    t1.join();
                    t2.join();
                    t3.join();
                    break;
                case 12:
                    break;
                default:
                    cout << "Invalid number! Please enter a valid number" << endl;
                }
                if (choice2 == 12)
                {
                    break;
                }
                cout << "\nDo you want to continue with admin menu then please press::Y\n";
                cout << "If you want to exit then please press::N ";
                x = getch();
                if (x == 'n' || x == 'N')
                    cout << "\n Exiting...";
            } while (x == 'y' || x == 'Y');
        }
        else
        {
            cout << "\nDetails are incorrect ! Please try again";
            break;
        }
        break;
    }
}

//! Function to display main menu
void mainMenu()
{
    // Logger::Info("mainMenu function called");
    int x;
    char choice;
    do
    {
        cout << "\nWelcome to Bank Management System" << endl;
        cout << "\n1. ATM Management";
        cout << "\n2. Admin/Manager Menu ";
        cout << "\n3. Exit";
        cout << "\n Enter your choice: " << endl;
        cin >> choice;
        while (isalpha(choice))
        {
            cout << "Please enter a valid chocie" << endl;
            cin >> choice;
        }
        int n = 2;
        vector<thread> threads(n);
        switch (choice)
        {
        case '1':
            int n;
            cout << "Enter number of people: " << endl;
            cin >> n;
            threads.resize(n);
            // creating n threads:
            for (int i = 0; i < n; i++)
            {
                threads[i] = thread(atmMenu, i + 1);
            }

            for (auto &th : threads)
            {
                th.join();
            }
            break;
        case '2':
            // cout << "Inside main menu case2";
            empMenu();
            break;
        case '3':
            cout << "\nThank you for visiting the bank!" << endl;
            break;

        default:
            cout << "Invalid number! Please enter a valid choice" << endl;
        }
        if (choice == '3')
        {
            break;
        }
        cout << "\nDo you want to continue with main menu? ::Y\n";
        cout << "If you want to exit then please press::N ";
        x = getch();
        if (x == 'n' || x == 'N')
            cout << "Exiting...";

    } while (x == 'y' || x == 'Y');
}
