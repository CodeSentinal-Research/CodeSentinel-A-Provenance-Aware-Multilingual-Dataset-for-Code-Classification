Here is the code:

#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
    if (s.empty() || s.size() == 1) {
        return true;
    }

    if (s[0] == s[s.size() - 1]) {
        return isPalindrome(s.substr(1, s.size() - 2));
    }

    return false;
}

int main() {
    string s;
    cin >> s;

    if (isPalindrome(s)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}

This program takes a string as input and checks if it is a palindrome using recursion. The base case is when the string is empty or has only one character, in which case it is a palindrome. For the recursive case, it compares the first and last characters of the string and recursively checks the rest of the string. If all characters match, the string is a palindrome, otherwise it's not.