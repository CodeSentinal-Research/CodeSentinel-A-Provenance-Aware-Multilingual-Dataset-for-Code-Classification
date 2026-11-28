#include <iostream>
#include <string>
using namespace std;

bool canBeSplit(string s) {
    for (int i = 1; i < s.length(); i++) {
        if (s[i] == s[i-1] - 1 && s[i] == s[i-1] - 2) {
            return true;
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    if (canBeSplit(s)) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}