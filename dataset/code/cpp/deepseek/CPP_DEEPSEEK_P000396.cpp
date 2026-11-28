#include <iostream>
#include <vector>

int main() {
    std::vector<std::pair<std::string, bool>> userAccounts = {
        {"User1", true},
        {"User2", false},
        {"User3", true},
        {"User4", false},
        {"User5", true}
    };

    for (const auto& user : userAccounts) {
        if (user.second) {
            std::cout << user.first << std::endl;
        }
    }

    return 0;
}
This code reads a list of user accounts, and then iterates over the list. If a user account is marked as active, it prints the name of that user account.