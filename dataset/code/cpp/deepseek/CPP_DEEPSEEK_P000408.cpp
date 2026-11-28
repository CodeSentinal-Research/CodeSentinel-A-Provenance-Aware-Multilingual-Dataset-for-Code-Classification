#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> emails;
    for (int i = 0; i < n; i++) {
        string email;
        cin >> email;
        emails.push_back(email);
    }

    string domain;
    cin >> domain;

    for (const string& email : emails) {
        if (email.find(domain) != string::npos) {
            cout << email << endl;
        }
    }

    return 0;
}