#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

struct Account {
    string name;
    vector<string> emails;
};

bool compare(Account a, Account b) {
    return a.name < b.name;
}

int main() {
    int n;
    cin >> n;
    vector<Account> accounts(n);
    for (int i = 0; i < n; i++) {
        cin >> accounts[i].name;
        string email;
        while (cin >> email) {
            if (email != "quit") {
                accounts[i].emails.push_back(email);
            } else {
                break;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        sort(accounts[i].emails.begin(), accounts[i].emails.end());
        for (int j = 0; j < accounts[i].emails.size(); j++) {
            cout << accounts[i].name << " " << accounts[i].emails[j] << endl;
        }
    }
    return 0;
}