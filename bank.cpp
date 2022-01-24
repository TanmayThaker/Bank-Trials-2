//! Including necessary libraries and header files
#include <bits/stdc++.h>
#include <mutex>
#include <thread>
using namespace std;
#include "bank.h"
//#include "logger.h"
#include "helper.h"

//! Bank class default constructor
Bank ::Bank()
{
    balance = 0;
}
/*!
    \return the username which is pointer to character aray username
*/
char *Bank ::getUsernames()
{
    // Return username
    // Logger::Info("Username function is called");
    return username;
}
/*!
    \return account type which is pointer to character aray accountType
*/
char *Bank ::getAccountType()
{
    // Logger::Info("Returning account type of user");
    return accountType;
}
//! Function to get password of customer
/*!
    \return password of integer type
*/
int Bank ::getPassword()
{
    // Return the password
    // Logger::Info("Returning password of user");
    return password;
}

//! Function to set the data
void Bank ::setData()
{
    // Logger::Info("Set data function called");
    cin.ignore();
    cout << "\nEnter username:";
    cin.getline(username, 30);
    cout << "\nEnter 4-digit password: ";
    cin >> password;
    while (countDigits(password) > 4 || countDigits(password) < 4)
    {
        // Logger::Error("Invalid password entered");
        cout << "ERROR: Invalid Pin: " << endl;
        cout << "Enter your 4 digit pin please: ";
        cin >> password;
    }
    cin.ignore();
    cout << "\nEnter initial balance: " << endl;
    cin >> balance;
    while (balance < 0 || balance == 0)
    {
        // Logger::Error("Invalid balance is entered");
        cout << "\n Please enter a valid number\nEnter initial balance: " << endl;
        cin >> balance;
    }
    cin.ignore();
    cout << "\nEnter 4 digit account number: " << endl;
    cin >> accountNumber;
    while (countDigits(accountNumber) < 4 ||
           countDigits(accountNumber) > 4)
    {
        // Logger::Error("Invalid account number is entered");
        cout << "Invalid account number. please enter a valid account number" << endl;
        cout << "\nEnter 4 digit account number: " << endl;
        cin >> accountNumber;
    }
    cout << "\nEnter account type " << endl;
    cin >> accountType;
    cin.ignore();
}

//! Function displaying the data
void Bank ::showData()
{
    // Logger::Info("Show data function called");
    cout << "Username: " << username << endl;
    cout << "Password: " << password << endl;
    cout << "Balance: " << balance << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Account type: " << accountType << endl;
}

//! Function to add user
/*!
    \return integer type
*/
int Bank ::addUser()
{
    // Logger::Info("addUser function is called");
    Bank bank;
    ofstream file;

    // Open file in write mode
    file.open("data.txt", ios::out | ios::app);
    if (!file)
    {
        cout << "Error in creating file..." << endl;
        return 0;
    }

    // Read from user
    bank.setData();

    // Write into file
    file.write((char *)&bank, sizeof(bank)); // typecasting &bank into character pointer

    // Close the file
    file.close();

    return 0;
}

//!  Function to View all Users
/*!
    \return integer type
*/
int Bank ::ViewAllUsers()
{
    // Logger::Info("View all users function called");
    Bank bank;

    ifstream file1;

    // Open file in read mode
    file1.open("data.txt", ios::in);
    if (!file1)
    {
        cout << "Error in opening file..";
        return 0;
    }

    // Read data from file
    file1.read((char *)&bank, sizeof(bank));
    while (!file1.eof())
    {

        // Display data on console
        bank.showData();
        file1.read((char *)&bank, sizeof(bank));
    }

    // Close the file
    file1.close();
    return 0;
}

//! Function to delete the user
/*!
    \param uname character array
*/
void Bank ::deleteUser(char uname[])
{
    // Logger::Info("Delete user function called", uname);
    Bank bank;
    fstream original, temp;
    original.open("data.txt", ios::in);
    if (!original) // If file notfound then return
    {
        cout << "\nfile not found";
        return;
    }
    else
    {
        temp.open("temp.txt", ios::out | ios::app);
        original.read((char *)&bank, sizeof(bank));

        // Till end of file is reached
        while (!original.eof())
        {

            if (!strcmp(bank.getUsernames(), uname)) // compare the username
            {
                cout << "Hello" << endl;
                cout << "data found and deleted\n"
                     << bank.username << "\n";
            }
            else
            {

                temp.write((char *)&bank, sizeof(bank));
            }

            original.read((char *)&bank, sizeof(bank));
        }
        original.close();               // I will close my original file i.e. data.txt file
        temp.close();                   // I will close my temp file i.e. temp.txt file
        remove("data.txt");             // I will remove the main data.txt file
        rename("temp.txt", "data.txt"); // I will rename my temp.txt file with data.txt file
        cout << "\nRemaining Users: " << endl;
        bank.ViewAllUsers();
    }
    return;
}

