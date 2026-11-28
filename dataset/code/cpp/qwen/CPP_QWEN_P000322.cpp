#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int upper = 0, lower = 0;
    for (char c : s) {
        if (isupper(c)) upper++;
        else lower++;
    }
    bool ok = (upper == s.size()) || (lower == s.size()) || (upper == 1 && isupper(s[0]));
    cout << (ok ? "Yes" : "No") << endl;
    return 0;
}
