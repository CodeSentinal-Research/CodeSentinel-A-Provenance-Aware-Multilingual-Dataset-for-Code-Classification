Here is the C++ code that will solve the problem:

#include <iostream>
#include <string>

using namespace std;

bool isRepeatedSubstring(string s) {
    int n = s.size();
    for (int len = 1; len * 2 <= n; ++len) {
        if (n % len == 0) {
            string sub = s.substr(0, len);
            if (s.substr(len, n - len) == sub) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    if (isRepeatedSubstring(s)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}

This program works by checking all possible lengths of substrings (from 1 to half of the size of the string) and checking if they appear in the string. If they do, it means the string can be constructed by repeating a substring.