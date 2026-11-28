Sure, here's a simple Python code snippet to implement your requirements:

class Account:
    def __init__(self, account_number, account_holder_name, account_balance):
        self.account_number = account_number
        self.account_holder_name = account_holder_name
        self.account_balance = account_balance

accounts = {}

def add_account(account_number, account_holder_name, account_balance):
    account = Account(account_number, account_holder_name, account_balance)
    accounts[account_number] = account

def search_account(account_number):
    if account_number in accounts:
        account = accounts[account_number]
        return f'Account number: {account.account_number}, Account Holder: {account.account_holder_name}, Account Balance: {account.account_balance}'
    else:
        return 'Account Not Found'

def main():
    add_account(123, 'John Doe', 1000)
    add_account(456, 'Jane Smith', 2000)

    print(search_account(123))  
    print(search_account(789))  

if __name__ == "__main__":
    main()
In this code, we create a class `Account` to represent a bank account. We then create a dictionary `accounts` to store all the accounts. We have two functions: `add_account` and `search_account`.

In the `add_account` function, we create a new account and add it to the `accounts` dictionary.

In the `search_account` function, we check if the account number is in the `accounts` dictionary. If it is, we get the account details and return it. If it's not, we return 'Account Not Found'.

In the `main` function, we add two accounts to the `accounts` dictionary and then search for these accounts.