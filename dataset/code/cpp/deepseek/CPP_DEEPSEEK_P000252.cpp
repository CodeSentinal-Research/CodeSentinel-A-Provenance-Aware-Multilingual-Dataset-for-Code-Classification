#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool isPalindrome(string s) {
    string original = s;
    reverse(s.begin(), s.end());
    return s == original;
}

int main() {
    string s;
    cin >> s;
    if (isPalindrome(s)) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}