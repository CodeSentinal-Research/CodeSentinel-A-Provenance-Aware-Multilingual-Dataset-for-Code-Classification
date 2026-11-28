#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> passports(n), details(n);
    for (int i = 0; i < n; i++) cin >> passports[i] >> details[i];
    int q;
    cin >> q;
    while (q--) {
        string passport;
        cin >> passport;
        bool found = false;
        for (int i = 0; i < n; i++) {
            if (passports[i] == passport) { cout << passports[i] << " " << details[i] << endl; found = true; break; }
        }
        if (!found) cout << "Passport Not Found" << endl;
    }
    return 0;
}
