#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> names(n), phones(n);
    for (int i = 0; i < n; i++) cin >> names[i] >> phones[i];
    string prefix;
    cin >> prefix;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (names[i].substr(0, prefix.size()) == prefix) { cout << names[i] << " " << phones[i] << endl; found = true; }
    }
    if (!found) cout << "No Contacts Found" << endl;
    return 0;
}
