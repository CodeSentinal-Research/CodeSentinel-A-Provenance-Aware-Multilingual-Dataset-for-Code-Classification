Here is the C++ code that solves the problem:

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool isMatch(string s, string p) {
    if (p.empty()) return s.empty();

    if (p.size() > 1 && p[0] == '*' && p[1] == s[0]) {
        return isMatch(s.substr(1), p) || (s.size() > 1 && isMatch(s.substr(2), p));
    }

    if (!s.empty() && (p[0] == s[0] || p[0] == '?' || p[0] == '*')) {
        return isMatch(s.substr(1), p.substr(1));
    }

    return false;
}

int main() {
    int n;
    cin >> n;
    cin.ignore();
    while (n--) {
        string s;
        getline(cin, s);
        string p;
        getline(cin, p);
        cout << (isMatch(s, p) ? "YES" : "NO") << endl;
    }
    return 0;
}

This code uses a recursive approach to solve the problem. The main idea is to use the recursive definition of a match: if the pattern and the string are empty, the match is true. If the pattern and the string are not empty, we check if the first characters match. If they match, we remove the characters from both strings. If the first character of the pattern is '*', we can ignore one character in the pattern and match the rest of the string. If the first character of the pattern is a '?', we can ignore the current character in the string and match the rest of the pattern. If none of these conditions are met, the match is false.