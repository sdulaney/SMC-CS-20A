#include<iostream>
//using std::cout;
//using std::endl;


struct AccountInfo {
    
    float balance;
    int password;
    
};
//Spec: Function adds some amount to my balance
//If the password is correct. Ensure nonnegative amount.
//Return true if successful, false otherwise.

bool addBalance(AccountInfo &acc_info, float amount, int input_password) {
    
    if ((input_password == acc_info.password) && (amount >=0 )) {
        
        acc_info.balance += amount;
        return true;
    }
    
    return false;
    
}



int main() {
    
    // Declare and initialize variables
    // MY actual account info
    
    AccountInfo acc_info;
    acc_info.balance = 100;
    acc_info.password = 1234;
    
    
    float amount;
    int input_password;
    
    std::cout << "Gimme da amount yo" << std::endl;
    std::cin >> amount; // 50;
    
    std::cout << "Password?" << std::endl;
    std::cin >> input_password;
    
    addBalance(acc_info, amount, input_password);
    
    std::cout << acc_info.balance << std::endl;
    
    
    return 0;
}
