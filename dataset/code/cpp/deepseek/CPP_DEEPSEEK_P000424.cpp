Sure, here is the C++ code that satisfies all the requirements:

#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_set<string> set;
    vector<string> duplicates;

    for(int i = 0; i < n; i++) {
        string email;
        cin >> email;

        if(set.find(email) != set.end()) {
            duplicates.push_back(email);
        } else {
            set.insert(email);
        }
    }

    for(const auto &email : duplicates) {
        cout << email << endl;
    }

    return 0;
}

This program reads in a list of email addresses. It then uses an unordered set to keep track of the unique email addresses it has encountered. If it encounters an email that is already in the set, it adds it to the list of duplicates. Finally, it outputs all of the duplicates.