//! Function to deposit money
/*!
    \param uname character array
*/
void Bank ::depositMoney(char uname[])
{
    // Logger::Info("Deposit Money function called");
    Bank bank;
    fstream file, temp;
    file.open("data.txt", ios::in | ios::out | ios::ate);
    temp.open("temp.txt", ios::out | ios::app);
    file.seekg(0); // pointing to the beginning of the file
    file.read((char *)&bank, sizeof(bank));

    // Till end of the file
    while (!file.eof())
    {
        if (!strcmp(bank.getUsernames(), uname))
        {
            int depositAmount;
            cout << "\nEnter amount to deposit:";
            cin >> depositAmount;
            try
            {
                if (depositAmount > 0)
                {
                    bank.balance = bank.balance + depositAmount;
                    cout << "\nBalance is: " << bank.balance;
                    temp.write((char *)&bank, sizeof(bank));
                }
                while (depositAmount < 0)
                {
                    // Logger::Critical("Negative amount is entered");
                    throw depositAmount;
                }
            }
            catch (int amt)
            {
                // Logger::Error("Exception occured while depositing money");
                cout << "Negative amount not allowed" << endl;
                continue;
            }
        }
        else
        {
            temp.write((char *)&bank, sizeof(bank));
        }
        file.read((char *)&bank, sizeof(bank));
    }
    file.close();
    temp.close();
    remove("data.txt");
    rename("temp.txt", "data.txt");
}

//! Function to withdraw money
/*!
    \param uname character array
*/
void Bank ::withdrawMoney(char uname[])
{
    // Logger::Info("Withdraw Money function called");
    Bank bank;
    fstream file, temp;
    file.open("data.txt", ios::in | ios::out | ios::ate);
    temp.open("temp.txt", ios::out | ios::app);
    file.seekg(0);
    file.read((char *)&bank, sizeof(bank));

    // Till end of file is reached
    while (!file.eof())
    {
        if (!strcmp(bank.getUsernames(), uname))
        {
            int withdrawMoney;
            cout << "\nEnter amount to withdraw:";
            cin >> withdrawMoney;

            try
            {
                /*
                if (bank.balance > withdrawMoney && withdrawMoney > 0)
                {
                }*/
                while (bank.balance < withdrawMoney || withdrawMoney <= 0)
                {
                    // Logger::Critical("Invalid amount is entered");
                    throw withdrawMoney;
                }
                bank.balance = bank.balance - withdrawMoney;
                temp.write((char *)&bank, sizeof(bank));
                cout << "\nBalance is: " << bank.balance;
            }
            catch (int withdrawMoney)
            {
                // Logger::Error("Exception Occured while withdrawing money");
                cout << "Please Enter the valid amount" << endl;
                continue;
            }
        }
        else
        {
            temp.write((char *)&bank,
                       sizeof(bank));
        }
        file.read((char *)&bank, sizeof(bank));
    }

    // Close the file
    file.close();
    temp.close();
    remove("data.txt");
    rename("temp.txt", "data.txt");
}

//!  Search user from binary file
/*!
    \param uname character array
    \param pass integer type
    \return integer type
*/
int Bank ::searchUser(char uname[], int pass)
{
    // Logger::Info("Search User function called");
    Bank bank;
    fstream f;

    // Open the file
    f.open("data.txt", ios::in);
    if (!f)
    {
        cout << "Error in opening file...";
        return 0;
    }

    // Read data from file
    f.read((char *)&bank, sizeof(bank));
    while (!f.eof())
    {

        if (!strcmp(bank.getUsernames(), uname))
        {
            if (bank.getPassword() == pass)
            {
                return 1;
            }
        }
        f.read((char *)&bank, sizeof(bank));
    }

    // Close the file
    f.close();
    return 0;
}

// ! Function to search specific user
/*!
    \return integer type
*/
int Bank ::searchUserByUsername(
    char uname[])
{
    // Logger::Info("Search user by username function called");
    Bank bank;
    fstream file1;

    // Open the file
    file1.open("data.txt", ios::in);
    if (!file1)
    {
        cout << "Error in opening file..";
        return 0;
    }

    // Read data from file
    file1.read((char *)&bank, sizeof(bank));
    while (!file1.eof())
    {
        if (!strcmp(bank.getUsernames(), uname))
        {
            bank.showData();
            return 0;
        }
        file1.read((char *)&bank, sizeof(bank));
    }

    // Close the file
    file1.close();
    return 0;
}