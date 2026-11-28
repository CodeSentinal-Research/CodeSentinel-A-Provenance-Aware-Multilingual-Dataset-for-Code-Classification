#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool checkPalindrome(string s, int start, int end) {
    for (int i = 0, j = end; i < j; ++i, --j) {
        if (s[i] != s[j]) {
            return false;
        }
    }
    return true;
}

int main() {
    string s;
    cin >> s;
    int len = s.length();
    for (int i = 0; i < len / 2; ++i) {
        if (s[i] != s[len - i - 1]) {
            if (checkPalindrome(s, i + 1, len - i - 2) ||
                checkPalindrome(s, i, len - i - 2)) {
                cout << "Yes";
                return 0;
            }
        }
    }
    cout << "No";
    return 0;
}