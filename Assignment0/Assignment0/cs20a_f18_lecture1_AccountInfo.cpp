// Stewart Dulaney
// 9/5/2018
// CS 20A Section 4110
// SID: 1545566
// Assignment 0
#include<iostream>
#include<cassert>
//using std::cout;
//using std::endl;

// Demonstrates that structs can be used the same way as classes, the only
// difference being that the default access specifier is public.
struct AccountInfo {
    void initAccount(float balance, int password);
    // Precondition: The initial balance must not be negative, if it is negative,
    // set it to $0.00 by default.
    // Postcondition: Initializes the member variables balance and password to
    // the given arguments.
    float checkBalance(int input_password);
    // Returns the balance if the password is correct, or -1 otherwise.
    bool addBalance(float amount, int input_password);
    // Precondition: The argument amount is nonnegative and the input_password matches
    // the current password.
    // Postcondition: Adds amount to balance and returns true if preconditions are met,
    // returns false otherwise.
    bool remBalance(float amount, int input_password);
    // Precondition: The argument amount does not exceed the current balance and is
    // nonnegative. The input_password matches the current password.
    // Postcondition: Removes funds from balance and returns true if preconditions
    // are met, returns false otherwise.
    bool changePassword(int current_password, int new_password);
    // Precondition: The argument current_password matches the current password.
    // Postcondition: Returns true and the current password is updated to new_password
    // if preconditions are met, returns false otherwise.
private:
    float balance;
    int password;
    
};

void AccountInfo::initAccount(float balance, int password) {
    this->password = password;
    if (balance < 0) {
        this->balance = 0.0;
    } else {
        this->balance = balance;
    }
}

float AccountInfo::checkBalance(int input_password) {
    if (this->password == input_password) {
        return this->balance;
    }
    return -1;
}


bool AccountInfo::addBalance(float amount, int input_password) {
    if ((input_password == this->password) && (amount >=0 )) {
        this->balance += amount;
        return true;
    }
    return false;
}

bool AccountInfo::remBalance(float amount, int input_password) {
    if ((input_password == this->password) && (amount >=0 ) && (amount <= this->balance)) {
        this->balance -= amount;
        return true;
    }
    return false;
}

bool AccountInfo::changePassword(int current_password, int new_password) {
    if (current_password == this->password) {
        this->password = new_password;
        return true;
    }
    return false;
}

int main() {
    
    // Declare my account info object
    AccountInfo acc_info;
    
    // Initialize the accounts information
    acc_info.initAccount(100, 1234);
    assert(acc_info.checkBalance(1234) == 100.0);           // balance initialized correctly
    assert(acc_info.checkBalance(1234) != -1);              // password initialized correctly

    // Deposit some funds
    acc_info.addBalance(50.0, 1234);
    assert(acc_info.checkBalance(1234) == 150.0);           // balance updated correctly
    
    // Check the balance
    std::cout << acc_info.checkBalance(1234) << std::endl;  // should show 150
    
    // Withdraw some funds
    acc_info.remBalance(20.5, 1234);
    assert(acc_info.checkBalance(1234) == 129.5);           // balance updated correctly
    
    // Check the balance
    std::cout << acc_info.checkBalance(1234) << std::endl;  // should show 129.5
    
    // Change the password
    acc_info.changePassword(1234, 4321);
    assert(acc_info.checkBalance(4321) == 129.5);           // password updated correctly

    // Check the balance
    std::cout << acc_info.checkBalance(1234) << std::endl;  // should show -1
    
    return 0;
}
