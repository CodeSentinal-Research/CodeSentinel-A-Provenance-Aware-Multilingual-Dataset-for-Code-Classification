#include <iostream>
#include <unordered_map>

struct BankAccount {
    int accountNumber;
    string accountHolderName;
    double balance;
};

unordered_map<int, BankAccount> accountRecords;

void addAccount(int accountNumber, string accountHolderName, double balance) {
    BankAccount newAccount;
    newAccount.accountNumber = accountNumber;
    newAccount.accountHolderName = accountHolderName;
    newAccount.balance = balance;
    accountRecords[accountNumber] = newAccount;
}

void findAccount(int accountNumber) {
    if (accountRecords.find(accountNumber) != accountRecords.end()) {
        BankAccount account = accountRecords[accountNumber];
        cout << "Account Number: " << account.accountNumber << endl;
        cout << "Account Holder Name: " << account.accountHolderName << endl;
        cout << "Balance: " << account.balance << endl;
    } else {
        cout << "Account Not Found" << endl;
    }
}

int main() {
    addAccount(123, "John Doe", 5000.0);
    addAccount(456, "Jane Doe", 7000.0);
    findAccount(123);
    findAccount(789);
    findAccount(456);
    findAccount(789);
    return 0;
}