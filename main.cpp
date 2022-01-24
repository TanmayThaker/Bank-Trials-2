//! Including necessary libraries and header files
#include <bits/stdc++.h>
#include <mutex>
#include <thread>
using namespace std;
#include "bank.h"
#include "employee.h"
#include "manager.h"
#include "cashier.h"
#include "menu.h"
#include "logger.h"

// extern void setPriority(LogPriority);
// template <typename... Args>
// extern void Info(const char *message, Args... args);
//! main function
int main()
{
    Logger::Info("Welcome to Main Function");
    mainMenu();
    return 0;
}
