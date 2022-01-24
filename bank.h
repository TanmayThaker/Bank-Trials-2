//! Including header guard
#ifndef BANK
#define BANK

//! Bank class
class Bank
{
private:
    //! Username of customer
    char username[30];
    //! password for customer login
    int password;
    //! balance
    int balance;
    //! account number of the customer
    int accountNumber;
    //! account type of customer
    char accountType[30];

public:
    //! Member Functions
    //! Bank class default constructor
    Bank();
    //! Function to get Username of customer
    char *getUsernames();
    //! Function to get account type of customer
    char *getAccountType();
    //! Function to get password of the customer/user
    int getPassword();
    //! Function to set data
    void setData();
    //! Function to add customer/user
    int addUser();
    //! Function to show data of the cutomer/user
    void showData();
    //! Function to view all the customers/users
    int ViewAllUsers();
    //! Function to delete customer/user
    void deleteUser(char[]);
    //! Function to deposit money to the account
    void depositMoney(char[]);
    //! Function to get withdraw money from account
    void withdrawMoney(char[]);
    //! Function to search User
    int searchUser(char[], int);
    //! Function to search uer by its username
    int searchUserByUsername(char[]);
};
#endif