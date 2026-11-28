#include <iostream>
#include <vector>
#include <map>

struct Account {
    int accountId;
    int inactivityPeriod;
};

int main() {
    std::map<int, int> accountMap; 
    std::vector<Account> inactiveAccounts;
    int numAccounts, inactivityPeriod;

    std::cin >> numAccounts >> inactivityPeriod;

    for (int i = 0; i < numAccounts; ++i) {
        Account account;
        std::cin >> account.accountId >> account.inactivityPeriod;
        accountMap[account.accountId] = account.inactivityPeriod;
    }

    for (auto const& pair: accountMap) {
        int accountId = pair.first;
        int inactivityPeriod = pair.second;

        if (inactiveAccounts.size() == 0 || inactiveAccounts.back().accountId != accountId || inactiveAccounts.back().inactivityPeriod + inactivityPeriod > inactivityPeriod) {
            inactiveAccounts.push_back(Account{accountId, inactivityPeriod});
        }
    }

    for (const Account& account : inactiveAccounts) {
        std::cout << account.accountId << std::endl;
    }

    return 0;
}
This code will retrieve the list of inactive accounts by examining the account inactivity periods. It reads the number of accounts and inactivity period from the standard input, then reads in each account's ID and inactivity period. If the account's inactivity period is greater than the specified inactivity period, it is considered inactive and added to the list of inactive accounts. Finally, it prints out the IDs of the inactive accounts.