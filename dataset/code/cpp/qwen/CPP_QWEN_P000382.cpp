#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> users(n), emails(n);
    for (int i = 0; i < n; i++) cin >> users[i] >> emails[i];
    int q;
    cin >> q;
    while (q--) {
        string user;
        cin >> user;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (users[i] == user) { cout << emails[i] << endl; found = true; break; }
        }
        if (!found) cout << "User Not Found" << endl;
    }
    return 0;
}
