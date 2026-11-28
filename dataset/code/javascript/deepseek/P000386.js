Sure, here is a simple implementation of the problem using JavaScript:

class BankAccount {
  constructor(accountNumber, accountHolder, balance) {
    this.accountNumber = accountNumber;
    this.accountHolder = accountHolder;
    this.balance = balance;
  }
}

let bankAccounts = [];

// Add account
function addAccount(accountNumber, accountHolder, balance) {
  bankAccounts.push(new BankAccount(accountNumber, accountHolder, balance));
}

// Find account
function findAccount(accountNumber) {
  for (let i = 0; i < bankAccounts.length; i++) {
    if (bankAccounts[i].accountNumber === accountNumber) {
      return bankAccounts[i];
    }
  }
  return "Account Not Found";
}

// Testing the code
addAccount(123, "John Doe", 5000);
addAccount(456, "Jane Doe", 7000);

console.log(findAccount(123)); // John Doe
console.log(findAccount(789)); // Account Not Found

This code defines a BankAccount class with attributes accountNumber, accountHolder, and balance. It then creates an array of BankAccount objects and provides methods to add and find accounts. The addAccount function adds a new BankAccount to the array and the findAccount function finds a BankAccount by accountNumber and returns the details.