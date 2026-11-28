Here is the C++ code for the wildcard pattern matching problem:

#include <iostream>
using namespace std;

bool isMatch(string s, string p) {
    if(p.empty()) return s.empty();

    bool firstMatch = (!s.empty() && (s[0] == p[0] || p[0] == '?'));

    if(p.size() > 1 && p[1] == '*') {
        return isMatch(s, p.substr(2)) || firstMatch && isMatch(s.substr(1), p);
    }

    return firstMatch && isMatch(s.substr(1), p.substr(1));
}

int main() {
    string s, p;
    cout << "Enter string s: ";
    cin >> s;
    cout << "Enter pattern p: ";
    cin >> p;
    if(isMatch(s, p)) {
        cout << "True\n";
    } else {
        cout << "False\n";
    }
    return 0;
}

In this code, the function `isMatch(string s, string p)` is defined. This function recursively checks if the first character of the pattern matches the first character of the string. If the pattern character is '*', it checks the next character in the pattern and if it matches, it can either match the rest of the pattern or the next character in the string. If the pattern character is '?', it matches only one character from the string.