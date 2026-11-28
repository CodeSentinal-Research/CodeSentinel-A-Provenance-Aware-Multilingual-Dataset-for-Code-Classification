#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPalindrome(string s) {
    int n = s.length();
    for(int i=0; i<n/2; i++)
        if (s[i] != s[n-i-1])
            return false;
    return true;
}

bool isPossibleToMakePalindrome(string s) {
    int n = s.length();
    if (n == 1)
        return true;
    if (isPalindrome(s))
        return true;
    for (int i = 0; i < n - 1; i++) {
        string temp = s.substr(0, i) + s.substr(i + 1, n - i - 1);
        if (isPalindrome(temp))
            return true;
    }
    return false;
}

int main() {
    string s;
    cin >> s;
    if (isPossibleToMakePalindrome(s))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
This C++ code first defines a helper function `isPalindrome` to check if a string is a palindrome. Then it defines a function `isPossibleToMakePalindrome` to check if a string can become a palindrome after removing at most one character. The `main` function reads the input string, and prints "YES" if possible, otherwise "NO".